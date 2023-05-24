#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    struct TrieNode
    {
        TrieNode *children[26];
        bool isEnd;
    };

    TrieNode *rootNode;

    Trie()
    {
        rootNode = getNode();
    }

    TrieNode *getNode()
    {
        TrieNode *currNode = new TrieNode;

        currNode->isEnd = false;

        for (long i = 0; i < 26; i++)
        {
            currNode->children[i] = nullptr;
        }

        return currNode;
    }

    void insert(string word)
    {
        TrieNode *curr = rootNode;
        for (long i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (!curr->children[index])
            {
                curr->children[index] = getNode();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *curr = rootNode;

        for (long i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (!curr->children[index])
            {
                return false;
            }

            curr = curr->children[index];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = rootNode;

        for (long i = 0; i < prefix.size(); i++)
        {
            int index = prefix[i] - 'a';
            if (!curr->children[index])
            {
                return false;
            }

            curr = curr->children[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */