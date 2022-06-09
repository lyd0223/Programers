#include <string>
#include <vector>
#include <queue>

using namespace std;

//그래프 구조로 변경후, bfs로 최단거리 입력.
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < edge.size(); i++)
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    int maxDis = 0;
    vector<int> disArr(n + 1, -1);
    queue<int> q;
    q.push(1);
    disArr[1] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (disArr[next] != -1)
                continue;

            q.push(graph[now][i]);
            disArr[next] = disArr[now] + 1;

            if (maxDis < disArr[next])
                maxDis = disArr[next];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        if (disArr[i] == maxDis)
            answer++;
    }
    return answer;
}
