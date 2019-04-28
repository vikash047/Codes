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

const int MAXN = 507;
vector<int> G[MAXN];
bool check[MAXN];
int matchR[MAXN];
int n;
int sx[MAXN];
int sy[MAXN];
int ex[MAXN];
int ey[MAXN];
int st[MAXN];
int et[MAXN];

void init() {
    for(int i = 0; i <= n; i++) G[i].clear();
    cin >> n;
    for(int i = 0; i < n; i++) {
        int h, m;
        scanf("%d:%d %d %d %d %d", &h, &m, &sx[i], &sy[i], &ex[i], &ey[i]);
        st[i] = h*60 + m;
        //cout << h << "  " << m << endl;
        et[i] = st[i] + abs(ex[i] - sx[i]) + abs(ey[i] - sy[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(st[j] > (et[i] + abs(sx[j] - ex[i]) + abs(sy[j] - ey[i]))) {
                G[i].push_back(j);
            }
        }
    }

}

bool bpm(int u) {
    for(int i = 0; i < G[u].size(); i++) {
        int nextNode = G[u][i];
        if(!check[nextNode]) {
            check[nextNode] = true;
            if(matchR[nextNode] == -1 || bpm(matchR[nextNode])) {
                matchR[nextNode] = u;
                return true;
            }
        }
    }
    return false;
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < G[i].size(); j++) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        init();
        print();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            memset(check, false, sizeof(check));
            if(bpm(i)) {
                ans++;
            }
        }
        printf("Case %d: %d\n", test, n - ans);
    }
    return 0;
}
