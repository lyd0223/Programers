#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    //예외처리. 합이 수보다 적으면 만들 수 없다.
    if (s < n)
    {
        answer.push_back(-1);
    }
    else
    {
        //생각해본 결과, 합이 s인 n개의 수로 가장 큰 곱을 가지려면,
        //수 사이의 차이가 가장 적어야한다.
        //따라서, 나눈 값으로 모든 수를 채워넣되, 남는값들을 나눈 devide에 1씩 더해준다. 
        int devide = s / n;
        int remain = s % n;

        //일단 먼저 수를 채워넣음 
        //ex) n = 5, s = 22
        //    devide = 4, remain = 2
        //    answer = [ 5, 5, 5, 5 ] 
        //    문제는 오름차순 정렬을 원하고있으므로 뒤에서부터.
        //    remain이 2이므로 두개 1씩더해줌.
        //    answer = [ 5, 5, 6, 6 ]
        while (answer.size() != n)
        {
            answer.push_back(devide);
        }
        int ct = answer.size() - 1;
        while (remain != 0)
        {
            answer[ct] ++;
            ct--;
            remain--;
        }
    }
    return answer;
}