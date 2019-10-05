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

const int maxn = 100002;

int64 tree[maxn];
const int mod = 1000000000+7;

void update(int x, int val) {
    while(x < maxn) {
        tree[x] = (tree[x]%mod + val%mod)%mod;
        x += (x & -x);
    }
}

int query(int x) {
    int sum = 0;
    while(x > 0) {
        sum = (sum%mod + tree[x]%mod)%mod;
        x -= (x & -x);
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        memset(tree, 0, sizeof(tree));
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        map<int, int> unid;
        int cnt = 2;
        unid[b[0]] = 1;
        for(int i = 1; i < n; i++) {
            if(b[i] != b[i-1]) {
                unid[b[i]] = cnt;
                cnt++;
            }
        }
        for(int i = 0; i < n; i++) {
            update(unid[a[i]], query(unid[a[i]] - 1) + 1);
        }
        cout << "Case " << cs << ": " << query(n)%mod << endl;
    }
    return 0;
}
