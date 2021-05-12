#include <string>
#include <vector>
#include <iostream>
using namespace std;
int havelist[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for (int i = 0; i < reserve.size(); i++)
    {
        havelist[reserve[i]] += 1;
    }
    for (int i = 0; i < lost.size(); i++)
    {
        havelist[lost[i]] -= 1;
    }
    for (int i = 0; i < 31; i++)
    {
        cout << havelist[i];
    }
    for (int i = 1; i < 31; i++)
    {
        if (havelist[i] == 1)
        {
            if (havelist[i - 1] == -1)
            {
                havelist[i - 1] += 1;
                havelist[i] -= 1;
            }
            else if (havelist[i + 1] == -1)
            {
                havelist[i + 1] += 1;
                havelist[i] -= 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (havelist[i] == 1 || havelist[i] == 0)
            answer++;
    }
    return answer;
}