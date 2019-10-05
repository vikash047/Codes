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

const int MAXN = 2*1e5;
const int MAXC = 256;
int TF[MAXN][MAXC];


// m*noofchar complexity

void computeTF(string pat) {
    int m = pat.size();
    for(int i = 0; i < MAXC; i++) TF[0][i] = 0;
    TF[0][pat[0]] = 1;
    int lps = 0, x;
    for(int state = 1; state <= m; state++) {
        for(x = 0; x < MAXC; x++) {
            TF[state][x] = TF[lps][x];
        }
        TF[state][pat[state]] = state + 1;
        if(x < m) lps = TF[lps][pat[x]];
    }
}
// m^3 complexity
int getNextState(string pat, int state, int x, int m) {
    if(state < m && pat[state] == x) {
        return state + 1;
    }
    int ns, i;
    for(ns = state; ns > 0; ns--) {
        if(pat[ns] == x) {
            for(i = 0; i < ns - 1; i++) {
                if(pat[i] != pat[state - ns + 1 + i]) break;
            }
        }
        if(i == ns - 1) return ns;
    }
    return 0;
}

void search(string pat, string text) {
    int m = pat.size();
    int n = text.size();
    computeTF(pat);
    int state = 0;
    for(int i = 0; i < n; i++) {
        state = TF[state][text[i]];
        if(state == m) {
            cout << " found in the text at " << i - m + 1 << endl;
        }
    }
}

void compute(string s) {
    int m = s.size();
    int state, x;
    for(state = 0; state <= m; state++ ) {
        for(int x = 0; x < MAXC; x++) {
            TF[state][x] = getNextState(s, state, x, m);
        }
    }    
}

int main(int argc, char const *argv[])
{
    /* code */
     string pat, text;
    cin >> pat >> text;
    search(pat, text);
    return 0;
}