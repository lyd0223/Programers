#include <string>
#include <vector>
#include "math.h"
using namespace std;
//효율성이 조금 빡세다.
//처음에 솔루션함수안에서 다 해결하려했으나 효율성문제로 따로 check함수를 만들어줬다.
//규칙은 n번째블록은 n을 제외한 약수중 제일 큰 수를 찾는것.
int check(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0 && n / i <= 10000000)
        {
            return n / i;
        }
    }
    return 1;
}
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (int i = begin; i <= end; i++)
    {
        answer.push_back(check(i));
    }
    if (begin == 1)
        answer[0] = 0;

    return answer;
}