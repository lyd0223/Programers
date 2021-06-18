#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

//규칙을 찾기위해 dfs를 이용해 다 돌려봤다.
//2 5 14 42 132 429... 
//이는 '카탈랑 수'라는 수열이다.
// 카탈랑 수 ? 이진 트리를 세는 수열이다.
// 카탈랑 수의 식 : arr[i] = 2(2i+1) / i+2 * arr[i-1]

/*
int count;
//str이 size크기이며, 올바른괄호인지 파악.
void check(string str, int size)
{
    stack<char> s;
    //사이즈가 맞는지 체크
    if(size != str.size())
        return;

    for(int i = 0; i<str.size(); i++)
    {
        if(str[i] == '(')
        {
            s.push(str[i]);
        }
        else
        {
            if(s.empty())
            {
                return;
            }
            else
            {
                s.pop();
            }
        }
    }
    if(s.empty())
    {
        //cout << str << endl;
        count++;
    }

}
void dfs(string now ,int n, int ct)
{
    if(ct > n)
        return;
    check(now, n);
    dfs(now+"(", n, ct+1);
    dfs(now+")", n, ct+1);
}
*/
int solution(int n) {
    //dfs("(", 2*n, 1);
    //cout << count ;

    float arr[15] = { 0, };
    arr[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        arr[i + 1] = (2.f * (2.f * (float)i) + 2.f) / ((float)i + 2.f) * arr[i];
        cout << arr[i] << endl;
    }
    return arr[n];
}