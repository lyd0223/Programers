#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string str = to_string(n);
    for(int i = 0; i< str.length(); i++)
    {
        answer.push_back(str[i]-48);
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}