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
     int n, h;
    cin >> n >> h;
    int a[n];
    fri(i, n) cin >> a[i];
    int c;
    int curr = 0;
    bool box = false;
    while(true) {
        cin >> c;
        if(c == 0) break;
        if(c == 1) {
            curr = curr > 0 ? curr - 1 : curr;
        } else if(c == 2) {
            curr = curr <  n - 1 ? curr + 1 : curr;
        } else if(c == 3) {
            if(a[curr] > 0 && !box) {
                box = true;
                a[curr]--;
            }
        } else if(c == 4) {
            if(a[curr] < h && box) {
                a[curr]++;
                box = false;
            }
        }
    }
    fri(i, n) cout << a[i] << " ";
    cout << endl;
    return 0;
}