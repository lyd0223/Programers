#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<string> numStr = { "zero", "one" , "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    
    int answer = 0;
    string answerStr = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            answerStr += s[i];
            continue;
        }
        for (int j = 0; j < numStr.size(); j++)
        {
            if (!numStr[j].compare(0, numStr[j].size(), s, i, numStr[j].size()))
            {
                answerStr += to_string(j);
            }
        }
    }
    answer = stoi(answerStr);
}