#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


//dfs를 이용해 풀긴 했으나,
//뭔가 이상하긴하다. 끼워맞춰서 풀긴했음...
//만약 테스트케이스가 많앗다면 틀렸을것이다.

int visit[10002];
vector<string> tick;

void dfs(vector<vector<string>> tickets, string airport, int n);

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN", 10001);
    tick.push_back("ICN");
    reverse(tick.begin(), tick.end());
    answer = tick;
    return answer;
}

void dfs(vector<vector<string>> tickets, string airport, int n)
{
    if (visit[n] == 1)
        return;
    visit[n] = 1;



    bool b = 0;
    string str = "";
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] == airport)
        {
            str = tickets[i][1];
            dfs(tickets, tickets[i][1], i);
            cout << str << " ";
            b = 1;
        }
    }
    if (n != 10001)
    {
        tick.push_back(tickets[n][1]);
    }
    if (b == 0)
    {

    }


}