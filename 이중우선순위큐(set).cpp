#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include<set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    set<int> s;
    int ct = 0;
    for (auto a : operations)
    {
        if (a[0] == 'I')
        {
            string str = "";
            for (int i = 2; i < a.length(); i++)
            {
                str += a[i];
            }
            s.insert(stoi(str));
        }
        else
        {
            if (a[2] == '-')
            {
                if (!s.empty())
                    s.erase(s.begin());
            }
            else
            {
                if (!s.empty())
                    s.erase(--s.end());
            }
        }
    }
    if (s.empty())
    {
        vector<int> v = { 0,0 };
        return v;
    }
    answer.push_back(*(--s.end()));
    answer.push_back(*(s.begin()));
    return answer;
}