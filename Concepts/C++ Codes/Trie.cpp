#include <bits/stdc++.h>

using namespace std;

class Trie
{
private:
    struct TrieNode
    {
        bool isEnd;
        TrieNode *arr[26];
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
                arr[i] = nullptr;
            isEnd = false;
        }
    };
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;

        for (char c : word)
        {
            int idx = c - 'a';
            if (node->arr[idx] == nullptr)
                node->arr[idx] = new TrieNode();

            node = node->arr[idx];
        }

        node->isEnd = true;
    }

    bool search(string word)
    {

        TrieNode *node = root;

        for (char c : word)
        {
            int idx = c - 'a';
            if (node->arr[idx] == nullptr)
                return false;
            node = node->arr[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix)
    {

        TrieNode *node = root;

        for (char c : prefix)
        {
            int idx = c - 'a';
            if (node->arr[idx] == nullptr)
                return false;
            node = node->arr[idx];
        }

        return true;
    }
};

int main()
{

    Trie t;
    t.insert("apple");
    t.insert("aple");
    t.insert("aps");

    cout << boolalpha << t.search("apple"); // true
    cout << boolalpha << t.search("aps");   // true
    cout << boolalpha << t.startsWith("a"); // true
    cout << boolalpha << t.startsWith("b"); // false

    return 0;
}