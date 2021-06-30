#include <string>
#include <vector>
#include "math.h"
using namespace std;

bool isPrimeNumArr[10000001];
void Eratosthenes(int n)
{
    for (int i = 2; i < sqrt(n); i++)
    {
        for (int j = i * i; j < n; j += i)
        {
            isPrimeNumArr[j] = 1;
        }
    }
}
int solution(int n) {
    int answer = 0;
    Eratosthenes(n + 1);

    for (int i = 2; i <= n; i++)
    {
        if (isPrimeNumArr[i] == 0)
            answer++;
    }
    return answer;
}