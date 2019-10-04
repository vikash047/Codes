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
const int N = 3*1e5;
vector<int> g[N];
int vis[N], vis2[N][2], par[N][2], n, m, s;

bool findLoop(int u) {
    if(vis[u] == 1) {
        return 1;
    }
    if(vis[u] == 2) {
        return 0;
    }
    vis[u] = 1;
    for(auto it : g[u]) {
        //if(par == it) continue;
        if(findLoop(it)) {
            return 1;
        }
    }
    vis[u] = 2;
    return 0;
}
int dfs2(int u, int turn) {
    vis2[u][turn] = 1;
    if(g[u].size() == 0) {
        if(turn == 1) {
            return u;
        }
        return 0;
    }
    for(auto it : g[u]) {
        if(!vis2[it][turn^1]) {
            par[it][turn^1] = u;
            int last = dfs2(it, turn^1);
            if(last > 0) {
                return last;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> m;
    int u, v, k;
    for(int i = 1; i <= n; i++) {
        cin >> k;
        for(int j = 0; j < k; j++) {
            cin >> v;
            g[i].push_back(v);
        } 
    }
    cin >> s;
    //cout << s << endl;
    int last = dfs2(s, 0);
    //cout << last << endl;
    if(last > 0) {
        vector<int> ans;
        ans.push_back(last);
        int turn = 1;
        // for(int i = 1; i <= n; i++) {
        //     cout << par[i][0] << "  " << par[i][1] << endl;
        // }
       do {
            last = par[last][turn];
            //cout << last << endl;
            ans.push_back(last);
            turn = turn ^ 1;
            //cout << last << "  " << turn << endl;
            //if(last == s) break;
        } while(!(last == s && turn == 0));
        cout << "Win" << endl;
        reverse(ans.begin(), ans.end());
        for(auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    } else if(findLoop(s)) {
        cout << "Draw" << endl;
    } else {
        cout << "Lose" << endl;
    }
    return 0;
}
