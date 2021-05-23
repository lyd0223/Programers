#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0 || ((i != 0) && (s[i - 1] == ' ')))
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] -= 32;
            }
        }
        else
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 32;
            }
        }
    }
    answer = s;
    return answer;
}