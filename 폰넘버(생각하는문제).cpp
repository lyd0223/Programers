#include <string>
#include <vector>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lnum = 10, rnum = 12;
    // *, 0 , #은 10,11,12로 간주.
    // 행 : %로구함.
    // 열 : /로구함.
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 0)
        {
            numbers[i] = 11;
        }
        if (numbers[i] % 3 == 1)
        {
            lnum = numbers[i];
            answer += "L";
        }
        else if (numbers[i] % 3 == 0)
        {
            rnum = numbers[i];
            answer += "R";
        }
        else
        {
            int dis1 =
                abs((numbers[i] - 1) % 3 - (lnum - 1) % 3) + abs((numbers[i] - 1) / 3 - (lnum - 1) / 3);
            int dis2 =
                abs((numbers[i] - 1) % 3 - (rnum - 1) % 3) + abs((numbers[i] - 1) / 3 - (rnum - 1) / 3);

            if (dis1 < dis2)
            {
                lnum = numbers[i];
                answer += 'L';
            }
            else if (dis1 > dis2)
            {
                rnum = numbers[i];
                answer += 'R';
            }
            else
            {
                if (hand == "right")
                {
                    rnum = numbers[i];
                    answer += "R";
                }
                else
                {
                    lnum = numbers[i];
                    answer += "L";
                }
            }
        }
    }
    return answer;
}