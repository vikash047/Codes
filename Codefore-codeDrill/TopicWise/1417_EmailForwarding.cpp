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
const int N = 50005;
vector<int> g[N], g2[N];
stack<int> currScc;
int n, current_ssc, ticks;
int disc[N], low[N], stacked[N], ssc[N], nodes[N], dp[N], visit[N];

void targen_ssc(int u) {
    disc[u] = low[u] = ++ticks;
    currScc.push(u);
    stacked[u] = 1;
    for(auto it : g[u]) {
        if(disc[it] == 0) {
            targen_ssc(it);
            low[u] = min(low[u], low[it]);
        } else if(stacked[it]) {
            low[u] = min(low[u], low[it]);
        }
    }
    if(disc[u] == low[u]) {
        //cout << "Hello " << u << endl;
        while(currScc.top() != u) {
            int top = currScc.top();
            //cout << current_ssc << " " << top << endl;
            currScc.pop();
            stacked[top] = 0;
            ssc[top] = current_ssc;
        }
        int top = currScc.top();
        //cout << current_ssc << " " << top << endl;
        currScc.top();
        stacked[top] = 0;
        ssc[top] = current_ssc;
        current_ssc++;
    }
}

void dfs(int u) {
    if(visit[u] == 0) return;
    visit[u] = 1;
    for(auto it : g[u]) {
        if(ssc[u] != ssc[it]) {
            g2[u].push_back(it);
        }
        dfs(it);
    }
}

int findCandidateNode(int u) {
    if(dp[u] != -1) return dp[u];
    int ans = nodes[ssc[u]];
    for(auto it : g2[u]) {
        ans = max(ans, findCandidateNode(it) + nodes[ssc[u]]);
    }
    dp[u] = ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        cin >> n;
        int u, v;
        for(int i = 0; i < N; i++) {
            g[i].clear();
            g2[i].clear();
            disc[i] = low[i] = stacked[i] = ssc[i] = nodes[i] = visit[i] = 0;
            dp[i] = -1;
        }
        current_ssc = ticks = 1;

        for(int i = 1; i <= n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
        }
        for(int i = 1; i <= n; i++) {
            if(disc[i] == 0) {
                targen_ssc(i);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(visit[i] == 0) {
                dfs(i);
            }
        }
        /*for(int i = 1; i <= n; i++) {
            cout << ssc[i] << " ";
        }*/
        //cout << endl << endl;
        for(int i = 1; i <= n; i++) nodes[ssc[i]]++;
        /*for(int i = 1; i <= n; i++) {
            cout << nodes[i] << " ";
        }
        cout << endl;*/
        int ans = -1;
        int node = -1;
        for(int i = 1; i <= n; i++) {
            int t = findCandidateNode(i);
            //cout << i << "  " << t << endl;
            if(ans < t) {
                ans = t;
                node = i;
            }
        }
        cout << "Case " << test << ": " << node << endl;
    }
    return 0;
}
