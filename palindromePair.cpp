#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    //bool isWord;
    int index;
    TrieNode* children[26];
    TrieNode() {
        //isWord = false;
        index = -1;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word, int index) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++){
            if(cur->children[(int)(word[i] - 'a')] == NULL)
                cur->children[(int)(word[i] - 'a')] = new TrieNode();
            cur = cur->children[(int)(word[i] - 'a')];
        }
        //cur->isWord = true;
        cur->index = index;
    }

    // Returns if the word is in the trie.
    int search(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++){
            if(cur->children[(int)(word[i] - 'a')] == NULL)
                return -1;
            cur = cur->children[(int)(word[i] - 'a')];
        }
        //return cur->isWord;
        return cur->index;
    }

private:
    TrieNode* root;
};

class Solution {
private:
    Trie trie;
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > rslt;
        unordered_set<int> pairs;
        for(int i = 0; i < words.size(); i++)
            trie.insert(words[i], i);
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j <= words[i].length(); j++){
                if(isPalindrome(words[i], 0, j-1)){//prefix
                    string str = words[i].substr(j);
                    reverse(str.begin(), str.end());
                    int searchRes = trie.search(str);
                    cout << str << " " << searchRes << endl;
                    if(searchRes != -1 && searchRes != i){
                        pairs.insert(searchRes * words.size() + i);
                        cout << "1: " << i << " " << j << " " << searchRes << endl;
                    }
                }
                if(isPalindrome(words[i], j, words[i].length()-1)){//surfix
                    string str = words[i].substr(0, j);
                    reverse(str.begin(), str.end());
                    int searchRes = trie.search(str);
                    if(searchRes != -1 && searchRes != i){
                        pairs.insert(i * words.size() + searchRes);
                        cout << "2: " << i << " " << j << " " << searchRes << endl;
                    }
                }
            }
        }
        for(auto p:pairs){
            vector<int> v;
            v.push_back(p / words.size());
            v.push_back(p % words.size());
            rslt.push_back(v);
        }
        return rslt;
    }
    bool isPalindrome(string& s, int start, int end){
        while(start <= end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<string> words;
    words.push_back("abcd");
    words.push_back("dcba");
    words.push_back("lls");
    words.push_back("s");
    words.push_back("sssll");
    s.palindromePairs(words);
    return 0;
}