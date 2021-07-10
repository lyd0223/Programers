#include <vector>
#include <iostream>
#include <algorithm>
#include "math.h"
using namespace std;

bool sosulist[3000];
void Eratosthenes()
{
    for (int i = 2; i < sqrt(3000); i++)
    {
        for (int j = i * i; j < 3000; j += i)
        {
            sosulist[j] = 1;
        }
    }
}
int solution(vector<int> nums) {
    int answer = 0;

    //permutation을 사용하기위한 밑작업.

    vector<int> temp(nums.size(), false);
    for (int i = 0; i < 3; i++)
        temp[i] = true;
    vector<long long> numlist;
    //permutation을이용, 숫자를 만든다.
    do {
        int num = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (temp[i])
                num += nums[i];
        }
        numlist.push_back(num);
    } while (prev_permutation(temp.begin(), temp.end()));

    Eratosthenes();

    for (auto a : numlist)
    {
        if (!sosulist[a])
        {
            answer++;
            cout << a << " ";
        }
    }

    return answer;
}