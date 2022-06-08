#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//이분탐색 이용
long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    long long min = 1;
    long long max = (long long)times[times.size() - 1] * n;

    while (min <= max)
    {
        long long mid = (min + max) / 2;
        long long ct = 0;

        for (long long time : times)
        {
            ct += mid / time;
        }

        if (ct >= n)
        {
            max = mid - 1;
            answer = mid;
        }
        else
            min = mid + 1;
    }

    return answer;
}