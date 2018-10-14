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
#define MAXC 26
int g[maxN][MAXC];
int output[maxN];
int f[maxN];

int buildStateMachine(vector<string> words) {
    int n = words.size();
    memset(g, -1, sizeof(g));
    memset(output, 0, sizeof(output));
    int state = 1;
    for(int i = 0; i < n; i++) {
        int currState = 0;
        for(int j = 0; j < words[i].size(); j++) {
            int ch = words[i][j] - 'a';
            if(g[currState][ch] == -1) g[currState][ch] = state++;
            currState = g[currState][ch];
        }
        output[currState] |= (1 << i);
    }
    for(int i = 0; i < MAXC; i++) {
        if(g[0][i] == -1) g[0][i] = 0;
    }
    queue<int> pq;
    for(int i = 0; i < MAXC; i++) {
        if(g[0][i] > 0) {
            pq.push(g[0][i]);
            f[g[0][i]] = 0;
        }
    }
    while(!pq.empty()) {
        int state = pq.front();
        pq.pop();
        for(int i = 0; i < MAXC; i++) {
            if(g[state][i] != -1) {
                int failure = f[state];
                while(g[failure][i] == -1) {
                    failure = f[failure];
                }
                failure = g[failure][i];
                f[g[state][i]] = failure;
                output[g[state][i]] |= output[failure];
                pq.push(g[state][i]);
            }
        }
    }
    return state;
}

int findWordFromCurrentState(int currStae, char ch) {
    int ans = currStae;
    int i = ch - 'a';
    while(g[ans][i] == -1) {
        ans = f[ans];
    }
    return g[ans][i];
}


void searchWords(vector<string> words, string text) {
    buildStateMachine(words);
    int currState = 0;
    for(int i = 0; i < text.size(); i++) {
        currState = findWordFromCurrentState(currState, text[i]);
        if(output[currState] == 0) continue;
        for(int j = 0; j < words.size(); j++) {
            if(output[currState] & (1 << j)) {
                cout << "foud word " << words[j] << " at position from " << i - words[j].size() + 1 << " to " << i << endl; 
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    string text;
    cin >> text;
    searchWords(v, text);
    return 0;
}