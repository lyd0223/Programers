#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//한 점으로부터의 각 지점의 최단거리를 구하는 문제.
//벨만포드 알고리즘을 이용했다.

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> dis(N + 1, 555555);
    dis[1] = 0;
    sort(road.begin(), road.end());

    for (int j = 1; j < N; j++)
    {
        for (int i = 0; i < road.size(); i++)
        {
            int to = max(road[i][0], road[i][1]);
            int from = min(road[i][0], road[i][1]);
            if (road[i][2] + dis[from] < dis[to])
                dis[to] = road[i][2] + dis[from];
            if (road[i][2] + dis[to] < dis[from])
                dis[from] = road[i][2] + dis[to];
        }
    }
    for (int i = 1; i < dis.size(); i++)
    {
        if (dis[i] <= K)
            answer++;
    }

    return answer;
}