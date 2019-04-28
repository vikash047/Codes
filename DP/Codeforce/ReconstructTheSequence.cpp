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

int dp[12455][12], next[12455][12], visit[12455][12];

int solve(int pos, int dig, int n, string s) {
    if(pos == n) {
        return  1;
    }
    if(visit[pos][dig]) {
        return dp[pos][dig];
    }
    visit[pos][dig] = 1;
    for(int i = 0; i < 10; i++) {
        if(s[pos] == '=' && dig == i) {
            if(solve(pos + 1, i, n, s)) {
                dp[pos][dig] = 1;
                next[pos][dig] = i;
                return 1;
            }
        } else if(s[pos] == '>' && dig > i) {
            if(solve(pos+1, i, n, s)) {
                dp[pos][dig] = 1;
                next[pos][dig] = i;
                return 1;
            }
        } else if(s[pos] == '<' && dig < i) {
            if(solve(pos+1 , i, n, s)) {
                dp[pos][dig] = 1;
                next[pos][dig] = i;
                return 1;
            }
        } else if(s[pos] == '!' && dig != i) {
            if(solve(pos + 1, i, n, s)) {
                dp[pos][dig] = 1;
                next[pos][dig] = i;
                return 1;
            }
        }
    }
    return 0;
}

string printAns(int n, int dig) {
    string ans = "";
    int i = 0;
    while(i <= n) {
        ans += (char)(dig + '0');
        dig = next[i][dig];
        cout << dig << endl;
        i++;
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    /* code */
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 1; i < 10; i++) {
        if(solve(0, i, n, s)) {
            cout << printAns(n, i) << endl;
        }
    }
    cout << "End" << endl;
    return 0;
}
