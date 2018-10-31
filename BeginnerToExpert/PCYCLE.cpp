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
int n;

vector<int> dfs(int node, int g[], bool visit[]) {
    vector<int> ans;
    int temp = g[node];
    int root = g[node];
    ans.pb(root);
    visit[root] = true;
    while(!visit[g[temp]]) {
        visit[g[temp]] = true;
        ans.pb(g[temp]);
        temp = g[temp]; 
    }
    ans.pb(root);
    return ans;
}
int main(int argc, char const *argv[])
{
    /* code */
    cin >> n;
    map<int, int> indexMapping;
    int g[n];
    int x;
    frei(i, 1, n) {
        cin >> g[i];
        indexMapping[g[i]] = i;
    }
    bool visit[n+1];
    memset(visit, false, sizeof(visit));
    vector<vector<int> > res;
    int count = 0;
    frei(i, 1, n) {
        if(!visit[i]) {
            count++;
            res.pb(dfs(indexMapping[i], g, visit));
        }
    }
    cout << count << endl;
    fri(i, res.size()) {
        fri(j, res[i].size()) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
