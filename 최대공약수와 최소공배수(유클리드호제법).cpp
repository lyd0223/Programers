#include <string>
#include <vector>

using namespace std;

//GCD : �ִ����� , ��Ŭ���� ȣ�������̿��� ã��.
//��Ŭ���� ȣ���� : ū���� ���� ���� ���� �������� ��� ������.
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

    //LCM : �ּҰ����
    //�� ���� ��(num)�� �ִ������� ã�´�.
    answer.push_back((m * n) / answer[0]);
    return answer;
}