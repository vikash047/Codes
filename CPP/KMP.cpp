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

vector<int> lps(string pat) {
    int n = pat.size();
    int i = 1;
    int len = 0;
    vector<int> ps(n, 0);
    while(i < n) {
        if(pat[i] == pat[len]) {
            ps[i++] = ++len;
        } else {
            if(len != 0) {
                len = ps[len -1];
            } else {
                ps[i] = 0;
                i++;
            }
        }
    }
    return ps;
}

void kmp(string text, string pat) {
    int n = text.size();
    int m = pat.size();
    if(m > n) return;
    int i = 0, j = 0;
    vector<int> ps = lps(pat);
    while(i < n) {
        if(pat[j] == text[i]) {
            i++;
            j++;
        } 
        if(j == m) {
            cout << "Pattern found at " << i - j << endl;
            j = ps[j - 1];
        } else if(i < n && pat[j] != text[i]) {
            if(j != 0) {
                j = ps[j-1];
            } else {
                i = i + 1;
            }
        }
    }
}



int main(int argc, char const *argv[])
{
    /* code */
    string text, pat;
    cin >> text >> pat;
    return 0;
}
