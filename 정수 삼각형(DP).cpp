#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//DP문제.
//이전까지의 합을 구한뒤 뒤를 구함.
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for (int i = 0; i < triangle.size() - 1; i++)
    {
        for (int j = 0; j < triangle[i + 1].size(); j++)
        {
            if (j == 0)
                triangle[i + 1][j] += triangle[i][0];
            else if (j == triangle[i + 1].size() - 1)
                triangle[i + 1][j] += triangle[i][triangle[i].size() - 1];
            else
                triangle[i + 1][j] += max(triangle[i][j - 1], triangle[i][j]);
        }
    }
    sort(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
    answer = triangle[triangle.size() - 1][triangle[triangle.size() - 1].size() - 1];
    return answer;
}