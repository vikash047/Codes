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

const int MAXN = 1e5+10;
vector<int> tree[4*MAXN];
int A[MAXN];

class Solve{
    int N;
    void buildTree(int node, int l, int r) {
        if(l == r) {
            tree[node].pb(A[l]);
            return;
        }
        if(l > r || l > N || r < 0) return;
        int mid = l + (r - l) >> 1;
        buildTree(l >> 1, l, mid);
        buildTree(l >> 1 | 1, mid + 1, r);
        merge(node, tree[l >> 1], tree[l >> 1 | 1]);
    }
    void merge(int node, vector<int> left, vector<int> right) {
        int l = 0;
        int r = 0;
        while(l < left.size() && r < right.size()) {
            if(left[l] < right[r]) {
                tree[node].pb(left[l]);
                l++;
            } else {
                tree[node].pb(right[r]);
                r++;
            }
        }
        while(l < left.size()) tree[node].pb(left[l++]);
        while(r < right.size()) tree[node].pb(right[r++]);
    }
    int query(int node, int l, int r, int i, int j, int k) {
        if(i > r || j < l) return;
        if(i == l && r == j) {
            return tree[node][k];
        }
        int mid = (l + (r - l) >> 1);
        if(k > mid) {
            k = k - mid;
            return query(node >> 1 | 1, mid + 1, r, i - mid, j, k);
        } else {
            
        }
    }
    public:
    Solve(int n) {
        this->N = n;
    }
    void buildTree() {

    }

};

int main(int argc, char const *argv[])
{
    /* code */
   int n, m;
    return 0;
}
