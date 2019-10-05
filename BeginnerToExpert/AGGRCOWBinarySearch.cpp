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

bool findSol(int a[], int n, int c, int mnd) {
    if(n < c) return false;
    int st = a[0]; 
    int currCow = 1;
    frei(i, 1, n-1) {
        if(a[i] -  st >= mnd) {
            currCow++;
            st = a[i];
        }
    }
    //cout << currCow << endl;
    if(currCow < c) return false;
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
   int t;
   cin >> t;
   while(t--) {
       int n, c;
       cin >> n >> c;
       int a[n];
       int mxd = 0;
       int mnd = 1e9+7;
       fri(i, n) {
           cin >> a[i];
           mxd = max(mxd, a[i]);
           mnd = min(mnd, a[i]);
       }
       sort(a, a+n);
       int lo = 1;
       int hi = 10000000001;
       int mid;
       int ans = 1;
       while(lo <= hi) {
           mid = lo + (hi - lo)/2;
           //cout << mid << endl;
           if(findSol(a, n, c, mid)) {
                lo = mid + 1;
                ans = mid;
           }else {
                hi = mid - 1;
           } 
       }
       cout << ans << endl;
   }
    return 0;
}
