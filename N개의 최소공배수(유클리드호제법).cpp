#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//유클리드 호제법을 이용해 최대공약수를구함.
//N개의 수의 최소공배수는 순차적으로 두개씩 최소공배수를 구하면됨.
int FindGCD(int a, int b)
{
    int bignum, smallnum;
    if (a > b)
    {
        bignum = a;
        smallnum = b;
    }
    else if (a < b)
    {
        bignum = b;
        smallnum = a;
    }
    else
        return a;

    int temp;
    while (smallnum != 0)
    {
        temp = bignum % smallnum;
        bignum = smallnum;
        smallnum = temp;
    }
    return bignum;
}
int FindLCM(int a, int b, int gcd)
{
    return a * b / gcd;
}
int solution(vector<int> arr) {
    int answer = 0;
    if (arr.size() == 1)
        return arr[0];
    if (arr.size() == 2)
        return FindLCM(arr[0], arr[1], FindGCD(arr[0], arr[1]));
    int lcm = FindLCM(arr[0], arr[1], FindGCD(arr[0], arr[1]));

    for (int i = 2; i < arr.size(); i++)
    {
        lcm = FindLCM(lcm, arr[i], FindGCD(lcm, arr[i]));
    }
    return lcm;
}