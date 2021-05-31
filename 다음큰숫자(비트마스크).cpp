#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

int Count(int n)
{
    int ct = 0;
    for (int i = 0; i < 21; i++)
    {
        if ((0b1 << i) & n)
            ct++;
    }
    return ct;
}
int solution(int n) {
    int answer = 0;
    int ct = Count(n);

    int i = 0;
    while (1)
    {
        i++;
        if (ct == Count(n + i))
        {
            answer = n + i;
            break;
        }
    }
    return answer;
}