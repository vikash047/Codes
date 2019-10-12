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

const int N = 105;
int choices[2*N][N], freeM[N], freeW[N];
int n;

bool choicePriority(int assign, int m, int cmp) {
    int assignrnk;
    int mrnk;
    for(int i = 1; i <= n; i++) {
        if(choices[cmp][i] == assign) {
            assignrnk = i;
        }
        if(choices[cmp][i] == m) {
            mrnk = i;
        }
    }
    return (assignrnk < mrnk);
}

void solve() {
    memset(freeM, -1, sizeof(freeM));
    memset(freeW, -1, sizeof(freeW));
    int freecnt = n;
    while(freecnt > 0) {
        int m;
        for(int i = 1; i <= n; i++) {
            if(freeM[i] == -1) {
                m = i;
                break;
            }
        }
        for(int i = 1; i <= n && freeM[m] == -1; i++) {
            int cmp = choices[m][i];
            if(freeW[cmp - n] == -1) {
                freeW[cmp-n] = m;
                freeM[m] = cmp-n;
                freecnt--;
            } else {
                int assigned = freeW[cmp-n];
                if(!choicePriority(assigned, m, cmp)) {
                    freeM[m] = cmp - n;
                    freeW[cmp - n] = m;
                    freeM[assigned] = -1;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << "(" << i << " " << freeM[i] + n << ")" << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        cin >> n;
        for(int i = 1; i <= 2*n; i++) {
            for(int j = 1; j <= n; j++) cin >> choices[i][j];
        }
        cout << "Case " << test << ": ";
        solve();
    }
    return 0;
}
