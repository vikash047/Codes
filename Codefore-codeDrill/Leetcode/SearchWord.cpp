#include<bits/stdc++.h>

using namespace std;

struct Trie{
    unordered_map<char, struct Trie*> next = {};
    priority_queue<string> suggest = {};
};

class TriSol {
    Trie* root = new Trie();
    public:
    vector<vector<string>> search(vector<string> products, string word) {
        for(string s : products) {
            Trie* ptr = root;
            for(char ch : s) {
                if(!ptr->next.count(ch)) {
                    ptr->next[ch] = new Trie();
                }
                ptr = ptr->next[ch];
                ptr->suggest.push(s);
                if(ptr->suggest.size() > 3) ptr->suggest.pop();
            }
        }
        vector<vector<string>> ans(word.size());
        for(int i = 0; i < word.size() && root->next.count(word[i]); i++) {
            root = root->next[word[i]];
            vector<string> match(root->suggest.size());
            for(int i = root->suggest.size() - 1; i >= 0; i--) {
                match[i] = root->suggest.top();
                root->suggest.pop();
            }
            ans[i] = match;
        }
        return ans;
    }
    
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        /*vector<vector<string>> ans(searchWord.size());
        auto it = products.begin();
        string str = "";
        sort(products.begin(), products.end());
        for(int i = 0; i < searchWord.size(); i++) {
            int lo = lower_bound(products.begin(), products.end(), str + searchWord[i]) - products.begin();
            int hi = lower_bound(products.begin(), products.end(), str + (char)(searchWord[i] + 1)) - products.begin();
            for(int k = lo; k < min(lo + 3, hi); k++) ans[i].push_back(products[k]);
            str += searchWord[i];
        }*/
        TriSol ob;
        
        return ob.search(products, searchWord);
    }
};