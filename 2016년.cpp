#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

string solution(int a, int b) {
    string answer = "";
    int dydlf = 4;
    for (int i = 1; i <= a; i++)
    {
        int daynum;
        if (i == 2) daynum = 29;
        else if (i == 1 || i == 3 || i == 5 ||
            i == 7 || i == 8 || i == 10 || i == 12) daynum = 31;
        else daynum = 30;
        for (int j = 1; j <= daynum; j++)
        {
            if (dydlf == 7) dydlf = 1;
            else dydlf++;
            if (i == a && j == b)
            {
                switch (dydlf)
                {
                case 1:
                    return "MON";
                case 2:
                    return "TUE";
                case 3:
                    return "WED";
                case 4:
                    return "THU";
                case 5:
                    return "FRI";
                case 6:
                    return "SAT";
                case 7:
                    return "SUN";
                }
            }

        }
    }

}
using namespace std;

int main()
{
	

	cout << solution(5,24);

}