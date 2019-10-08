#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

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

const int N = 100;
vector<int> g[N];
int n, m;
struct Prop{
    int h, a, d;
} DataSet[2*N];

bool visit[N];
int match[N];

bool dfs(int manId) {
    for(auto it : g[manId]) {
        if(visit[it]) continue;
        visit[it] = true;
        if(match[it] == -1 || dfs(match[it])) {
            match[it] = manId;
            return true;
        }
    }
    return false;
}

int bpm() {
    int cnt  = 0;
    memset(match, -1, sizeof(match));
    for(int i = 1; i <= n; i++) {
        if(g[i].empty()) continue;
        memset(visit, false, sizeof(visit));
        if(dfs(i)) cnt++;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        for(int i = 0; i < N; i++) g[i].clear();
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> DataSet[i].h >> DataSet[i].a >> DataSet[i].d;
        }
        for(int i = n + 1; i <= m + n; i++) {
            cin >> DataSet[i].h >> DataSet[i].a >> DataSet[i].d;
            for(int j = 1; j <= n; j++) {
                if(abs(DataSet[i].h - DataSet[j].h) <= 12 && abs(DataSet[i].a - DataSet[j].a) <= 5 && !(DataSet[i].d^DataSet[j].d)) {
                    g[j].push_back(i - n);    
                }
            }
        }
        int ans = bpm();
        cout << "Case " << test << ": " << ans << endl;
    }
    return 0;
}
