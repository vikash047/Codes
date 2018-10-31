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

const int MAXN = 301;
int n, k;
int ans = 1;
void dfs(int s, vector<int> adj[], bool visit[]) {
    visit[s] = true;
    fri(i, adj[s].size()) {
        int next = adj[s][i];
        if(!visit[next]) {
            ans++;
            dfs(next, adj, visit);
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> k;
    vector<vector<int> > input;
    fri(i, n) {
        int x;
        cin >> x;
        vector<int> temp(x, 0);
        fri(j, x) cin >> temp[j];
        sort(temp.begin(), temp.end());
        input.pb(temp);
    }
    vector<int> adj[n];
    fri(i, n) {
        fri(j, n) {
            if(i != j) {
                int x = 0;
                int y = 0;
                int z = 0;
                while(x < input[i].size() && y < input[j].size()) {
                    if(input[i][x] < input[j][y]) x++;
                    else if(input[i][x] > input[j][y]) y++;
                    else {
                        x++;
                        y++;
                        z++;
                    }
                }
                if(z >= k) {
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
        }
    } 
    bool visit[n];
    memset(visit, false, sizeof(visit));
    dfs(0, adj, visit);
    cout << ans << endl;
    return 0;
}
