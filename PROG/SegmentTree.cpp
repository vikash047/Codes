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

void buildTree(int t[], int n, int p, int d[]) {
    while(p > 1) {
        p >>= 1;
        t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
    }
}

int main() {

}