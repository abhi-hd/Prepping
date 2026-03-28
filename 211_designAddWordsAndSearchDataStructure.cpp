/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

    WordDictionary() Initializes the object.
    void addWord(word) Adds word to the data structure, it can be matched later.
    bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

*/
#include <bits/stdc++.h>
using namespace std;
/*
Lessons:
Be careful with infinite instantiation in constructor.
Look at the return pattern carefully
*/
class WordDictionary
{
public:
    unordered_map<char, WordDictionary *> store;
    WordDictionary()
    {
        store['*'] = NULL;
    }

    void addWord(string word)
    {
        if (store['*'] == NULL)
            store['*'] = new WordDictionary();
        WordDictionary *itr = store['*'];
        for (char c : word)
        {
            if (itr->store.count(c) == 0)
                itr->store[c] = new WordDictionary();
            itr = itr->store[c];
        }
        itr->store['#'] = NULL;
    }

    bool search(string word)
    {
        if (store['*'] == NULL)
            store['*'] = new WordDictionary();
        WordDictionary *itr = store['*'];
        return search(word, 0, store['*']);
    }

    bool search(string word, int index, WordDictionary *dict)
    {
        bool result = false;
        for (int i = index; i < word.size(); i++)
        {
            if (word[i] != '.')
            {
                if (!dict->store.count(word[i]))
                    return false;
                dict = dict->store[word[i]];
            }
            else
            {
                for (int j = 0; j < 26; j++)
                {
                    if (dict->store.count('a' + j) != 0)
                        result = result || search(word, i + 1, dict->store['a' + j]);
                }
                return result;
            }
        }
        return dict->store.count('#') != 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */