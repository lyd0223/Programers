#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> num;
    int sq = 0;
    int temp = n;
    while (temp >= 3)
    {
        temp = temp / 3;
        sq++;
    }
    while (sq != 0)
    {
        num.push_back(n / (int)pow(3, sq));
        n = n % (int)pow(3, sq);
        sq--;
    }
    num.push_back(n);
    string revNum;
    for (int i = num.size() - 1; i >= 0; i--)
        revNum += num[i] + 48;
    answer = stoi(revNum, NULL, 3);
    return answer;
}

int main()
{
    
    string s;

    int n;
		cin >> n;
		cout << solution(n);
}