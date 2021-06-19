#include <iostream>
#include <algorithm>
using namespace std;

//초간단 공식문제.

int solution(int n)
{
    int ans = 0;

    while (n != 0)
    {
        if (n % 2 == 1)
        {
            ans++;
            n--;
        }
        n /= 2;
    }

    return ans;
}