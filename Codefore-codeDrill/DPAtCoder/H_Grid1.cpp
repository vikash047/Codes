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



int main(int argc, char const *argv[])
{
    /* code */
    int n, m;
    int mod = 1e9+7;
    cin >> n >> m;
    int a[n+1][m+1];
    char ch;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> ch;
            if(ch == '.') {
                a[i][j] = 0;
            } else {
                a[i][j] = -1;
            }
        }
    }
    a[1][1] = 1;
    for(int i = 2; i <= m; i++) {
        if(a[1][i] >= 0) {
            a[1][i] = a[1][i-1] > 0 ? 1 : 0;
        }
    }
    for(int i = 2; i <= n; i++) {
        if(a[i][1] >= 0) {
            a[i][1] = a[i-1][1]> 0 ? 1 : 0;
        }
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            if(a[i][j] >= 0) {
                a[i][j] = ((a[i-1][j] > 0 ? a[i-1][j] : 0)%mod + (a[i][j-1] > 0 ? a[i][j-1] : 0)%mod)%mod;
                //cout << a[i][j] << endl;
            }
        }
    }
    cout << a[n][m] << endl;
    return 0;
}
