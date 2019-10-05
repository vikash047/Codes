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
#define pr pair

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 5005

const int MAXN = 100001;
vector<pr<int, pr<int, int> > > adj[MAXN];
int sumA, sumB;
bool visit[MAXN];
priority_queue<pr<pr<double, int>, pr<int, int> > > pq;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void process(int u, double c) {
    visit[u] = true;
    int a, b, v;
    double temp;
    
    fri(i, adj[u].size()) {
        v = adj[u][i].first;
        if(visit[v]) continue;
        a = adj[u][i].second.first;
        b = adj[u][i].second.ss;
        temp = (double)a - b*c;
        pq.push(mp(mp(temp, v), mp(a, b)));
    }
}

bool mst(double c) {
    double max_cost = 0.0, w;
    sumA = sumB = 0;
    int a, b, v;
    memset(visit, false, sizeof(visit));
    process(0, c);
    while(!pq.empty()) {
        pr<pr<double, int>, pr<int, int> > p = pq.top();
        pq.pop();
        w = p.ff.ff;
        v = p.ff.ss;
        a = p.ss.ff;
        b = p.ss.ss;
        if(!visit[v]) {
            max_cost += w;
            sumA += a;
            sumB += b;
            process(v, c);
        }
    }
    if(max_cost >= 0) return true;
    return false;
}


int main(int argc, char const *argv[])
{
    /* code */
    int n, m;
    cin >> n >> m;
    int u, v, a, b;
    fri(i, n) {
        cin >> u >> v >> a >> b;
        adj[u].pb(mp(v, mp(a,b)));
        adj[v].pb(mp(u, mp(a, b)));
    }
    double mid, lo = 0.0, hi = 100000000.0;
    
    for(int i =1 ;i<=65 ; i++) {
        mid = lo + (hi-lo)/2.0 ;
        if(mst(mid)) lo = mid ;
        else hi = mid ;
    }
    mst(lo);
    int g = gcd(sumA, sumB);
    printf("%d/%d\n", sumA/g, sumB/g);
    return 0;
}
