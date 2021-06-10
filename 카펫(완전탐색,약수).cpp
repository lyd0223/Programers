#include <string>
#include <vector>
#include "math.h"

using namespace std;

//���ã�¿����� �̿��Ѵ�.
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    int x;
    int y;
    for (int i = 3; i <= sqrt(sum); i++)
    {
        int j = 0;
        if (sum % i == 0)
        {
            j = sum / i;
            if ((i + j) * 2 - 4 == brown)
            {
                //�����Ǳ��̰� ���κ��� ���������...
                if (i > j)
                {
                    answer.push_back(i);
                    answer.push_back(j);
                }
                else
                {
                    answer.push_back(j);
                    answer.push_back(i);
                }
                return answer;
            }
        }
    }
    return answer;
}