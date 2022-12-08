#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode('\0');

    void insertUtil(TrieNode* root, string word) {
        if(word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        TrieNode* child;

        // assume that the word is lower case
        int index = word[0] - 'a';
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        if(word.size() == 0) {
            return root->isTerminal;
        }

        TrieNode* child;
        int index = word[0] - 'a';

        // present
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode *root, string word) {
        if(word.size() == 0) {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return;
        }

        removeUtil(child, word.substr(1));
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }
};


int main() {
    // insertion

    Trie t;
    t.insertWord("ABC");
    t.insertWord("DEF");
    t.insertWord("XYZ");

    // searching

    cout << "Present or not " << t.searchWord("ABC") << endl;

    // remove word

    t.removeWord("ABC");
    cout << "Present or not " << t.searchWord("ABC");
}

