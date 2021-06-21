#include <string>
#include <vector>
#include <iostream>
using namespace std;
//이차원배열에 공식에 맞게 숫자를 넣어두고,
//그를 1차원 배열에 넣어준다.
vector<int> solution(int n) {
    vector<int> answer;
    int arr[1001][1001] = { 0 };
    int ct = n - 1;
    int y = 1;
    int x = 1;
    int num = 1;
    //case 1 : y값증가
    //case 2 : x값증가
    //case 3 : y값감소
    int casenum = 0;
    while (ct > 0)
    {
        for (int i = 0; i < ct; i++)
        {
            arr[y][x] = num;
            num++;
            switch (casenum)
            {
            case 0:
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                x--;
                break;
            }
        }
        if (x != 1)
            ct--;
        casenum++;
        if (casenum > 2)
            casenum = 0;
    }
    arr[y][x] = num;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] != 0)
                answer.push_back(arr[i][j]);
            else
                break;
        }

    }
    return answer;
}