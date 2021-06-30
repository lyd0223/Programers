#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//간단문제...
//하나씩 비교해가면서 큰거면 올림
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int j = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if (j > A.size())
            break;
        if (A[j] < B[i])
        {
            j++;
            answer++;
        }
    }
    return answer;
}