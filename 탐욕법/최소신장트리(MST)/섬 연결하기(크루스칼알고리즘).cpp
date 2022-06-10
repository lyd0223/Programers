#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind
{
public:
    static int GetParent(vector<int>& _ParentList, int _NodeNum)
    {
        if (_ParentList[_NodeNum] == _NodeNum)
            return _NodeNum;
        return GetParent(_ParentList, _ParentList[_NodeNum]);
    }

    //부모 합치기.
    static void Union(vector<int>& _ParentList, int a, int b)
    {
        a = GetParent(_ParentList, a);
        b = GetParent(_ParentList, b);
        if (a < b)
            _ParentList[b] = a;
        else
            _ParentList[a] = b;
    }

    //같은 부모인지 확인
    static bool Find(vector<int>& _ParentList, int a, int b)
    {
        a = GetParent(_ParentList, a);
        b = GetParent(_ParentList, b);
        if (a == b)
            return true;
        return false;
    }
};

//MST(최소신장트리) -크루스칼 알고리즘이용(Union Find)
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(),
        [](vector<int> a, vector<int> b) {
            return a[2] < b[2];
        });

    vector<int> ParentList(n);
    for (int i = 0; i < ParentList.size(); i++)
    {
        ParentList[i] = i;
    }

    for (int i = 0; i < costs.size(); i++)
    {
        if (UnionFind::Find(ParentList, costs[i][0], costs[i][1]) == false)
        {
            UnionFind::Union(ParentList, costs[i][0], costs[i][1]);
            answer += costs[i][2];
        }
    }

    return answer;
}