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

const int maxn = 100000 + 5;
const int logn = 18;
const int inf = 100000001;
int n;
struct  Edge{
    int to, w;
    Edge(){}
    Edge(int a, int b): to(a), w(b){}
};

struct lowest_lca{
    int T[maxn], L[maxn], W[maxn];
    int P[maxn][logn], MA[maxn][logn], MI[maxn][logn];
    void dfs(vector<vector<Edge> > &g, int root, int pi = -1) {
        if(pi == -1) {
            T[root] = -1;
            L[root] = W[root] = 0;
        }
        for(int i = 0; i < g[root].size(); i++) {
            int nextNode = g[root][i].to;
            if(nextNode != pi) {
                T[nextNode] = root;
                L[nextNode] = L[root] + 1;
                W[nextNode] = g[root][i].w;
                dfs(g, nextNode, root);
            }
        }
    }
    void init(vector<vector<Edge> > &g, int root) {
        dfs(g, root);
        int N = g.size();
        /*for(int i = 0; i < n; i++) {
            cout << L[i] << "  " << W[i] << " " << T[i] << endl;
        }
        cout << N << endl;*/
        for(int i = 0; i < N; i++){
            for(int j = 0; (1 << j) < N; j++) {
                P[i][j] = -1;
                MA[i][j] = -inf;
                MI[i][j] = inf;
            }
        }
        /*for(int i = 0; i < N; i++) {
            for(int j = 0; 1 << j < N; j++) {
                cout << P[i][j] << "  " << MA[i][j] << "  " << MI[i][j] << endl;
            }
        }*/
        for(int i = 0; i < N; i++) {
            P[i][0] = T[i];
            MA[i][0] = MI[i][0] = W[i];
        }
        for(int j = 1; (1 << j) < N; j++) {
            for(int i = 0; i < N; i++) {
                if(P[i][j-1] != -1) {
                    P[i][j] = P[P[i][j-1]][j-1];
                    MA[i][j] = max(MA[i][j-1], MA[P[i][j-1]][j-1]);
                    MI[i][j] = min(MI[i][j-1], MI[P[i][j-1]][j-1]);
                }
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; 1 << j < N; j++) {
                cout << P[i][j] << "  " << MA[i][j] << "  " << MI[i][j] << endl;
            }
        }
    }
    pii query(int p, int q) {
        int tmp, lg;
        int mmin = inf, mmax = -inf;
        if(L[p] < L[q]) {
            tmp = p;
            p = q;
            q = tmp;
        }
        //cout << L[p] << "  " << L[q] << endl;
        for(lg = 1; (1 << lg) <= L[p]; lg++);
        lg--;
        //cout << lg << endl;
        for(int i = lg; i >= 0; i--) {
            if(L[p] - (1 << i) >= L[q]) {
                mmin = min(mmin, MI[p][i]);
                mmax = max(mmax, MA[p][i]);
                //cout << MI[p][i] << "  " << MA[p][i] << endl;
                p = P[p][i];
            }
        }
        if(p == q) {
            return mp(mmin, mmax);
        }
        for(int i = lg; i >= 0; i--) {
            if(P[p][i] != -1 && P[p][i] != P[q][i]) {
                mmin = min(mmin, min(MI[p][i], MI[q][i]));
                mmax = max(mmax, max(MA[p][i], MI[q][i]));
                p = P[p][i];
                q = P[q][i];
            }
        }
        return mp(min(mmin, min(MI[p][0], MI[q][0])), max(mmax, max(MA[p][0], MA[q][0])));
    }

};

lowest_lca lca;
int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cin >> n;
        vector<vector<Edge> > g(n);
        int x, y, c;
        for(int i = 0; i < n-1; i++) {
            cin >> x >> y >> c;
            x--;
            y--;
            g[x].pb(Edge(y, c));
            g[y].pb(Edge(x, c));
        }
        lca.init(g, 0);
        int q;
        cin >> q;
        printf("Case %d:\n", cs);
        while(q--){
            int u, v;
            cin >> u >> v;
            u--, v--;
            pii ans = lca.query(u, v);
            printf("%d %d\n", ans.ff, ans.ss);
        }

    }
    return 0;
}
