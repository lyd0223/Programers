#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    reverse(prices.begin(), prices.end());

    while (!prices.empty())
    {
        int num = prices.back();
        prices.pop_back();

        int ct = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            ct++;
            if (prices[i] < num)
                break;

        }
        answer.push_back(ct);
    }

    return answer;
}