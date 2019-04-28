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

int t;
int mem[1 << 14][2];
string s;
bool solve(int mask, int turn) {
    int &res = mem[mask][turn];
    if(res == -1) {
        int ec = 0;
        char fc = '?';
       for(int i = 0; i < t; i++) {
           if(!(mask & (1 << i))) {
               ec++;
               fc = s[i];
           }
       }
       if(ec == 1) {
           res =  ((turn == 0) == (fc == 'A'));
       } else {
           res = 0;
           for(int i = 0; i < t; i++) {
               int taken = 0;
               for(int j = i; j < t; j++) {
                   if(!(mask && (1 << j))) {
                       taken++;
                       if(ec - taken >= 1) {
                           int new_mask = (mask | ((1 << taken) - 1) << i);
                           res |= !(solve(new_mask, !turn));
                       }
                   } else {
                       break;
                   }
               }
           }
       }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    cin >> s;
    t = s.size();
    memset(mem, -1, sizeof(mem));
    cout << solve(0, 0) << endl;
    return 0;
}
