#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 트리구조로 각 노드는 자식으로 'a'~'z'의 자식Node를 갖는 형식.
class Node
{
private:
    vector<Node*> NodeList;
    int count;

public:
    Node()
    {
        NodeList.resize(26);
        count = 0;
    }
public:
    int GetCount() const
    {
        return count;
    }
    int FindCount(const string& query)
    {
        int size = query.size() - 1;
        int nowsize = 0;
        Node* tempNode = this;
        while (1)
        {
            if (nowsize > size)
                break;
            int a = query[nowsize] - 'a';
            tempNode = tempNode->NodeList[query[nowsize] - 'a'];
            if (tempNode == nullptr)
                return 0;
            nowsize++;
        }
        return tempNode->count;
    }
    void Insert(const string& query, int index)
    {
        if (index >= query.size())
            return;
        if (NodeList[query[index] - 'a'] == nullptr)
            NodeList[query[index] - 'a'] = new Node();
        NodeList[query[index] - 'a']->Insert(query, index + 1);
        count++;
        return;
    }
};
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    //글자길이마다 RootNode 하나씩.
    vector<Node> prefixRootNodeList(10001);
    vector<Node> suffixRootNodeList(10001);

    for (int i = 0; i < words.size(); i++)
    {
        prefixRootNodeList[words[i].size()].Insert(words[i], 0);
        reverse(words[i].begin(), words[i].end());
        suffixRootNodeList[words[i].size()].Insert(words[i], 0);
    }

    // 쿼리를 내 스타일대로 바꿈.
    // pair<키, 접두어는 true 접미어는 false>
    vector<pair<string, bool>> keyList;
    keyList.reserve(queries.size());
    for (string& query : queries)
    {
        string key = "";
        bool isPrefix = true;
        if (query[0] == '?')
            isPrefix = false;
        for (int i = 0; i < query.size(); i++)
        {
            if (query[i] != '?')
                key += query[i];
        }
        if (isPrefix == false)
            reverse(key.begin(), key.end());
        keyList.push_back(make_pair(key, isPrefix));
    }

    // Count
    for (int i = 0; i < keyList.size(); i++)
    {
        int count = 0;
        if (keyList[i].second == true) // prefix
            count = prefixRootNodeList[queries[i].size()].FindCount(keyList[i].first);
        else
            count = suffixRootNodeList[queries[i].size()].FindCount(keyList[i].first);
        answer.push_back(count);
    }
    return answer;
}


void main()
{
    solution({"frodo", "front", "frost", "frozen", "frame", "kakao"}, { "fro??", "????o", "fr???", "fro???", "pro?" });
}