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

vector<int> merge(vector<int> a, vector<int> b, int n1, int n2) {
    vector<int> temp(n1+n2);
    int l = 0; 
    int r = 0;
    while(l < n1 && r < n2) {
        if(a[l] < b[r]) {
            temp[l] = a[l++];
        }else {
            temp[r] = b[r++];
        } 
    }
    while(l < n1) temp[l] = a[l++];
    while(r < n2) temp[r] = b[r++];
    return temp;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    map<int, int> mp;
    int vl;
    vector<int> a1(n1, 0), a2(n2, 0), a3(n3, 0);
    fri(i, n1) cin >> a1[i];
    fri(i, n2) cin >> a2[i];
    fri(i, n3) cin >> a3[i];
    vector<int> tt = merge(a1, a2, n1, n2);
    tt = merge(tt, a3, tt.size(), n3);
    vector<int> ans;
    int cnt = 0;
    frei(i, 1, tt.size()) {
        if(tt[i] == tt[i-1]) {
            cnt++;
        } else {
            if(cnt > 0) ans.pb(tt[i-1]);
            cnt = 0;
        }
    }
    cout << ans.size() << endl;
    fri(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}
