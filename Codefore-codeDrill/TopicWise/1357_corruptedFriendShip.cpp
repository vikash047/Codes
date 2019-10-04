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

const int N = 1e5+5;
bool visit[N];
int64 dis, notfr;
int n;
vector<int> g[N];

void dfs(int u) {
    visit[u] = true;
    dis++;
    for(auto it : g[u]) {
        if(!visit[it]) {
            dfs(it);
        }
    }
    notfr += (n - dis);
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int tst = 1; tst <= t; tst++) {
        for(int i = 0; i < N; i++) {
            g[i].clear();
            visit[i] = false;
        }
        dis = notfr = 0;
        cin >> n;
        int x, y;
        for(int i = 0; i < n -1; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            //g[y].push_back(x);
        }
        dfs(1);
        cout << "Case " << tst << ": ";
        cout << n-1 << " " << notfr << endl;
    }
    return 0;
}
