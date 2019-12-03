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
const int inf = 1e18 + 5;
const int N = 17;
const int nax = 1 << 17;
vector<int64> pre, dp;
int input[nax][nax];
int n;
void calculatePairSum()
{
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if((mask&(1 << i) && (mask & (1 << j)))) {
                    pre[mask] += input[i][j];
                }
            }
        }
    }
}

void rec(int i, vector<int> &notTaken, int scoreSoFar, int mask, int group) {
    if(i == notTaken.size()) {
        dp[mask] = max(dp[mask], (int64)scoreSoFar + pre[group]);
        return;
    }
    rec(i + 1, notTaken, scoreSoFar, mask, group);
    rec(i+1, notTaken, scoreSoFar, mask ^ (1 << notTaken[i]), group ^ (1 << notTaken[i]));
}

void makeGroup() {
    dp.resize(1 << n, -inf);
    pre.resize(1 << n, 0);
    calculatePairSum();
    dp[0] = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        vector<int> notTaken;
        for(int i = 0; i < n; i++) {
            if(!(mask&(1 << i))) {
                notTaken.push_back(i);
            }
        }
        rec(0, notTaken, dp[mask], mask, 0);
    }
    cout << dp[(1 << n) - 1] << endl;
}



int main(int argc, char const *argv[])
{
    /* code */
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    makeGroup();
    return 0;
}
