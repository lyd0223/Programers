
#include<string>
using namespace std;
//이거 효율성에서 실패했음! 그래서 생각하다가 자료구조 스택으로 변경!
int solution(string s)
{
    int answer = -1;
    
    while (1)
    {
        bool check = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                if (s.length() == 2)
                    s = "";
                else
                    s.erase(s.begin() + i, s.begin() + i + 2);
                check = 1;
                i -= 2;
            }
        }
        if (s.empty())
            return 1;
        if (!check)
            return 0;
    }

    return answer;
}