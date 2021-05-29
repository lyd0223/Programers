#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    reverse(progresses.begin(), progresses.end());
    reverse(speeds.begin(), speeds.end());

    int ct = 0;
    while (!progresses.empty())
    {

        if (progresses[progresses.size() - 1] >= 100)
        {
            progresses.pop_back();
            speeds.pop_back();
            ct++;
            if (progresses.empty())
            {
                answer.push_back(ct);
            }
            continue;
        }

        if (ct != 0)
        {
            answer.push_back(ct);
            ct = 0;
        }

        for (int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
        }
    }
    return answer;
}