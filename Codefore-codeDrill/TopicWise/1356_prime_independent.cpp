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

const int N = 5e5+5;
int totalPrime = 0, prime[N], check[N];
void computePrimeNumbers() {
    //prime[totalPrime++] = 2;
    for(int i = 2; i*i < N; i++) {
        if(check[i] == 0) {
            //prime[totalPrime++] = i;
            for(int j = i*i; j < N; j += i) check[j] = 1;
        }
    }
    for(int i = 2; i < N; i++) {
        if(check[i] == 0) prime[totalPrime++] = i;
    }
}

const int inf = 1e9;
int n, in[N], mx, fnd[N], dist[N], matchV[N], matchU[N];
vector<int> adj[N];

void clear() {
    for(int i = 0; i < N; i++) {
        in[i] = 0;
        fnd[i] = -1;
        adj[i].clear();
        matchV[i] = matchU[i] = 0;
        dist[i] = inf;
    }
}

bool bfs() {
    queue<int> pq;
    for(int i = 1; i <= n; i++) {
        if(matchU[i] == 0) {
            //cout << " Push " << i << endl;
            pq.push(i);
            dist[i] = 0;
        } else {
            dist[i] = inf;
        }
    }

    dist[0] = inf;

    while(!pq.empty()) {
        int node = pq.front();
        pq.pop();
        if(node == 0) continue;
        if(dist[node] < dist[0]) {
            //cout << " Come in " << node << endl;
            for(auto it : adj[node]) {
                if(dist[matchU[it]] == inf) {
                    dist[matchU[it]] = dist[node] + 1;
                    pq.push(matchU[it]);
                }
            }
        }
    }
    return dist[0] != inf;
}


bool visit[N];

bool dfs(int u) {
    if(u == 0) return true;
    for(auto it : adj[u]) {
        cout << "Node " << it << endl;
        //if(visit[it]) continue;
        if(dist[matchU[it]] = dist[u] + 1) {
            if(dfs(matchU[it])) {
                matchU[it] = u;
                matchU[u] = it;
                return true;
            }
            
        }
    }
    dist[u] = inf;
    return false;
}

int hopKorp() {
    int matching = 0;
    while(bfs()) {
       // cout << "Hello " << endl;
       memset(visit, false, sizeof(visit));
        for(int i = 1; i <= n; i++) {
            if(matchU[i] == 0 && dfs(i)) {
                //cout << "Node matched with " << matchU[i] << " node " << i << endl;
                ++matching;
            }
        }
    }
    return matching;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    computePrimeNumbers();
    for(int test = 1; test <= t; test++) {
        clear();
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> in[i];
            if(mx < in[i]) mx = in[i];
            fnd[in[i]] = i;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < totalPrime; j++) {
                int y = prime[j]*in[i];
                if(y > mx) break;
                if(fnd[y] != -1) {
                    adj[i].push_back(fnd[y]);
                    adj[fnd[y]].push_back(i);
                }
            }
        }
        int res = hopKorp();
        cout << "Case " << test << ": " << (n - res) << endl;
    }
    return 0;
}
