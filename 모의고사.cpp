#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer, answer1, answer2, answer3;
	int temp1 = 1;
	map<int, int> m;
	m.insert({ 1, 0 });
	m.insert({ 2, 0 });
	m.insert({ 3, 0 });
	for (int i = 0; i < answers.size(); i++)
	{
		answer1.push_back((i) % 5 + 1);

		if (i % 2 == 0)
			answer2.push_back(2);
		else
		{

			if (temp1 == 1)
				answer2.push_back(1);
			else if (temp1 == 2)
				answer2.push_back(3);
			else if (temp1 == 3)
				answer2.push_back(4);
			else if (temp1 == 4)
				answer2.push_back(5);

			if (temp1 == 4)
				temp1 = 1;
			else temp1++;

		}

		if (i % 10 == 0 || i % 10 == 1)
			answer3.push_back(3);
		else if (i % 10 == 2 || i % 10 == 3)
			answer3.push_back(1);
		else if (i % 10 == 4 || i % 10 == 5)
			answer3.push_back(2);
		else if (i % 10 == 6 || i % 10 == 7)
			answer3.push_back(4);
		else if (i % 10 == 8 || i % 10 == 9)
			answer3.push_back(5);

		if (answer1[i] == answers[i])
			m[1]++;
		if (answer2[i] == answers[i])
			m[2]++;
		if (answer3[i] == answers[i])
			m[3]++;
	}
	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(),
		[](pair<int, int> a, pair<int, int> b)
		{
			return a.second > b.second;
		});
	if (v[0].second == v[1].second)
	{
		if (v[1].second == v[2].second)
		{
			sort(v.begin(), v.end(),
				[](pair<int, int> a, pair<int, int> b)
				{
					return a.first < b.first;
				});
		}
		sort(v.begin(), v.end() - 1,
			[](pair<int, int> a, pair<int, int> b)
			{
				return a.first < b.first;
			});
	}


	answer.push_back(v[0].first);
	if (v[0].second == v[1].second)
	{
		answer.push_back(v[1].first);
		if (v[1].second == v[2].second)
			answer.push_back(v[2].first);

	}
	return answer;
}

int main()
{
	solution({ 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 });

	

}