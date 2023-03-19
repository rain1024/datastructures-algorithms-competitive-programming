#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class WordDictionary {
private:
    struct TrieNode {
        char val;
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isEnd = false;
        }
    };
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for(auto c: word){
            int index = c - 'a';
            if(current->children[index] == NULL){
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
    }

    bool dfs(string word, int i, TrieNode* node){
        if(i == word.size()){
            return node->isEnd;
        }

        char c = word[i];
        if(c == '.'){
            for(int index=0; index<26; index++){
                if(node->children[index] != NULL){
                    TrieNode* current = node->children[index];
                    if(dfs(word, i+1, current)){
                        return true;
                    }
                }
            }
            return false;
        }
        int index = c - 'a';
        if(node->children[index] == NULL){
            return false;
        }
        return dfs(word, i+1, node->children[index]);
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */