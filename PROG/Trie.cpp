#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 5005
#define MAXCHAR 256;

struct Trie {
    bool isEnd;
    map<char, struct Trie*> nextNode;
};

class TrieTree {
    Trie* root;
    public:
    TrieTree() {
        root = new Trie;
    }
    void insert(string s) {
        Trie* temp = root;
        for(int i = 0; i < s.size(); i++) {
            if(temp->nextNode.find(s[i]) != temp->nextNode.end()) {
                temp = (temp->nextNode.find(s[i]))->second;
            }else {
                temp->nextNode[s[i]] = new Trie;
                temp = (temp->nextNode.find(s[i]))->second;
            } 
        }
        temp->isEnd = true;
    }
    bool searchWord(string s) {
        Trie* temp = root;
        for(int i = 0; i < s.size(); i++) {
            if(temp->nextNode.find(s[i]) != temp->nextNode.end()) {
                temp = (temp->nextNode.find(s[i]))->second;
            } else {
                return false;
            }
        }
        return temp->isEnd;
    }
    bool searchPrefix(string s) {
        Trie* temp = root;
        for(int i = 0; i < s.size(); i++) {
            if(temp->nextNode.find(s[i]) != temp->nextNode.end()) {
                temp = (temp->nextNode.find(s[i]))->second;
            } else {
                return false;
            } 
        }
        return true;
    }
};

int main() {
    TrieTree ob;
    ob.insert("vikash");
    ob.insert("meou");
    ob.insert("manmeet");
    ob.insert("choti meou");
    cout << ob.searchWord("vikash") << endl;
    cout << ob.searchPrefix("man") << endl;
    cout << ob.searchWord("komal") << endl;
    cout << ob.searchPrefix("eou") << endl;
    return 0;
}