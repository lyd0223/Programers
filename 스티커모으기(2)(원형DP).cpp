#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//dp를 이용해서 품.
//근데 직선형이 아닌 원형이라 2번 돌려야한다.
// 0에서시작하는것과 1에서시작하는것.
int solution(vector<int> sticker)
{
    int answer = 0;
    if (sticker.size() == 1)
    {
        return sticker[0];
    }
    vector<int> maxdp = sticker;
    maxdp[0] = sticker[0];
    maxdp[1] = sticker[0];
    maxdp[maxdp.size() - 1] = 0;
    for (int i = 2; i < sticker.size() - 1; i++)
    {
        maxdp[i] = max(maxdp[i - 1], maxdp[i - 2] + sticker[i]);
    }

    vector<int> maxdp2 = sticker;
    maxdp2[0] = 0;
    maxdp2[1] = sticker[1];
    for (int i = 2; i < sticker.size(); i++)
    {
        maxdp2[i] = max(maxdp2[i - 1], maxdp2[i - 2] + sticker[i]);
    }
    answer = max(*max_element(maxdp.begin(), maxdp.end()),
        *max_element(maxdp2.begin(), maxdp2.end()));
    return answer;
}