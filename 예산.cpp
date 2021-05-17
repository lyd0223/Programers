#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    int i = 0;
    while (1)
    {
        if (i >= d.size())
            return answer;
        budget -= d[i];
        i++;
        if (budget < 0)
            return answer;
        answer++;
    }

    return answer;
}