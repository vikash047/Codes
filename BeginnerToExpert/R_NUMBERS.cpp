/*solution for n = 2
There are 33 numbers:
02, 03, 05, 07  -> 4 start with 0
11, 12, 14, 16  -> 4            1
21, 23, 25, 29  -> 4            2
32, 34, 38      -> 3            3
41, 43, 47, 49  -> 4            4
52, 56, 58      -> 3            5
61, 65, 67      -> 3            6
74, 76          -> 2            7
83, 85, 89      -> 3            8
92, 94, 98      -> 3            9*/

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

const int MOD = 1e9+7;
int F1[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};
int F2[10] = {4, 4, 4, 3, 4, 3, 3, 2, 3, 3};

int A[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {0, 1, 1, 0, 1, 0, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
                {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                {0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
                {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
                {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
                {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
                {0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
                {0, 0, 1, 0, 1, 0, 0, 0, 1, 0}};

void print(vector<vector<int64> > a) {
    fri(i, a.size()) {
        fri(j, a[0].size()) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int64> > multiply(vector<vector<int64> > a, vector<vector<int64> > b) {
    vector<vector<int64> > res(a.size(), vector<int64>(b[0].size(), 0));
    fri(i, a.size()) {
        fri(j, b[0].size()) {
            res[i][j] = 0;
            fri(k, b.size()) {
                res[i][j] = (res[i][j]%MOD + ((a[i][k]%MOD)*(b[k][j]%MOD))%MOD)%MOD;
                res[i][j] = res[i][j]%MOD;
            }
        }
    }
   // print(res);
    return res;
}

vector<vector<int64> > matrixPower(int n) {
    vector<vector<int64> > mat(10, vector<int64>(10, 0));
    fri(i, 10) {
        fri(j, 10) mat[i][j] = A[i][j];
    }
    if(n == 1) return mat;
    vector<vector<int64> > ans(10, vector<int64>(10, 0));
    fri(i, 10) ans[i][i] = 1;
    
    while(n) {
        if(n%2 == 1) {
            ans = multiply(ans, mat);
        }
        n = n >> 1;
        mat = multiply(mat, mat);
    }
    return ans;
} 

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n > 2) {
            vector<vector<int64> > POWMAT = matrixPower(n-2);
            vector<vector<int64> > FV;
            // fri(i, 10) {
            //     FV.pb(vector<int64>(1, F2[i]));
            // }
            //print(FV);
            //vector<vector<int64> > ans = multiply(POWMAT, FV);
            int64 res = 0;
            fri(i, POWMAT.size()) {
                fri(j, POWMAT.size()) {
                    res += ((POWMAT[i][j]%MOD)*(F2[j]%MOD))%MOD;
                }
            }
            cout << res << endl;
        } else {
            if(n == 1) {
                cout << 4 << endl;
            } else if(n == 2) {
                cout << 33 << endl;
            }
        }
    }
    return 0;
}
