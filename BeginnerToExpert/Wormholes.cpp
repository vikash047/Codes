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

const int MAXN = 1e5 + 1;
int n, x, y;
pii in[MAXN];
int V[MAXN], W[MAXN];

int binarySearchLeft(int value) {
    int l = 0;
    int r = x-1;
    while(l <= r) {
        int mid = (l + r)/2;
        //cout << mid << endl;
        if(V[mid] <= value && V[mid+1] > value) {
            return V[mid];
        } else if(V[mid] > value) {
            r = mid - 1;
        }else {
            l  = mid + 1;
        } 
    }
    return -1;
}

int binarySearchRight(int value) {
    int l = 0;
    int r = y-1;
    while(l <= r) {
        int mid = (l + r)/2;
        if(W[mid] >= value && W[mid-1] < value) {
            return W[mid];
        } else if(W[mid] < value) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int solve() {
    sort(in, in + n);
    sort(V, V + x);
    sort(W, W + y);

    int ans = MAXN;
    //cout << " Come here " << endl;
    fri(i, n) {
        int s = in[i].ff;
        int e = in[i].ss;
        //cout << s << "  " << e << endl;
        int v1 = binarySearchLeft(s);
        //cout << v1 << endl;
        if(v1 != -1) {
            int v2 = binarySearchRight(e);
            if(v2 != -1) {
                ans = min(ans, v2 - v1 + 1);
            }
        }
    }
    if(ans == MAXN) return 0;
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> x >> y;
    int a, b;
    fri(i, n) {
        cin >> a >> b;
        in[i] = mp(a, b);
    }
    fri(i, x) cin >> V[i];
    fri(i, y) cin >> W[i];
    cout << solve() << endl;
    return 0;
}
