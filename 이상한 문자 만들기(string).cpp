#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int ct = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ct = 0;
            continue;
        }
        if (ct % 2 == 0)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
        }
        else
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
        ct++;
    }
    answer = s;
    return answer;
}