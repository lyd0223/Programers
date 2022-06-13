#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    // 종류 / 갯수
    map<string, int> clothTypeMap; 

    //각 의상종류마다 갯수를 세줌.
    for (vector<string>& data : clothes)
    {
        if (clothTypeMap.find(data[1]) == clothTypeMap.end())
            clothTypeMap.insert(make_pair(data[1], 1));
        else
            clothTypeMap[data[1]]++;
    }

    //경우의수를 구함.
    map<string, int>::iterator iter;
    for (iter = clothTypeMap.begin(); iter != clothTypeMap.end(); iter++)
    {
        answer *= iter->second + 1;
    }
    
    //아무것도 입지않은경우
    answer--;

    return answer;
}