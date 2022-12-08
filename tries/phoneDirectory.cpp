#include<bits/stdc++.h>
using namespace std;

// implementation of phone directory

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

class Trie
{
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

        // assume that the word is lower case
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

    void getSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(next->data);
                getSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> solve(string queryStr)
    {
        TrieNode *prev = root;
        string prefix = "";
        vector<vector<string>> output;

        for (int i = 0; i < queryStr.size(); i++)
        {
            char lastch = queryStr[i];
            TrieNode *curr = prev->children[lastch - 'a'];

            if (curr == NULL)
            {
                break;
            }
            prefix.push_back(lastch);
            vector<string> temp;
            getSuggestions(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie tr;
    for (int i = 0; i < contactList.size(); i++)
    {
        tr.insertWord(contactList[i]);
    }
return tr.solve(queryStr);
    
}

int main() {
    vector<string> words = {"adithya", "chandra", "chand", "adith"};
    string query = "chand";
    auto it = phoneDirectory(words, query);
    for(auto it1 : it) {
        for(auto it2 : it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }
}



