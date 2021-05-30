#include <string>
#include <vector>

using namespace std;

char Conversion(char c, int n)
{
    if (c >= 'a' && c <= 'z')
    {
        if (c + n > 'z')
            return c + n - 26;
        else
            return c + n;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        if (c + n > 'Z')
            return c + n - 26;
        else
            return c + n;
    }
    else
        return c;
}
string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.length(); i++)
    {
        answer += Conversion(s[i], n);
    }
    return answer;
}