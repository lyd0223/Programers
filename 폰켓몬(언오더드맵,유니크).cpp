#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;


//유니크 이용
int solution(vector<int> nums)
{
    int answer = 0;
    int numsSize = nums.size();
    
    sort(nums.begin(), nums.end());
    vector<int>::iterator iter =  unique(nums.begin(), nums.end());
    nums.erase(iter, nums.end()); 

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    if (nums.size() > numsSize / 2)
    {
        answer = numsSize / 2;
    }
    else
    {
        answer = nums.size();
    }
    return answer;
}

//언오더드 맵 이용
int solution2(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> um;

    for (int i = 0; i < nums.size(); i++)
        um[nums[i]]++;

    if (nums.size() / 2 > um.size())
    {
        answer = um.size();
    }
    else
    {
        answer = nums.size() / 2;
    }
    return answer;
}

int main()
{
    vector<int> v = { 3,71,3,1,444,2,3,1,2,2,71,1,2,5,99 };
    solution(v);
}