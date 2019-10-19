#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

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


map<int, int> active;
int n, q, ans;
void init() {
    active[-1] = -1;
    active[2e9] = 2e9;
    active[1] = n;
}

void add(int L, int R) {
    active[L] = R;
    ans += (R - L + 1);
}

void remove(int L, int R) {
    int remove = 0;
    auto it = active.lower_bound(L);
    it--;
    if(it->ss >= L) {
        active[L] = it->ss;
        it->ss = L - 1;
    }
    it++;
    while(it->ff <= R) {
        if(it->ss > R) {
            remove += (R - it->ff + 1);
            active[R+1] = it->ss;
        } else {
            remove += it->ss - it->ff + 1;
        }
        auto it2 = it;
        it++;
        active.erase(it2);
    }
    ans -= remove;
}

int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> q;
    init();
    ans = n;
    for(int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        remove(l, r);
        if(k == 2) {
            add(l, r);
        } 
        cout << ans << endl;
    }
    //cout << ans << endl;
    return 0;
}
