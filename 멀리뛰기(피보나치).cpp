#include <string>
#include <vector>
long long answer;
using namespace std;
//피보나치 수와 비슷하게 풀면 간단하게 풀린다.
//i번째 수는 i-1 + i-2이라는점을 코딩하면된다.
long long solution(int n) {
    long long answer = 0;
    vector<long long> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for (int i = 4; i <= n; i++)
    {
        v.push_back((v[i - 2] + v[i - 1]) % 1234567);
    }
    answer = v[n];
    return answer;
}