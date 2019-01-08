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
const int MAXN = 30001;
int a[MAXN];
int F[10000001] = {0};
const int BLOCK = 555;
int cnt = 0;
struct node {
    int x, y, i;
};
bool comp(node a, node b) {
    if(a.x/BLOCK != b.x/BLOCK) {
        return a.x/BLOCK < b.x/BLOCK;
    }
    return a.y/BLOCK < b.y/BLOCK;
}

int add(int pos) {
    F[a[pos]]++;
    if(F[a[pos]] == 1) {
        cnt++;
    }
}
int remove(int pos) {
    F[a[pos]]--;
    if(F[a[pos]] == 0) cnt--;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n, q;
    cin >> n;
    //range = (int)sqrt(n);
    fri(i, n) cin >> a[i];
    cin >> q;
    vector<node> query;
    fri(i, q) {
        node q;
        cin >> q.x >> q.y;
        q.x--;
        q.y--;
        q.i = i;
        query.pb(q);
    }
    sort(query.begin(), query.end(), comp);
    int currL = 0;
    int currR = 0;
    vector<int> ans(q, 0);
    fri(i, query.size()) {
        int L = query[i].x;
        int R = query[i].y;
        cout << L << "  " << R << endl;
        while(currL < L) {
            remove(currL);
            currL++;
        }
        while(currL > L) {
            add(currL-1);
            currL--;
        }
        while(currR <= R) {
            add(currR);
            currR++;
        }
        while(currR > R+1) {
            remove(currR-1);
            currR--;
        }
        ans[query[i].i] = cnt;
    }
    fri(i, ans.size()) cout << ans[i] << endl;
    return 0;
}
