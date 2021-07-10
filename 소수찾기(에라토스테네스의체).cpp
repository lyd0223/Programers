#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "math.h"
using namespace std;

vector<int> Eratosthenes(int num)
{
    vector<int> v(num, 0);
    vector<int> answer;
    for (int i = 2; i < sqrt(num); i++)
    {
        if (!v[i])
        {
            for (int j = i * i; j < num; j += i)
            {
                v[j] = 1;
            }
        }
    }
    for (int i = 2; i < num; i++)
    {
        if (v[i] == 0)
        {
            answer.push_back(i);
        }
    }
    return answer;
}
int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<int>());
    vector<int> sosoos;
    sosoos = Eratosthenes(stoi(numbers) + 1);


    for (int i = 0; i < sosoos.size(); i++)
    {
        string sosoo = to_string(sosoos[i]);
        string num = numbers;
        vector<bool> checks(sosoo.length(), 0);
        for (int j = 0; j < sosoo.length(); j++)
        {

            for (int k = 0; k < num.length(); k++)
            {
                if (sosoo[j] == num[k])
                {
                    num[k] = 'a';
                    checks[j] = 1;
                    break;
                }
            }
        }
        bool check2 = 0;
        for (int j = 0; j < checks.size(); j++)
        {
            if (!checks[j])
            {
                check2 = 1;
            }
        }

        if (!check2)
        {
            answer++;
        }
    }
    return answer;
}