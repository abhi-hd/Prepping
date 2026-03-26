/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

    Trie() Initializes the trie object.
    void insert(String word) Inserts the string word into the trie.
    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
Use one prefixLookup function for both , code reuse
*/
class Trie
{
private:
    struct TrieNode
    {
        char val;
        unordered_map<char, TrieNode *> store;
        TrieNode() : val('#') {}
        TrieNode(char c) : val(c), store(unordered_map<char, TrieNode *>()) {}
    };
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('*');
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (curr->store.find(c) != curr->store.end(c))
            {
                curr = curr->store[c];
                continue;
            }
            TrieNode *newNode = new TrieNode(c);
            curr->store[c] = newNode;
            curr = curr->store[c];
        }
        curr->store['!'] = new TrieNode('!');
    }

    bool search(string word)
    {
        TrieNode *itr = prefixLookup(word);
        return itr == NULL ? false : itr->store.find('!') != itr->store.end();
    }

    bool startsWith(string prefix)
    {
        TrieNode *itr = prefixLookup(prefix);
        return itr != NULL;
    }

    TrieNode *prefixLookup(string prefix)
    {
        TrieNode *curr = root;
        for (char c : prefix)
        {
            if (curr->store.find(c) == curr->store.end())
                return NULL;
            curr = curr->store[c];
        }
        return curr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */