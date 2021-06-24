#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> v;

    int n = 1;
    int size = stages.size();
    while (n <= N)
    {
        int ct = 0;
        for (int i = 0; i < stages.size(); i++)
        {
            if (stages[i] == n)
                ct++;

        }
        if (size > 0)
        {
            v.push_back(make_pair(n, (float)ct / (float)size));
        }
        else
            v.push_back(make_pair(n, 0));
        n++;
        size -= ct;
    }

    sort(v.begin(), v.end(), [](pair<int, float> a, pair<int, float> b)
        {
            if (a.second != b.second)
                return a.second > b.second;
            else
                return a.first < b.first;
        });
    for (int i = 0; i < v.size(); i++)
    {
        answer.push_back(v[i].first);
    }

    return answer;
}