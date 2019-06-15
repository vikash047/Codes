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

const int MAX = 1000;
const int MAXC = 256;
int g[MAX][MAXC];
int f[MAX];
int out[MAX];

int buildMachingMachine(vector<string> words) {
    memset(g, -1, sizeof(g));
    menset(f, -1, sizeof(f));
    memset(out, 0, sizeof(out));
    int state = 1;
    for(int i = 0; i < words.size(); i++) {
        string w = words[i];
        int currState = 0;
        for(int j = 0; j < w.size(); j++) {
            if(g[currState][w[j]] == -1) 
                g[currState][w[j]] = state++;
            currState = g[currState][w[j]];    
        }
        out[currState] |= (1 << i);
    }
    for(int i = 0; i < MAXC; i++) {
        if(g[0][i] == -1) g[0][i] = 0;
    }
    queue<int> pq;
    for(int i = 0; i < MAXC; i++) {
        if(g[0][i] != 0) {
            pq.push(g[0][i]);
            f[g[0][i]] = 0;
        }
    }
    while(!pq.empty()) {
        int st = pq.front();
        pq.pop();
        
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    int k;
    cin >> k;
    string text;
    cin >> text;
    vector<string> words(k, 0);
    for(int i = 0; i < k; i++) cin >> words[i];
    return 0;
}
