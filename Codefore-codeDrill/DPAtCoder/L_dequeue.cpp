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

const int nax = 3003;
int64 dp[nax][nax];

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    // new conscept of diagnol dp filling from last to upper
    // f(l, r) = max(al - f(l+1, r), ar - f(l, r-1))
    for(int l = n -1; l >= 0; l--) {
        for(int r = l; r < n; r++) {
            if(l == r) {
                dp[l][r] = a[l];
            } else {
                dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
