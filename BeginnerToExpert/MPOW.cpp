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
const int MAXN = 100001;
const int MOD = 1e9+7;

 vector<vector<int64> > multiplyMatrix(int n, vector<vector<int64> > a, vector<vector<int64> > b) {
    vector<vector<int64> > res(n, vector<int64>(n, 0));
    fri(i, n) {
        fri(j, n) {
            res[i][j] = 0;
            fri(k, n) {
                res[i][j] =  (res[i][j]%MOD+(a[i][k]%MOD*b[k][j]%MOD)%MOD)%MOD;
            }
        }
    }
    return res;
}

void print(vector<vector<int> > a) {
    fri(i, a.size()) {
        fri(j, a[0].size()) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int64> > matrixPower(int n, int b, vector<vector<int64> > mat) {
    vector<vector<int64> > ans(n, vector<int64>(n, 0));
    fri(i, n) ans[i][i] = 1;
    if(b == 1) return mat;
    //cout << b << endl;
    while(b) {
        if(b%2 == 1) {
            //cout << " Hello " << endl;
            ans = multiplyMatrix(n, ans, mat);
           // print(ans);
        }
        b = b >> 1;
        mat = multiplyMatrix(n, mat, mat);
        //cout << " Hello " << endl;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while(t--) {
        int n, p;
        cin >> n >> p;
        vector<vector<int64> > mat(n, vector<int64>(n, 0));
        fri(i, n) {
            fri(j, n) {
                cin >> mat[i][j];
            }
        }
        vector<vector<int64> > ans = matrixPower(n, p, mat);
        fri(i, n){
            fri(j, n){
                printf("%lld ", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
