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

const int N = 1e4 + 5;
vector<int> g[N];
int visit[N], n, cycle;

void dfs(int u) {
    visit[u] = 1;
    for(auto it : g[u]) {
        if(visit[it] == 0) {
            dfs(it);
        } else if(visit[it] == 1) {
            cycle = 1;
            return;
        }
    }
    visit[u] = 2;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        cin >> n;
        string u, v;
        map<string, int> mp;
        int cnt = 1;
        for(int i = 0; i < N; i++) {
            g[i].clear();
            visit[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            cin >> u >> v;
            if(mp.find(u) == mp.end()) mp[u] = cnt++;
            if(mp.find(v) == mp.end()) mp[v] = cnt++;
            g[mp[u]].push_back(mp[v]);
        }
        cycle = 0;
        for(int i = 1; i < cnt; i++) {
            if(visit[i] == 0) {
                dfs(i);
                if(cycle) {
                    break;
                }
            }
        }
        if(cycle) {
            cout << "Case " << test << ": No" << endl;
        } else {
            cout << "Case " << test << ": Yes" << endl;
        }
    }
    return 0;
}
