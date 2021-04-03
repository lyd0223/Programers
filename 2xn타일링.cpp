
#include <string>
#include <vector>

using namespace std;
int arr[1001];
int solution(int n) {
	int answer = 0;
	
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	for (int i = 4; i < 1001; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	answer = arr[n];
	return answer;
}
int arr[1001];
int main()
{
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	for (int i = 4; i < 1001; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	int n;
	cin >> n;
	cout << arr[n];
}