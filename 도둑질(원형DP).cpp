#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//dp����. ��ƼĿ������2�� �ƿ�����������.
// ���� dp����.
int solution(vector<int> money) {
    int answer = 0;

    vector<int> maxdp1 = money;

    maxdp1[0] = money[0];
    maxdp1[1] = money[0];

    for (int i = 2; i < money.size() - 1; i++)
    {
        maxdp1[i] = max(maxdp1[i - 1], maxdp1[i - 2] + money[i]);
    }


    vector<int> maxdp2 = money;
    maxdp2[0] = 0;
    maxdp2[1] = money[1];

    for (int i = 2; i < money.size(); i++)
    {
        maxdp2[i] = max(maxdp2[i - 1], maxdp2[i - 2] + money[i]);
    }

    answer = max(*max_element(maxdp1.begin(), maxdp1.end()),
        *max_element(maxdp2.begin(), maxdp2.end()));
    return answer;
}