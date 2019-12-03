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
const int mod = 1e9 + 7;

// my version of code of this problem
// f(k, state = 0, 1, rem) -> f(k+1, some_state, (rem+some_value)%D);
// some_value if state = 0 , upto 9, if state = 1 -> upto s[k]
// state if some_value < s[k] -> 0, other wise state means if state 0 and some value equal to s[k] pass zero 
// because previous value less than s[k-1] so number is less than s[0..k]
// if state = 1 then means pass 1 even in the case of s[k] == value
int dp[100005][2][101];
int solveM(string s, int index, int state, int rem, int d) {
    if(index == s.size()) {
        if(rem == 0) return 1;
        return 0;
    }
    if(dp[index][state][rem] != -1) {
        return dp[index][state][rem];
    }
    int cnt = 0;
    int limit = state == 0 ? 9 : s[index] - '0';
    for(int i = 0; i <= limit; i++) {
        int ns;
        if(i < s[index]-'0') ns = 0;
        else ns = state;
        add_slef(cnt, solveM(s, index + 1, ns, (rem+i)%d, d), mod);
    }
    dp[index][state][rem] = cnt;
    return cnt;
} 
int solve(string s, int d) {
    int n = s.size();
    memset(dp, -1, sizeof(dp));
    return solveM(s, 0, 1, 0, d);
}

int main(int argc, char const *argv[])
{
    /* code */
    string s;
    cin >> s;
    int d;
    cin >> d;
    cout << solve(s, d) - 1 << endl;
    /* vector<vector<int>> dp(d, vector<int>(2));
    dp[0][0] = 1;
    // dp[sum][sm_already] -> number of ways to choose digit so far such that sum of digit is sum moduel D
    // and smaller aready means we choose already digits which are smaller than k
    for(int i = 0; i < s.size(); i++) {
        vector<vector<int>> new_dp(d, vector<int>(2));
        for(int sum = 0; sum < d; sum++) {
            for(bool sm_already : {false, true}) {
                for(int digit = 0; digit < 10; digit++) {
                    if(digit > s[i] - '0' && !sm_already) {
                        break;
                    }
                    add_slef(new_dp[(sum+digit)%d][sm_already || digit < s[i] - '0'], dp[sum][sm_already], mod);
                }
            }
        }
        dp = new_dp;
    }
    int ans = (dp[0][false] + dp[0][true])%mod;
    ans--;
    if(ans == -1) {
        ans = mod - 1;
    }
    cout << ans << endl;*/
    return 0;
}
