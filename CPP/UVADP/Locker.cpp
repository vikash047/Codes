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
int a[maxN];
int b[maxN];
int dp[maxN][15][15][15];
int l;
int dfs(int curr, int x, int y, int z) {
    if(curr >= l) return 0;
    int &ret = dp[curr][x][y][z];
    if(ret != -1) return ret;
    int ans = INT_MAX;
    int t;
    if(x > b[curr]) {
        t =  b[curr] + 10 - x;
    } else {
        t = b[curr] - x;
    }
    for(int i = 0; i <= t; i++) {
        for(int j = 0; j <= i; j++) {
            ans = min(ans, dfs(curr+1, (y+j)%10, (z+j)%10, a[curr+3]) + t);
        }
    }
    if(x >= b[curr]) {
        t = x - b[curr];
    } else {
        t = x + 10 - b[curr];
    }
    for(int i = 0; i <= t; i++) {
        for(int j = 0; j <= i; j++) {
            ans = min(ans, dfs(curr + 1, (y - j + 10)%10, (z - j + 10)%10, a[curr+1]) + t);
        }
    }
    ret = ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    string s1, s2;
    while(cin >> s1 >> s2) {
        l = s1.size();
        //cout << l << endl;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < l; i++) {
            a[i] = s1[i] - '0';
            b[i] = s2[i] - '0';
        }
        a[l] = a[l+1] = b[l] = b[l+1] = 0;
        int res = dfs(0, a[0], a[1], a[2]);
        cout << res << endl;
    }
    return 0;
}
