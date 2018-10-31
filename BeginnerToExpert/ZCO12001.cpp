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


int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    int a[n+1];
    frei(i, 1, n) cin >> a[i];
    int open = 0;
    int of = 0, depth = 0, mmatch = 0, mf = 0;
    int currm = 0, currmf = 0;
    frei(i, 1, n) {
        if(a[i] == 1) {
            open++;
            if(open > depth) {
                depth = open;
                of = i;
            }
            currm++;
        } else {
            open--;
            currm++;
            if(currm > mmatch) {
                mmatch = currm;
                mf = i - currm + 1;
            }
            if(open == 0) currm = 0;
        }
    }
    cout << depth << " " << of << " " << mmatch << " " << mf << endl;
    return 0;
}
