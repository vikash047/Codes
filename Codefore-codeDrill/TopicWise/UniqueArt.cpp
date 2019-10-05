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

const int N = 1e5 + 5;
int a[N], BIT[N], ANS[1000000+2];
map<int, int> mapping;
vector<int> pos[N];
int n, q;

struct Data {
    int l, r, idx;
    bool operator<( const Data &other) const {
        return r < other.r;
    }
} query[1000000+2];


void update(int idx, int value) {
    while(idx <= n) {
        BIT[idx] += value;
        idx += (idx & -idx);
    }
}

int sum(int idx) {
    int ans = 0;
    while(idx > 0) {
        ans += BIT[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

int preSum(int l, int r) {
    return sum(r) - sum(l-1);
}

int main(int argc, char const *argv[])
{
/* code */
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mapping[a[i]] = 0;
    }
    int ctr = 0;
    for(auto &it : mapping) {
        mapping[it.ff] = ++ctr;
    }
    // for(auto it : mapping) {
    //     cout << it.ff << "   " << it.ss << endl;
    // }
    cin >> q;
    //cout << q << endl;
    for(int i = 1; i <= q; i++) {
        cin >> query[i].l >> query[i].r;
        //cout << query[i].l << query[i].r << endl;
        query[i].idx = i;
    }
    sort(query + 1, query + q + 1);
    // for(int i = 1; i <= q; i++) {
    //     //cin >> query[i].l >> query[i].r;
    //     cout << query[i].l  << "  "  << query[i].r << endl;
    //     //query[i].idx = i;
    // }
    int r = 1;
    for(int i = 1; i <= n; i++) {
        int rnk = mapping[a[i]];
        //cout << "rank " << rnk << endl;
        pos[rnk].push_back(i);
        int sz = pos[rnk].size();
        // logic is current duplicate make it zero and previous one make it -1.
        // if there is three so last one is -1, make it zero and second one make it -1.
        // always do query current less than right range.
        if(sz >= 1) {
            update(i, 1);
        }
        if(sz >= 2) {
            update(pos[rnk][sz - 2], -2);
        }
        if(sz >= 3) {
            update(pos[rnk][sz - 3], 1);
        }
        while(r <= q && query[r].r == i) {
            int ans = preSum(query[r].l, query[r].r);
          //  cout << "ans " << ans << endl;
            ANS[query[r].idx] = ans;
            r++;
        }
    }
    for(int i = 1; i <= q; i++) {
            cout << ANS[i] << " ";
    }
    cout << endl;

    return 0;
}
