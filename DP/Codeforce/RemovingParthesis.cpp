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

int solve(string s) {
    if(s == "") return 1;
    int res = 0;
    int d = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            d++;
        } else {
            d--;
            if(i == s.size() - 1) {
                res += solve(s.substr(1, s.size()));
            }
            string nex = s.substr(1, i) + s.substr(i + 1);
            res + solve(next);
            if(d == 0) break;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    string s;
    cin >> s;
    return 0;
}
