#include <string>
#include <vector>

using namespace std;

int visit[201];
int answer;
void dfs(vector<vector<int>> computers, int com);
int solution(int n, vector<vector<int>> computers) {
    answer = n;
    for (int i = 0; i < n; i++)
    {
        dfs(computers, i);
    }

    return answer;
}

void dfs(vector<vector<int>> computers, int com)
{
    if (visit[com] == 1)
        return;
    visit[com] = 1;
    for (int i = 0; i < computers[com].size(); i++)
    {
        if (com != i)
        {
            if (computers[com][i] == 1 && visit[i] != 1)
            {
                dfs(computers, i);
                answer--;
            }
        }
    }

}