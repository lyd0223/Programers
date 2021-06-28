#include <string>
#include <vector>

using namespace std;

//arr크기에 유의
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> v;
        answer.push_back(v);
        for (int j = 0; j < arr2[0].size(); j++)
        {
            answer[i].push_back(0);
        }
    }
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2[0].size(); j++)
        {

            for (int k = 0; k < arr1[0].size(); k++)
            {
                answer[i][j] += (arr1[i][k] * arr2[k][j]);
            }

        }
    }

    return answer;
}