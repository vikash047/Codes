#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
//#define fill(ar, val) memset(ar, val, sizeof(ar))

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

vector<int> F;
void FenwickTreeAdd(int i, int k) {
    while( i < (1 << 18)) {
        F[i] += k;
        i += (i & -i);
    }
}

int GetFenwickTreeSum(int i) {
    int s = 0;
    while(i > 0) {
        s += F[i];
        i -= (i & -i);
    }
    return s;
}

void print() {
    for(int i = 0; i < 12; i++) {
        cout << F[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
   // vector<int> F;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    int m;
    cin >> m;
    F.resize(1 << 18);
    int ans = 0;
    for(int x = 0; x < m; x++) {
        int bal = n;
        fill(F.begin(), F.end(), 0);
        for(int i = 0; i  < n; i++) {
            FenwickTreeAdd(bal, 1);
            print();
            if(v[i] == x) {
                bal++;
            }else {
                bal--;
            }
            cout << "value of array is " << v[i] << endl;
            cout << " Result for " << bal;
            int tt = GetFenwickTreeSum(bal-1);
            cout << "  " << tt << endl;
            ans += tt;
        }
    }
    cout << ans << endl;
    return 0;
}
