#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    vector<char> nameVec(name.length(), 'A');


    for (int i = 0; i < nameVec.size(); i++)
    {
        if (name[i] > 'N')
        {
            answer += (26 - (name[i] - nameVec[i]));

        }
        else
        {
            answer += (name[i] - nameVec[i]);
        }
        nameVec[i] = name[i];
    }
    vector<int> visit;
    vector<int> allvisit(nameVec.size(), 1);
    for (int i = 0; i < nameVec.size(); i++)
    {
        if (nameVec[i] == 'A')
            visit.push_back(1);
        else
            visit.push_back(0);
    }
    visit[0] = 1;
    int i = 0;
    for (int i = 0; i < visit.size(); i++)
        cout << visit[i];
    while (visit != allvisit)
    {
        int n = 1;
        while (1)
        {
            int prev = i - n;
            if (prev < 0)
            {
                prev = prev + visit.size();
            }
            int next = i + n;
            if (next >= visit.size())
            {
                next = next - visit.size();
            }

            if (visit[next] == 0)
            {
                i = next;
                visit[next] = 1;
                break;
            }
            else if (visit[prev] == 0)
            {
                i = prev;
                visit[prev] = 1;
                break;
            }
            n++;
        }
        cout << n << " ";
        answer += n;
    }

    return answer;
}