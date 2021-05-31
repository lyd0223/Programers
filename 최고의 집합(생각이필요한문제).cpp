#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    //����ó��. ���� ������ ������ ���� �� ����.
    if (s < n)
    {
        answer.push_back(-1);
    }
    else
    {
        //�����غ� ���, ���� s�� n���� ���� ���� ū ���� ��������,
        //�� ������ ���̰� ���� ������Ѵ�.
        //����, ���� ������ ��� ���� ä���ֵ�, ���°����� ���� devide�� 1�� �����ش�. 
        int devide = s / n;
        int remain = s % n;

        //�ϴ� ���� ���� ä������ 
        //ex) n = 5, s = 22
        //    devide = 4, remain = 2
        //    answer = [ 5, 5, 5, 5 ] 
        //    ������ �������� ������ ���ϰ������Ƿ� �ڿ�������.
        //    remain�� 2�̹Ƿ� �ΰ� 1��������.
        //    answer = [ 5, 5, 6, 6 ]
        while (answer.size() != n)
        {
            answer.push_back(devide);
        }
        int ct = answer.size() - 1;
        while (remain != 0)
        {
            answer[ct] ++;
            ct--;
            remain--;
        }
    }
    return answer;
}