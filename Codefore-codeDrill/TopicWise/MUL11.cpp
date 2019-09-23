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

const int N = 100005;
int n, m;
vector<int> dcanUse;
vector<pii> G[N];
int parent[N];
int value[N];

void buildGraph(int n) {
    for(int i = 0; i < N; i++) G[i].clear();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < dcanUse.size(); j++) {
            int next = (i * 10 + dcanUse[j])%n;
            G[i].push_back(mp(next, dcanUse[j]));
        }
    }
}
void bfs(int n) {
    bool visit[n];
    memset(visit, false, sizeof(visit));
    memset(parent, -1, sizeof(parent));
    buildGraph(n);
    queue<int> pq;
    for(int i = 1; i < 10; i++) {
        pq.push(i);
        visit[i] = true;
        value[i] = i;
    }
    while(!pq.empty()) {
        int node = pq.front();
        pq.pop();
        for(auto it : G[node]) {
            if(!visit[it.ff]) {
                pq.push(it.ff);
                visit[it.ff] = true;
                parent[it.ff] = node;
                value[it.ff] = it.ss;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int test = 1;
    while(cin >> n >> m) {
        if(n == 0) break;
        set<int> notUse;
        int k;
        for(int i = 0; i < m; i++) {
            cin >> k;
            notUse.insert(k);
        }
        dcanUse.clear();
        bool f = false;
        cout << "Case "<< test++ << ": ";
        for(int i = 0; i < 10; i++) {
            if(notUse.find(i) == notUse.end()) {
                dcanUse.push_back(i);
                if(i != 0 && i%n == 0) {
                    f = true;
                    cout << i << endl;
                    break;
                }
            }
        }
        if(f) {
            continue;
        }
        bfs(n);
        if(parent[0] == -1) {
            cout << "-1" << endl;
        } else {
            int curr = 0;
            vector<int> ans;
            while(curr != -1) {
                ans.push_back(value[curr]);
                curr = parent[curr];
                //cout << curr << endl;
            }
            reverse(ans.begin(), ans.end());
            for(auto &it : ans) {
                cout << it;
            }
            cout << endl;
        }
    }
    return 0;
}
