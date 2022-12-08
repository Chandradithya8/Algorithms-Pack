#include <bits/stdc++.h>
using namespace std;

// least common prefix

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie {
public:
    TrieNode *root = new TrieNode('\0');

    void insertUtil(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        TrieNode *child;

        // assume that the word is upper case
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void findUtil(TrieNode *root, string &ans)
    {
        int count = 0;
        TrieNode *child;
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                child = root->children[i];
                count++;
            }
        }

        if (count == 1)
        {
            ans += child->data;
        }
        else
        {
            return;
        }
        findUtil(child, ans);
    }

    void findPrefix(string& ans)
    {
        findUtil(root, ans);
    }
};

int main() {
    vector<string> arr = {"coding", "code", "coded", "codingninja"};
    Trie tr;
    int n = arr.size();
    for (int i = 0; i < n; i++) 
    {
        tr.insertWord(arr[i]);
    }

    string ans = "";
    tr.findPrefix(ans);

    cout << ans << endl;
}

