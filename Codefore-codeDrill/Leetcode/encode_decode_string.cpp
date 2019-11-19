#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define pr pair

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

void add_slef(int &a, int b, int mod = 0) {
    a += b;
    if(mod > 0 && a >= mod) a -= mod;
}

void sub_slef(int &a, int b, int mod = 0) {
    a -= b;
    if(mod > 0 && a < 0) a += mod;
}

vector<string> split(string s, string del) {
        vector<string> ans;
        if(s.size() == 0) {
            return ans;
        }
        size_t pos = 0;
        while((pos = s.find(del)) != string::npos) {
            string str = s.substr(0, pos);
            ans.push_back(str);
            s.erase(0, pos + del.size());
        }
        return ans;
}
struct TrieNode{
    public:
    int index;
    bool flag;
    map<int, struct TrieNode*> next;
};

class Trie {
    TrieNode *root;
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(string s, int index) {
            TrieNode *temp = root;
            for(int i = 0; i < s.size(); i++) {
                if(temp->next.find(s[i]) == temp->next.end()) {
                    temp->next[s[i]] = new TrieNode();
                }
                temp = temp->next[s[i]];
            }
            temp->index = index;
            temp->flag = true;
        }
        TrieNode *getRoot() {
            return root;
        }
};

class EncodeDecode{
    void ecodeTrie(TrieNode* root, string &ans) {
        if(root == NULL) return;
        for(auto it : root->next) {
            ans += "{index: " + to_string(it.second->index) + ",flag :" + (it.second->flag ? "true," : "false,");
            ecodeTrie(it.second, ans);
            ans += "val: ";
            ans.push_back((char)it.first);
            ans += "},";
        }
    }
    map<int, string> getWords(string s) {
        map<int, string> mp;
        return mp;
    }
    public:
    string encode(vector<string> str) {
        Trie ob;
        for(int i = 0; i < str.size(); i++) {
            ob.insert(str[i], i);
        }
        string ans = "";
        for(auto it : ob.getRoot()->next) {
            if(it.second != NULL) {
                ecodeTrie(it.second, ans);
                ans += "val: ";
                ans.push_back((char) it.first);
                ans += "},$#";
            }
        }
        ecodeTrie(ob.getRoot(), ans);
        return ans;
    }
    vector<string> decode(string s) {
        vector<string> ans;
        if(s.size() == 0) return ans;
        vector<string> sp = split(s, "$#");
        cout << endl;
        for(int i = 0; i < sp.size(); i++) {
            string temp;
            if(sp[i][0] != '{') temp += "{" + sp[i];
            if(sp[i][sp.size() - 1] != '}') temp += "}";
            cout << sp[i] << endl;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    vector<string> input(n);
    for(int i = 0; i < n; i++) cin >> input[i];
    EncodeDecode ob;
    string encode = ob.encode(input);
    cout << encode << endl;
    ob.decode(encode);
    return 0;
}
