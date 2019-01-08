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



int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    int64 a[n+1], b[n+1], pref[n+1], mxel, diff[n+1], diffE[n+1];
    frei(i, 1, n) cin >> a[i];
    frei(i, 1, n) cin >> b[i];
    mxel = a[1];
    frei(i, 2, n) {
        mxel = max(mxel, a[i]);
    } 
    int64 p, q;
    pref[0] = 0;
    frei(i, 1, n) {
        pref[i] = pref[i-1] + b[i];
    }
    p = q = a[1];
    diff[0] = diffE[0] = -LLONG_MAX;
    frei(i, 1, n) {
        diff[i] = max(diff[i-1], a[i] - pref[i]);
    }
    frei(i, 2, n) {
        p = max(p, a[i] + diff[i-1] + pref[i-1]);
    }
    frei(i, 1, n) {
        diffE[i] = max(diffE[i-1], a[i] + pref[i-1]);
    }
    frei(i, 2, n) {
        q = max(q, a[i] + diffE[i-1] + pref[n] - pref[i]);
    }
    int64 ans = mxel;
    if(p > q) {
        if(p > mxel) ans = p;
    }else {
        if(q > mxel) ans = q;
    }
    cout << ans << endl;
    /*cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(uint64) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(bool) << endl;*/
    return 0;
}
