#include <string>
#include <vector>
#include "math.h"
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 1;
    for (int i = 2; i < n; i++)
    {
        int piv = 0;
        for (int j = 1; j <= i; j++)
            piv += j;
        if ((n - piv) % i == 0 && n >= piv)
        {
            answer++;
            cout << i << " ";
        }
    }
    return answer;
}