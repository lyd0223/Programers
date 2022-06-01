#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

//공백단위 스트링 분할
vector<string> Split(string& str)
{
	vector<string> result;
	int pivot = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			result.push_back(str.substr(pivot, i - pivot));
			pivot = i + 1;
		}
	}
	result.push_back(str.substr(pivot, str.size() - pivot));
	for (string& s : result)
	{
		std::cout << s << std::endl;
	}

	return result;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;

	map<string, string> userMap;
	vector<pair<string, string>> log;
	for (int i = 0; i < record.size(); i++)
	{
		vector<string> splitStr = Split(record[i]);
		switch (splitStr[0][0])
		{
		case 'E': // Enter
			if (userMap.find(splitStr[1]) != userMap.end())
			{
				userMap[splitStr[1]] = splitStr[2];
				log.push_back(make_pair(splitStr[1], "님이 들어왔습니다."));
				break;
			}
			userMap.insert(make_pair(splitStr[1], splitStr[2]));
			log.push_back(make_pair(splitStr[1], "님이 들어왔습니다."));
			break;
		case 'L': // Leave
			log.push_back(make_pair(splitStr[1], "님이 나갔습니다."));
			break;
		case 'C': // Change
			userMap[splitStr[1]] = splitStr[2];
			cout << "Change :" << splitStr[1] << " -> " << splitStr[2] << endl;
			break;
		}
	}
	for (int i = 0; i < log.size(); i++)
	{
		string str = userMap[log[i].first];
		str += log[i].second;
		
		answer.push_back(str);
	}
	
	return answer;
}
