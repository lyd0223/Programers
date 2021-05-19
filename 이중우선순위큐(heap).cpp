#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pqmin;
    priority_queue<int> pqmax;
    int ct = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i][0] == 'I')
        {
            string numstr = "";
            for (int j = 2; j < operations[i].length(); j++)
            {
                numstr += operations[i][j];
            }
            ct++;
            pqmin.push(stoi(numstr));
            pqmax.push(stoi(numstr));
        }
        else
        {
            if (operations[i][2] == '-')
            {
                if(!pqmin.empty())
                    pqmin.pop();
                if (ct > 0)
                    ct--;
            }
            else
            {
                if (!pqmax.empty())
                    pqmax.pop();
                if (ct > 0)
                    ct--;
            }
        }
    }
    if (ct == 0)
    {
        vector<int> v(2, 0);
        return v;
    }
    answer.push_back(pqmax.top());
    answer.push_back(pqmin.top());
    return answer;
}
