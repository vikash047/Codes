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

/*vector<string> split(string s, string del) {
        vector<string> ans;
        if(s.size() == 0) {
            return ans;
        }
        size_t pos = 0;
        while(pos = (s.find(del) != string::npos)) {
            string str = s.substr(0, pos);
            ans.push_back(str);
            s.erase(0, pos + del.size());
        }
        return ans;
}*/

const int mod = 1e9 + 7;

int main(int argc, char const *argv[])
{
    /* code */
    int n, k; 
    cin >> n >> k;
    // in recursion only k varies so at any child we have some x candies and assing to him some a candies 
    // then waht is ways to assign x - a candies will give resultant ways for assign a candies to this child
    // complexity is n*k^2
    vector<int> dp(k+1);
    dp[0] = 1;
    int up_to;
    // this code have com n*k^2
    /* for(int i = 0; i < n; i++) {
        cin >> up_to;
        for(int used = k; k >= 0; k--) {
            for(int ch = 1; ch <= min(up_to, k - used); ch++) {
                dp[used+ch] += dp[used];
            }
        }
    }*/

    // improve complexit of the above 
    // there is a range L to R update to dp[used] so we can use segment tree and compute the value complexity is log
    // but L = used + 1
    // R = used + min(up_to, k - used)
    // so use prefix sum so L to R increse by x so use s[L] += x && s[R+1] -= x;
    // when we iterate ans use this one make netural after R;
    // so optimize code is 
    vector<int> ps(k + 1);
    for(int i = 0; i < n; i++) {
        cin >> up_to;
        for(int used = k; k >= 0; k--) {
            int L = 1;
            int R = used + min(up_to, k - used);
            int val = dp[used];
            if(L <= R) {
                ps[L] += val;
                if(ps[L] >= mod) {
                    ps[L] -= mod;
                }
                if(R+1 <= k)
                    ps[R+1] -= val;
                    if(ps[R+1] <= 0) {
                        ps[R+1] += mod;
                    }
            }
        }
    }
    int p_s = 0;
    for(int i = 1; i <= k; i++) {
        p_s += ps[i];
        if(p_s >= mod) {
            p_s -= mod;
        } 
        dp[i] += p_s;
        if(dp[i] >= mod) {
            dp[i] -= mod;
        }
    }
    cout << dp[k] << endl;
    return 0;
}
