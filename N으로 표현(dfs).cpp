#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//������ȹ���̳�, ������ȹ������ Ǫ�¹��� �𸣰ڴ�.
//�ּڰ��� 9�̻��� �����ʴ´�. �׷����ϴ� dfs�� Ǯ����.

int answer = 9; // �ϴ� �񱳸� ���� 9�� �־�д�. (�ּڰ��� �ִ�)
void dfs(int N, int number, int currentnum, int ct)
{
    if (ct > 8) // �ּڰ��� 8���� ũ�� ����
        return;
    if (currentnum == number) //number�� ã������ ct�� answer��.
    {
        answer = min(ct, answer);
        return;
    }
    // N, NN, NNN, .... NNNNNNNNN���� ��� dfs�� ����.
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