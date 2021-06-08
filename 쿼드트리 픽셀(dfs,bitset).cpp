#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

//깊이우선탐색을 이용해 구현했다. 

//문자열의 위치를 기억하는 sdir와 비트셋의 위치를 기억하는 bitdir를 인자로 받아야함.
void dfs(int bit, int sdir, string s, bitset<1024>& bits, int bitdir)
{
    //비트셋의 위치를 기억하는 bitdir를 이용한다.
    if (s[sdir] != 'p')
    {
        if (s[sdir] == 'b')
        {
            for (int i = 0; i < bit; i++)
                bits[bitdir + i] = 1;
        }
        bitdir += bit;
        return;
    }
    
    //쿼드트리이므로, 문자가 'p'라면 4개만 dfs에 넣어줘야한다. 
    //근데 이게 사이에 또 p가 껴있다면? 문자열 4칸을 뛰어넘어준다.
    int n = 4;
    for (int i = sdir +1; i < s.size();)
    {
        if (n == 0)
            break;
        dfs(bit / 4, i, s, bits, bitdir);
        
        if (s[i] == 'p' )
            i += 4;
        i++;
        n--;
        bitdir +=(bit/4);
    }
}
int solution(string s1 , string s2) {
    int answer = 0;
    //두개의 or연산을 구하는건 bitset 자료구조를 쓰면 편할거라 생각해 bitset 자료구조를 이용함.
    //1024픽셀의 이미지이므로, 1024크기의 bitset 두개를 선언.
    bitset<1024> bits1;
    bitset<1024> bits2;

    dfs(1024, 0, s1, bits1, 0);
    dfs(1024, 0, s2, bits2, 0);

    cout << bits1.count() << endl;
    cout << bits2.count() << endl;

    cout << (bits1 |= bits2).count();
    
    return answer;
}

int main()
{
    solution("ppwwwbpbbwwbw", "pwbwpwwbw");
}