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

// First Approach using BIT
const int maxn = 2000000;

int tree[maxn];
int ans[maxn];
void update(int x, int val) {
    while(x <= maxn) {
        tree[x] += val;
        x += (x & -x);
    }
}

int query(int x) {
    int sum = 0;
    while(x > 0) {
        sum += tree[x];
        x -= (x & -x);
    }
    return sum;
}

int bs(int val) {
    int idx = 0, d = maxn - 1, tidx;
    while(idx < maxn && d > 0) {
        tidx = idx + maxn;
        if(tidx <= maxn && tree[tidx] <= val) {
            idx = tidx;
            val -= tree[tidx];
        }
        d = d >> 1;
    }
    return idx + 1;
}

int main(int argc, char const *argv[])
{
    /* code */
    for(int i = 1; i <= maxn; i += 2) update(i, 1);
    ans[1] = 1;
    int cnt = 2;
    int prev = 1;
    for(int i = 3; i < maxn; i += 2) {
        int kl = query(i);
        int k = kl - prev;
        if(k) {
            ans[cnt++] = i;
            int p = (maxn/i)*i;
            while(p >= i) {
                int pk = bs(p);
                update(pk, -1);
                p -= i;
            }
            prev = kl;
        }
    }
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        int n;
        cin >> n;
        printf("Case %d: %d\n", cs, ans[n]);
    }
    return 0;
}
