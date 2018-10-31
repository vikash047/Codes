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

const int MAXN = 200000 + 1;
int n, a[MAXN][3];

int solve() {
    vector<int> v(n);
    fri(i, n) v[i] = i;
    int sol = INT_MAX;
    do {
        int ans = 0;
        int wait = 0;
        fri(i, n) {
            int temp = a[v[i]][0] + a[v[i]][1] + a[v[i]][2];
            temp = temp + wait;
            wait += a[v[i]][0];
            ans = max(ans, temp);
        }
        sol = min(sol, ans);
    } while(next_permutation(v.begin(), v.end()));
    return sol;
}

bool comp(pii a, pii b) {
    return a.ff > b.ff;
}
int solveOptimally() {
    vector<pii> v(n);
    int wait = 0;
    fri(i, n) {
        v[i] = mp(a[i][1] + a[i][2], i);
    }
    sort(v.begin(), v.end(), comp);
    int ans = 0;
    fri(i, n) {
        ans = max(ans, wait + a[v[i].ss][0] + a[v[i].ss][1] + a[v[i].ss][2]);
        wait += a[v[i].ss][0];
    }
    return ans;

}

int main(int argc, char const *argv[])
{
    /* code */
    cin >> n;
    fri(i, n) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    cout << solveOptimally() << endl;
    return 0;
}

