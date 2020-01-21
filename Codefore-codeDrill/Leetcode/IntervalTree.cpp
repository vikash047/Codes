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
int mul(int a, int b, int mod = 0) {
    if(mod > 0) {
        return (int)((int64)a*b%mod);
    }
    return a*b;
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

// find the conflicting meetings
struct Meeting {
    int low, high;
    Meeting(int a, int b): low(a), high(b) {}
};

struct IntervalTree{
    Meeting *meeting;
    int mx;
    IntervalTree *left, *right;
};
typedef struct IntervalTree IntervalTree;
typedef struct Meeting Meeting;

class Solution{
    IntervalTree* root;
    IntervalTree* newNode(Meeting* m) {
        IntervalTree* node = new IntervalTree();
        node->meeting = m;
        node->mx = m->high;
        node->left = node->right = NULL;
        return node;
    }
    void insertTree(IntervalTree* root, Meeting* m) {
        if(root == NULL) {
            root = newNode(m);
        }
        if(m->low < root->meeting->low) {
            insertTree(root->left, m);
        } else {
            insertTree(root->right, m);
        }
        if(root->mx < m->high) {
            root->mx = m->high;
        }
    }
    bool doOverlap(Meeting* a, Meeting *b) {
        if(a->low < b->high && b->low < a->high) return true;
        return false;
    }
    Meeting* searchOverlap(IntervalTree* root, Meeting *m) {
        if(root == NULL) return NULL;
        if(doOverlap(root->meeting, m)) {
            return root->meeting;
        }
        if(root->left != NULL && root->left->mx >= m->low) {
            return searchOverlap(root->left, m);
        }
        return searchOverlap(root->right, m);
    }
    public:
    Solution() {
        root = NULL;
    }
    void insert(int a, int b) {
        insertTree(root, new Meeting(a, b));
    }
    vector<int> searchOverlap(int a, int b) {
        Meeting* res = searchOverlap(root, new Meeting(a, b));
        vector<int> ans;
        if(res != NULL) {
            ans.push_back(res->low);
            ans.push_back(res->high);
        }
        return ans;
    }

};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    int n;
    cin >> n;
    vector<vector<int>> in(n, vector<int>(2, 0));
    int x, y;
    for(int i = 0; i < n; i++) {
        cin >> in[i][0] >> in[i][1];
    }
    s.insert(in[0][0], in[0][1]);
    for(int i = 1; i < n; i++) {
        vector<int> o = s.searchOverlap(in[i][0], in[i][1]);
        if(o.size() > 0) {
            cout << "Interval " << in[i][0] << " " << in[i][1] << " conflict with " << o[0] << " " << o[1] << endl;
        }
        s.insert(in[i][0], in[i][1]);
    }

    return 0;
}
