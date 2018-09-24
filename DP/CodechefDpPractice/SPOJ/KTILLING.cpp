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

uint64 f[1001];
uint64 g[1001];
uint64 h[1001];

int main() {
    int t;
    cin >> t;
    f[0] = 1;
        f[1] = 1;
        g[0] = 1;
        g[1] = 2;
        h[0] = h[1] = 1;
        frei(i, 2, 1000) {
            f[i] = f[i-1] + f[i-2] + 2*g[i-2] + h[i-2];
            g[i] = f[i] + g[i-1];
            h[i] = f[i] + h[i-2];       
        }
    int cas = 1;    
    while(t--) {
        int w;
        cin >> w;
        cout << cas << " " << f[w] << endl;
        cas++;
    }
}