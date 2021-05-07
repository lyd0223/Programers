#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string solution(int n) {
    string answer = "";
    int c = 0;
    while (n > 0)
    {
        if (n % 3 == 1)
            answer = "1" + answer;
        else if (n % 3 == 2)
            answer = "2" + answer;
        else if (n % 3 == 0)
            answer = "4" + answer;
        if (n % 3 == 0)
            n = n / 3 - 1;
        else
            n = n / 3;


    }
    return answer;
}