#include <string>
#include <vector>

using namespace std;

//GCD : 최대공약수 , 유클리드 호제법을이용해 찾자.
//유클리드 호제법 : 큰수에 작은 수를 나눈 나머지로 계속 나눈다.
int FindGCD(int bignum, int smallnum)
{
    int temp;
    while (smallnum != 0)
    {
        temp = bignum % smallnum;
        bignum = smallnum;
        smallnum = temp;
    }
    return bignum;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    if (n > m)
        answer.push_back(FindGCD(n, m));
    else
        answer.push_back(FindGCD(m, n));

    //LCM : 최소공배수
    //두 수의 곱(num)과 최대공약수로 찾는다.
    answer.push_back((m * n) / answer[0]);
    return answer;
}