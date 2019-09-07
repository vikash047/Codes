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



int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> pokeManCatrds;
    for(int i = 0; i < s.size(); i++) {
        pokeManCatrds.insert(s[i]);
    }
    int cnt = pokeManCatrds.size();
    int st = 1, end = 1;
    int ans = INT_MAX;
    int unct = 0;
    int lastIndex[256];
    memset(lastIndex, 0, sizeof(lastIndex));
    //cout << cnt << endl;
    for(int i = 1; i <= s.size(); i++) {
        if(!lastIndex[s[i-1]]) {
            unct++;
        }
        lastIndex[s[i-1]]++;
        while(st < i && lastIndex[s[st-1]] > 1) {
            lastIndex[s[st-1]]--;
            st++;
        }
        if(unct == cnt) {
            ans = min(ans, i - st + 1);
        }
    }
    ans = ans != INT_MAX ? ans : 0;
    cout << ans << endl;
    return 0;
}
