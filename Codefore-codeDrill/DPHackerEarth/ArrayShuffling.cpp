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

void add_slef(int &a, int b, int mod = 0) {
    a += b;
    if(mod > 0 && a >= mod) a -= mod;
}

void sub_slef(int &a, int b, int mod = 0) {
    a -= b;
    if(mod > 0 && a < 0) a += mod;
}
int mul(int a, int b, int mod = 0) {
    if(mod > 0) {
        return (int)((int64)a*b%mod);
    }
    return a*b;
}

vector<string> split(string s, string del) {
        vector<string> ans;
        if(s.size() == 0) {
            return ans;
        }
        size_t pos = 0;
        while((pos = s.find(del)) != string::npos) {
            string str = s.substr(0, pos);
            ans.push_back(str);
            s.erase(0, pos + del.size());
        }
        return ans;
}

int dp[200][200][200];
int per[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

int solve(int i, int a, int b, int n, vector<vector<int>>& in) {
    if(i > n) return 0;
    if(dp[i][a][b] != -1) return dp[i][a][b];
    int cc = 0;
    int f[2] = {a, b};
    for(int ii = 0; ii < 6; ii++) {
        for(int mask = 0; mask < 7; mask++) {
            int cnt = 0, c1 = 0;
            int f2[2] = {a, b};
            for(int j = 0; j < 2; j++) {
                if((mask & (1 << j)) > 0) {
                    if(in[per[ii][j]][i] >= f[j]) {
                        f2[j] = in[per[ii][j]][i];
                        cnt++;
                    }
                }
            }
            cc = max(cc, cnt + solve(i + 1, f2[0], f2[1], n, in));
        }
    }
    dp[i][a][b] = cc;
    return cc;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    vector<vector<int>> in(3, vector<int>(n+1, 0));
    for(int i = 0; i < 3; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> in[i][j];
        }
    }
    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++) {
            for(int k = 0; k < 200; j++) {
                dp[i][j][k] = -1;
            }
        }
    }
    int ans = solve(1, 0, 0, n, in);
    return 0;
}
