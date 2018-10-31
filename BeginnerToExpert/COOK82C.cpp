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
const int MAXN = 1e6+1;
int query[MAXN];
int mxq;
int n, m;

int64 ans[63000005];
int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> m;
    int x;
    queue<int64> q1, q2;
    fri(i, n) {
        cin >> query[i];
    }
    sort(query, query + n);
    fred(i, n-1, 0) {
        q1.push(query[i]);
    }
    for(int i = 1; i <= 63000000; i++) {
        if(q2.empty()) {
            if(q1.empty()) break;
            ans[i] = q1.front();
            q1.pop();
            q2.push(ans[i] >> 1);
        } else if(q1.empty()) {
            ans[i] = q2.front();
            q2.pop();
            q2.push(ans[i] >> 1);
        } else if(q1.front() > q2.front()) {
            ans[i] = q1.front();
            q1.pop();
            q2.push(ans[i] >> 1);
        } else {
            ans[i] = q2.front();
            q2.pop();
            q2.push(ans[i] >> 1);
        } 
    }
    fri(i, m) {
        cin >> x;
        cout << ans[x] << endl;
    }
    
    //solve(pq);
    return 0;
}
