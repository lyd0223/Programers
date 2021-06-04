#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//정렬 후 substr을 이용
bool solution(vector<string> phone_book) {

    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
        {
            return false;
        }
    }
    return true;
}

//해쉬맵을 이용
//bool solution(vector<string> phone_book) {
//    unordered_map<string,int> um;
//    
//    for(auto a : phone_book)
//    {
//        um.insert(make_pair(a,1));
//    }
//    
//    for(auto a : phone_book)
//    {
//        string s = "";
//        for(int i = 0; i<a.length(); i++)
//        {
//            s+=a[i];
//            if(um[s] == 1 && s != a )
//            {
//                return false;
//            }
//        }
//        
//    }
//    return true;
//    
//}