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

int n, m;
const int N = 2*100005;
int64 BIT[2][N];

void update(int i, int value, int idx) {
    while(idx <= n) {
        BIT[i][idx] += value;
        idx += (idx & -idx);
    }
}

uint64 sum(int i, int idx) {
    uint64 ans = 0;
    while(idx > 0) {
        ans += BIT[i][idx];
        idx -= (idx & -idx);
    }
    return ans;
}

bool check(int idx) {
    int currSum = sum(0, idx);
    return currSum > m;
}

int binarySearch(int l, int r) {
    while(l < r) {
        int mid = (l + r)/2;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main(int argc, char const *argv[])
{
/* code */
    cin >> n >> m;
    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        update(0, a[i], i);
        update(1, 1, i);
    }
    int ans = 0;
    while(sum(1, n) > 0) {
        int s = sum(0, n);
        int cnt = sum(1, n);
        ans += (m/s)*cnt;
        m = m%s;
        int idx = binarySearch(1, n);
        update(0, -a[idx], idx);
        update(1, -1, idx);
    }
    cout << ans << endl;
    return 0;
}
