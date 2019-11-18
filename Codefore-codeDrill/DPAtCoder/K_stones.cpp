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
    int n , k;
    cin >> n >> k;
    // if there is x stones and first player choose x - a1, x - a2, x-an then these positions are winning position of
    // player 2 then x is winning position of 1 otherwise x is winning positions of 2.
    // means lets assume at stone x if i chose a stones from x and  at position x - a is player 2 then 1st win.

    vector<int> moves(n + 1);
    for(int i = 1; i <= n; i++) cin >> moves[i];
    vector<int> dp(k+1, 2);
    for(int i = 1; i <= k; i++) {
        for(int m = 1; m <= n; m++) {
            if(moves[m] > i) continue;
            if(dp[i - moves[m]] == 2) {
                dp[i] = 1;
            }
        }
    }
    string ans = dp[k] == 1 ? "First" : "Second";
    cout << ans << endl; 
    return 0;
}
