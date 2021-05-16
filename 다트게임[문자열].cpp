#include <string>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    int scorecount = 0;
    for (int i = 0; i < dartResult.length(); i++)
    {
        if (dartResult[i] == '*' || dartResult[i] == '#')
        {
            if (dartResult[i] == '*')
            {
                score[scorecount] *= 2;
                if (scorecount != 0)
                    score[scorecount - 1] *= 2;
            }
            else if (dartResult[i] == '#')
                score[scorecount] *= -1;

            //scorecount++;
        }
        else
        {
            if (dartResult[i] == '0')
            {
                if (i != 0)
                    scorecount++;
                score.push_back(0);
            }
            if (dartResult[i] == '1')
            {
                if (i != 0)
                    scorecount++;
                if (dartResult[i + 1] == '0')
                {
                    score.push_back(10);
                    i++;
                }
                else
                    score.push_back(1);
            }
            else if (dartResult[i] == '2')
            {
                if (i != 0)
                    scorecount++;
                score.push_back(2);
            }
            else if (dartResult[i] == '3')
            {
                if (i != 0)
                    scorecount++;
                score.push_back(3);
            }
            else if (dartResult[i] == '4')
            {
                if (i != 0)
                    scorecount++;
                score.push_back(4);
            }
            else if (dartResult[i] == '5')
            {
                if (i != 0)
                    scorecount++;
                score.push_back(5);
            }
            else if (dartResult[i] == '6')
            {
                if (i != 0)
                    scorecount++;
                score.push_back(6);
            }
            else if (dartResult[i] == '7')
            {
                if (i != 0)
                    scorecount++;
                score.push_back(7);
            }
            else if (dartResult[i] == '8')
            {
                if (i != 0)
                    scorecount++;
                score.push_back(8);
            }
            else if (dartResult[i] == '9')
            {
                if (i != 0)
                    scorecount++;
                score.push_back(9);
            }
            else if (dartResult[i] == 'S')
            {
                if (i + 1 <= dartResult.size())
                {
                    if (dartResult[i + 1] != '*' && dartResult[i + 1] != '#');
                    //scorecount++;
                }
            }
            else if (dartResult[i] == 'D')
            {
                score[scorecount] = pow(score[scorecount], 2);
                if (i + 1 <= dartResult.size())
                {
                    if (dartResult[i + 1] != '*' && dartResult[i + 1] != '#');
                    //scorecount++;
                }
            }
            else if (dartResult[i] == 'T')
            {
                score[scorecount] = pow(score[scorecount], 3);
                if (i + 1 <= dartResult.size())
                {
                    if (dartResult[i + 1] != '*' && dartResult[i + 1] != '#');
                    //scorecount++;
                }
            }


        }

    }
    for (int i = 0; i < score.size(); i++)
    {
        answer += score[i];
        cout << score[i] << " ";
    }
    cout << "   " << answer << endl;
    return answer;
}

int main()
{
    solution("1S2D*3T");
    solution("1D2S#10S");
    solution("1D2S0T");
    solution("1T*0D*2S");
    solution("3T#3S*3T*");
    solution("1T*3S*3S#");
    solution("2D1T2S*");
    solution("1S2D*3T*");
    solution("1S*2D*3T*");
    solution("1S2D3T*");
}