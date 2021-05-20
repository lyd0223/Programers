#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int minnum = min(a, b);
    int maxnum = max(a, b);
    for (int i = minnum; i <= maxnum; i++)
    {
        answer += i;
    }
    return answer;
}