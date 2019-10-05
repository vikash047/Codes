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

const int maxn = 1002;
int f[maxn][maxn], tree[maxn][maxn];

void update(int x, int y, int val) {
    while(x <= maxn) {
        int y1 = y;
        while(y1 <= maxn) {
            tree[x][y1] += val;
            y1 += (y1 & (-y1 ));
        }
        x += (x & -x);
    }
}

int getSum(int x, int y) {
    int ans = 0;
    while(x > 0) {
        int y1 = y;
        while(y1 > 0) {
            ans += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return ans;
}

int query(int x1, int y1, int x2, int y2) {
    return getSum(x2, y2) - getSum(x2, y1 - 1) - getSum(x1-1, y2) + getSum(x1 - 1, y1 - 1);
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        int q;
        cin >> q;
        int ty, x1, y1, x2, y2;
        memset(tree, 0, sizeof(tree));
        memset(f, 0, sizeof(f));
        cout << "Case " << cs << ":" << endl;
        for(int i = 0; i < q; i++) {
            cin >> ty;
            if(ty == 0) {
                cin >> x1 >> y1;
                if(f[x1][y1] == 0) {
                    update(x1 + 1, y1 + 1, 1);
                    f[x1][y1] = 1;
                }
            } else {
                cin >> x1 >> y1 >> x2 >> y2;
                cout << query(x1 + 1, y1 + 1, x2 + 1, y2 + 1) << endl;
            }
        }
    }
    return 0;
}
