#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> sco;
    for (int i = 0; i < scoville.size(); i++)
    {
        sco.push(scoville[i]);
    }
    while (1)
    {
        if (sco.size() < 2)
            return -1;
        if (sco.top() > K)
            return answer;
        int min1 = sco.top();
        sco.pop();
        int min2 = sco.top();
        sco.pop();
        int newScoville = min1 + min2 * 2;
        sco.push(newScoville);

        answer++;
    }
    return answer;
}

int main()
{
    priority_queue<int,vector<int>,greater<int>> heap;
    heap.push(1);
    heap.push(10);
    heap.push(5);
    heap.push(13);
    heap.push(15);
    
    int size = heap.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << heap.top() << " ";
        heap.pop();
    }
}