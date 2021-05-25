#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//동적계획법이나, 동적계획법으로 푸는법은 모르겠다.
//최솟값이 9이상은 되지않는다. 그래서일단 dfs로 풀엇다.

int answer = 9; // 일단 비교를 위해 9를 넣어둔다. (최솟값의 최댓값)
void dfs(int N, int number, int currentnum, int ct)
{
    if (ct > 8) // 최솟값이 8보다 크면 리턴
        return;
    if (currentnum == number) //number를 찾았을때 ct와 answer비교.
    {
        answer = min(ct, answer);
        return;
    }
    // N, NN, NNN, .... NNNNNNNNN까지 모두 dfs로 돌림.
    int temp = 0;
    for (int i = 0; i + ct < 9; i++)
    {
        temp = N + temp * 10;
        dfs(N, number, currentnum + temp, ct + 1 + i);
        dfs(N, number, currentnum - temp, ct + 1 + i);
        dfs(N, number, currentnum * temp, ct + 1 + i);
        dfs(N, number, currentnum / temp, ct + 1 + i);
    }
}
int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if (answer > 8)
        return -1;
    return answer;
}