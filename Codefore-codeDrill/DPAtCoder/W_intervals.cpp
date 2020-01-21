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

const int nax = 2e5 + 5;
const int64 inf = 1e18 + 5;
vector<pii> intervals[nax];

struct S{
    int64 small, lazy;
    void merge(const S &a, const S &b) {
        small = min(a.small, b.small);
        assert(lazy == 0);
    }
    void add(int64 x) {
        small += x;
        lazy += x;
    }
};
vector<S> tree;

const int TYPE_ADD = 1, TYPE_MIN = 2;
void rec(int id, int low, int high, int q_low, int q_high, int type, int64 &x) {
    if(high < q_low || low > q_high) {
        return;
    }
    if(q_low <= low && q_high >= high) {
        if(TYPE_ADD == type) {
            tree[id].add(x);
        } else if(TYPE_MIN == type) {
            x = min(x, tree[id].small);
        } else {
            assert(false);
        }
        return;
    }
    for(int b : {id*2, id*2 + 1}) {
        tree[b].add(tree[id].lazy);
    }
    tree[id].lazy = 0;
    int last_left = (low + high)/2;
    rec(2*id, low, last_left, q_low, q_high, type, x);
    rec(2*id + 1, last_left + 1, high, q_low, q_high, type, x);
    tree[id].merge(tree[id*2], tree[id*2 + 1]);
}

int main(int argc, char const *argv[])
{
    /* code */
    int n, m;
    cin >> n >> m;
    int base = 1;
    int64 total_score = 0;
    while(base <= n + 1) {
        base *= 2;
    }
    int64 wh;
    tree.resize(2*base, {inf, 0});
    vector<vector<int>> in(m, vector<int>(3, 0));
    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        intervals[b].push_back({a, c});
        total_score += c;
    }
    int64 answer = 0;
    wh = 0 - inf;
    rec(1, 0, base - 1, 0, 0, TYPE_ADD, wh);
    for(int i = 1; i <= n + 1; i++) {
        // I want to put 1 here
        for(pii p : intervals[i-1]) {
            wh = p.second;
            rec(1, 0, base - 1, 0, p.first - 1, TYPE_ADD, wh);
        }
        int64 best = inf;
        rec(1, 0, base - 1, 0, base - 1, TYPE_MIN, best);
        if(i == n + 1) {
            answer = best;
        }
        wh = best - inf;
        rec(1, 0, base - 1, i, i, TYPE_ADD, wh);
    }
    total_score = total_score - answer;
    cout << total_score << endl;
    return 0;
}
