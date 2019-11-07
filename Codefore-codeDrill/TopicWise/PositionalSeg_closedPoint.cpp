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

const int N = 5e5 + 5;
map<int, int> idx;
vii q[N];
int64 st[N];
const int inf = 1e9;

void build(int node, int l, int r) {
    if(l == r) {
        st[node] = inf;
        return;
    }
    int m = (l + r)/2;
    build(2*node, l, m);
    build(2*node+1, m + 1, r);
    st[node] = min(st[2*node], st[2*node + 1]);
}

void update(int node, int l, int r, int pos, int val) {
    if(l == r) {
        st[node] = val;
        return;
    }
    int m = (l + r)/2;
    if(pos <= m)
        update(2*node, l, m, pos, val);
    else 
        update(2*node + 1, m + 1, r, pos, val);
    st[node] = min(st[2*node], st[2*node + 1]);
}

int64 query(int node, int l, int r, int x, int y) {
    if(x > r || l > y) return inf;
    if(x <= l && y >= r) {
        return st[node];
    }
    int mid = (l + r)/2;
    int64 left = query(2*node, l, mid, x, y);
    int64 right = query(2*node + 1, mid + 1, r, x, y);
    return min(left, right);
}

int n, m;
int a[N];
int ans[N];
int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int x, y;
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        q[y].push_back(mp(x, i));
    }
    for(int i = 1; i <= n; i++) {
        int prev = idx[a[i]];
        idx[a[i]] = i;
        //cout << prev << endl;
        if(prev) {
            update(1, 1, n, prev, i - prev);
            //for(int i = 1; i <= 12; i++) {
            //    cout << st[i] << " ";
            //}
            //cout << "finish update" << endl;
        }
            
        for(auto it : q[i]) {
            //cout << it.first << endl;
            int64 curans = query(1, 1, n, it.first, i);
            //cout << curans << endl;
            if(curans == inf) curans = -1;
            ans[it.second] = curans;
        }
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    //cout << endl;
    return 0;
}
