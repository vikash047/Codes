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

// static segment Tree sum of range 

void buildTree(int t[], int n) {
    for(int i = n -1; i > 0; i--) {
        t[i] = t[i << 1] + t[ i << 1 | 1];
    }
}

void modify(int p, int value, int t[], int n) {
    for(t[p += n] = value; p > 1; p >>= 1) {
        t[p >> 1] = t[p] + t[p^1]; // p^1 2*i+1 or 2*i it's dependends on value of p; 
    }
}

int query(int l, int r, int t[], int n) {
    int res = 0;
    for(l += n, r += n; l > r; l >>= 1, r >>= 1) {
        if(l&1) res += t[l++]; // l is close bracket
        if(r&1) res += t[--r]; // r is open bracket in array index
    }
    return res;
}

// modify between a range l to r

void modify(int l, int r, int t[], int n, int value) {
    for(l += n, r += n, l < r; l >>= 1, r >>= 1;) {
        if(l & 1) t[l++] += value;
        if(r & 1) t[--r] += value;
    }
}

// now insteaded we call build function for a range update n long n time we can solve this in o(n)
// Below two operation only valid for range sum or range operation not valid for an assignment operation so 
// we need to think about lazy propagation
void push(int t[], int n) {
    for(int i = 1; i < n; i++) {
        t[i << 1] += t[i];
        t[i << 1 | 1] += t[i];
        t[i] = 0;
    }
}

// single elements access 

int query(int t[], int p, int n) {
    int res = 0;
    for(p += n; p > 1; p >>= 1) {
        res += t[p];
    }
    return res;
}
// Our second case is lazy propagation of segment tree
// lazy propagation tree query is max between range
// we have extra array which could take space of N to store delayed operations

void apply(int t[], int n, int d[], int p, int value) {
    t[p] += value;
    if(p < n) d[p] += value;
}

// Apply delayed operation and propagate this change up to root of p
void buildTree(int t[], int n, int p, int d[]) {
    while(p > 1) {
        p >>= 1;
        t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
    }
}

// Push all operation applied to root tree to down to child nodes

void push(int t[], int n, int d[], int p, int h) {
    for(int s = h; s > 0; s--) {
        int i = p >> s;
        if(d[i] != 0) {
            apply(t, n, d, i << 1, d[i]);
            apply(t, n, d, i << 1 | 1, d[i]);
            d[i] = 0;
        }
    }
}

// Operation inc between range of l to r
void inc(int t[], int n, int l, int r, int value, int d[]) {
    l += n;
    r += n;
    int l0 = l, r0 = r;
    for(; l < r; l >>= 1, r >>= 1) {
        if(l & 1) apply(t, n, d, l++, value);
        if(r & 1) apply(t, n, d, --r, value);
    }
    buildTree(t, n, l0, d);
    buildTree(t, n, r0-1, d);
}

// query between a range l to r

int query(int t[], int n, int d[], int l, int r, int h) {
    int res = 2e-9;
    push(t, n, d, l, h);
    push(t, n, d, r-1, h);
    int l0 = l, r0 = r;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l & 1) res = max(t[l++], res);
        if(r & 1) res = max(t[--r], res);
    }
    return res;
}

// but we can optimaze above push inc buid and query function we can only apply operatin when needed at left and right boundries only

// All of above are complex implementation of the algorithm no we can do simplify all these functions



int main() {

}