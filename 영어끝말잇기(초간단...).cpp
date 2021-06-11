#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

//초간단문제...

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, bool> um;

    um[words[0]] = 1;
    for (int i = 1; i < words.size(); i++)
    {
        if (um[words[i]] == 1)
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        else
        {
            if (words[i - 1][words[i - 1].size() - 1] != words[i][0])
            {
                answer.push_back(i % n + 1);
                answer.push_back(i / n + 1);
                return answer;
            }
            else
                um[words[i]] = 1;
        }

    }
    if (answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}