#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//동적 계획법을 이용.

int solution(vector<vector<int>> board)
{
    int answer = 0;

    //모두 0인경우 예외처리가 필요하다.
    for (int x = 0; x < board.size(); x++)
    {
        for (int y = 0; y < board[x].size(); y++)
        {
            if (board[x][y] != 0)
            {
                answer = 1;
                break;
            }
        }
    }

    //좌,상,좌상단 수를 파악해서 현재 수를 정해준다.
    for (int x = 1; x < board.size(); x++)
    {
        for (int y = 1; y < board[x].size(); y++)
        {
            //네숫자가 모두 0이아니라면
            if (board[x][y] == 0 || board[x - 1][y - 1] == 0 ||
                board[x - 1][y] == 0 || board[x][y - 1] == 0)
            {
                continue;
            }
            //세 숫자가 같다면
            if (board[x - 1][y - 1] == board[x - 1][y] && board[x - 1][y] == board[x][y - 1])
            {
                board[x][y] = board[x - 1][y - 1] + 1;
                if (answer < board[x][y])
                    answer = board[x][y];

            }
            else
            {
                board[x][y] = min(board[x - 1][y - 1], min(board[x - 1][y], board[x][y - 1])) + 1;
            }

        }

    }


    return answer * answer;
}