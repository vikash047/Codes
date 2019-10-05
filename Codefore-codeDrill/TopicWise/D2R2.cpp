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

int a[100001][6];
int ans[100001];
multiset<int> s[100001];

void add(int idx, int m) {
    for(int i = 1; i <= m; i++) {
        s[i].insert(a[idx][i]);
    }
}

void remove(int idx, int m) {
    for(int i = 1; i <= m; i++) {
        s[i].erase(s[i].find(a[idx][i]));
    }
} 


int reqd(int m) {
    if(!s[1].size()) {
        return 0;
    }
    int ret = 0;
    for(int i = 1; i <= m; i++) {
        ret += *(--s[i].end());
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    /* code */
    int n, m, k;
    cin >> n >> m >> k;
    int l = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    for(int r = 1; r <= n; r++) {
        add(r, m);
        while(reqd(m) > k) {
            remove(l++, m);
        }
        if(r - l + 1 > res) {
            res = r - l + 1;
            for(int i = 1; i <= m; i++) {
                ans[i] = *(--s[i].end());
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
