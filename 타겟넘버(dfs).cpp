#include <string>
#include <vector>
#include <iostream>

using namespace std;
int t;
int ans;
int visit[21];
void dfs(vector<int> numbers, int num, int ct, bool isplus);
int solution(vector<int> numbers, int target) {
    int answer = 0;
    t = target;
    dfs(numbers, 0, 0, 0);
    dfs(numbers, 0, 0, 1);
    answer = ans / 2;
    return answer;
}

void dfs(vector<int> numbers, int num, int ct, bool isplus)
{

    if (ct >= numbers.size())
    {
        if (t == num)
        {
            ans++;
        }
        return;
    }

    if (isplus)
    {
        num += numbers[ct];
    }
    else
    {
        num -= numbers[ct];
    }

    dfs(numbers, num, ct + 1, 1);
    dfs(numbers, num, ct + 1, 0);

}