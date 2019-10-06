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


struct node {
    int u, v;
} t1[501], t2[501];

int matchR[5001];
int n, m , q;
int seen[501];
bool gr[501][501];

bool bpm(int u) {
    //seen[u] = 1;
    for(int i = 1; i <= m; i++) {
        if(seen[i] == 0 && gr[u][i]) {
            seen[i] = 1;
            if(matchR[i] == 0 || bpm(matchR[i])) {
                matchR[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        //int m, f, v;
        cin >> n >> m >> q;
        memset(matchR, 0, sizeof(matchR));
        memset(gr, false, sizeof(gr));
        n = m = 0;
        char a[10], b[10];
        for(int i = 0; i < q; i++) {
            scanf("%s%s", a, b);
            if(a[0] == 'M') {
                n++;
                sscanf(a, "%*c%d", &t1[n].u);
                sscanf(b, "%*c%d", &t1[n].v);

            } else {
                m++;
                sscanf(a, "%*c%d", &t2[m].u);
                sscanf(b, "%*c%d", &t2[m].v);
            }
        }
        //cout << "Hello" << endl;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(t1[i].u == t2[j].v || t1[i].v == t2[j].u) {
                    gr[i][j] = 1;
                }
            }
        }
        //cout << "Hello" << endl;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            memset(seen, 0, sizeof(seen));
            if(bpm(i)) {
                ans++;
            }
        }
        printf("Case %d: %d\n", test, q - ans);
    }
    return 0;
}
