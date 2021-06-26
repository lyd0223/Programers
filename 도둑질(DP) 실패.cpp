#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> money) {
    //bool값은 1번이 들어갓는지를 파악하기위함.
    vector<pair<int, bool>> m;

    for (int i = 0; i < money.size(); i++)
    {
        m.push_back(make_pair(money[i], false));
    }
    m[0].second = true;

    if (m[m.size() - 1].first + m[2].first <= m[0].first + m[2].first)
    {
        m[2].first = m[2].first + m[0].first;
        m[2].second = true;
    }
    if (m[m.size() - 2].first + m[1].first <= m[m.size() - 1].first + m[1].first)
    {
        m[1].first = m[1].first + m[m.size() - 1].first;
    }
    int answer = max(m[0].first, max(m[1].first, m[2].first));;


    for (int i = 3; i < m.size(); i++)
    {
        if (m[i - 3].first + m[i].first > m[i - 2].first + m[i].first)
        {
            m[i].first = m[i - 3].first + m[i].first;
            if (m[i - 3].second == true)
                m[i].second = true;
        }
        else
        {
            m[i].first = m[i - 2].first + m[i].first;
            if (m[i - 2].second == true)
                m[i].second = true;
        }

        if (answer < m[i].first)
        {
            if (i == money.size() - 1 && m[i].second == true)
            {
                break;
            }
            answer = m[i].first;
        }
    }

    return answer;
}

int main()
{
    cout << "1 : " <<solution({ 1, 1, 4, 1, 4 }) << " " << 8 << endl;
    cout << "2 : " <<solution({ 1000, 0, 0, 1000, 0, 0, 1000, 0, 0, 1000 }) << " " << 3000 << endl;
    cout << "3 : " <<solution({ 1000, 1, 0, 1, 2, 1000, 0 }) << " " << 2001 << endl;
    cout << "4 : " <<solution({ 1000, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 1000 }) << " " << 2000 << endl;
    cout << "5 : " <<solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }) << " " << 30 << endl;
    cout << "6 : " <<solution({ 0, 0, 0, 0, 100, 0, 0, 100, 0, 0, 1, 1 }) << " " << 201 << endl;
    cout << "7 : " <<solution({ 11, 0, 2, 5, 100, 100, 85, 1 }) << " " << 198 << endl;
    cout << "8 : " <<solution({ 1, 2, 3 }) << " " << 3 << endl;
    cout << "9 : " <<solution({ 91, 90, 5, 7, 5, 7 }) << " " << 104 << endl;
    cout << "10 :" <<solution({ 90, 0, 0, 95, 1, 1 }) << " " << 185 << endl;
}