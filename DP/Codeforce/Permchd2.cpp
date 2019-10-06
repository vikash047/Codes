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

int tNode, tEdge, odd = 0;

void dfs(int node, vector<bool> &visit, vector<int> g[]) {
    if(visit[node]) return;
    tNode++;
    visit[node] = true;
    for(int i = 0; i < g[node].size(); i++) {
        int next = g[node][i];
        if(visit[next] == false) {
            tEdge++;
            dfs(next);
        }

    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    vector<int> g[n];
    vector<bool> visit[n];
    int x, y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        visit[i] = false;
    }
    bool f = false;
    fot(int i = 0; i < n; i++) {
        tNode = 0, tEdge = 0;
        if(visit[i]) continue;
        dfs(i);
        if((tEdge/2)%2 == 1 && (tNode*(tNode - 1)) == tEdge && tNode == n) {
            f = true;
            break;
        }
        if((tEdge/2)%2 == 1) odd++;

    }
    if(f) {
        cout << "-1" << endl;
    } else {
        cout << odd << endl;
    }
    return 0;
}
