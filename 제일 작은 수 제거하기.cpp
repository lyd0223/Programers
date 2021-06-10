#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    int temp = arr[0];
    int n = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < temp)
        {
            temp = arr[i];
            n = i;
        }
    }
    arr.erase(arr.begin() + n);
    if (arr.size() == 0)
        arr.push_back(-1);
    answer = arr;
    return answer;
}