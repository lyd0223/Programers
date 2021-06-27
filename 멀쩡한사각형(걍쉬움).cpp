#include <algorithm>
using namespace std;

//초간단 문제라 뭐 설명할게없다...
//w,h중 큰수 - 작은수를 계속 빼주면된다.
long long solution(int w, int h) {
    long long answer = (long)w * h;
    int maxnum = max(w, h);
    int minnum = min(w, h);

    int temp = 1000000000;
    while (temp != 0)
    {
        temp = maxnum - minnum;
        answer -= minnum;
        maxnum = max(temp, minnum);
        minnum = min(temp, minnum);
    }


    return answer;
}