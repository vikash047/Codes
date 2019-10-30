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

const int maxn = 100005;

int64 tree[3*maxn], Lazy[3*maxn];
int n, q;

void init(int node, int left, int right) {
    Lazy[node] = -1;
    tree[node] = 0;
    if(left == right) return;
    int mid = (left + right)/2;
    init(2*node, left, mid);
    init(2*node + 1, mid + 1, right);
}

void LazyPropagate(int idx, int l, int r) {
    if(l != r) {
        tree[idx] = Lazy[idx]*((r - l) + 1);
        Lazy[2*idx] = Lazy[idx];
        Lazy[2*idx + 1] = Lazy[idx];
        Lazy[idx] = -1;
    }
}

void update(int node, int left, int right, int x, int y, int val) {
    if(Lazy[node] != -1) LazyPropagate(node, left, right);
    if(left > y || right < x) return;
    if(x <= left && right <= y) {
        tree[node] = val*((right - left) + 1);
        if(left != right) {
            Lazy[2*node] = val;
            Lazy[2*node+1] = val;
        }
        return;
    }
    int mid = (left + right)/2;
    update(2*node, left, mid, x, y, val);
    update(2*node + 1, mid + 1, right, x, y, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}
int64 query(int node, int left, int right, int x, int y) {
    if(Lazy[node] != -1) LazyPropagate(node, left, right);
    if(left > y || right < x) return 0;
    if(x <= left && y >= right) {
        return tree[node];
    }
    int mid = (left + right)/2;
    int64 res = 0;
    res = query(2*node, left, mid, x, y) + query(2*node + 1, mid + 1, right, x, y);
    return res;
}
int64 gcd(int64 a, int64 b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}


int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cin >> n >> q;
        printf("Case %d:\n",cs);
        init(1, 0, n-1);
        int t, x, y;
        for(int i = 0; i < q; i++) {
            cin >> t >> x >> y;
            if(t==2) {
                int64 range = (y - x) + 1;
                int64 ans = query(1, 0, n-1, x, y);
                if(ans%range == 0) {
                    cout << (ans/range) << endl;
                }else {
                    int64 g = gcd(ans, range);
                    cout << (ans/g) << "/" << (range/g) << endl;
                }
            } else {
                int val;
                cin >> val;
                update(1, 0, n-1, x, y, val);
            }
        }
    }
    return 0;
}
