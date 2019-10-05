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

// segment tree problem  update using push down and push up
const int MAXN= 100000;
class SegmentTree{
    private:
    int N;
    int A[2*MAXN];
    int M[2*MAXN];
    bool H[2*MAXN];
    int Q[2*MAXN]; // store number of elements in assignment case how many elements are effected by assignment of a range L, R
    public:
    SegmentTree(int n) {
        N = n;
    }
    void buildTree(int a[]){
        frei(i, N, 2*N-1) A[i] = a[i-N];
        fred(i, N-1, 0) A[i] = A[i << 1] + A[i << 1 | 1];
        makeQ();
    }
    void makeQ() {
        frei(i, N, 2*N-1) Q[i] = 1;
        for(int i = 2*N - 1; i > 1; i -= 2) {
            Q[i >> 1] = Q[i] + Q[i^1];
        }
    }
    void modifyHelper(int i, int p) {
        A[i] = Q[i]*p;
        M[i] = p;
        H[i] = true;
    }
    void push(int i) {
        if(H[i >> 1]) {
            modifyHelper(i, M[i>>1]);
            modifyHelper(i^1, M[i>>1]);
            H[i>>1] = false;
        }
    }
    void pushDown(int i) {
        int k;
        for(k = 0; (i >> k) > 0; k++);
        for(k -= 2; k > 0; k--) {
            push(i >> k);
        }
        cout << "exit push down" << endl;
    }
    void popUp(int i) {
        for(; i > 1; i >>= 1) {
            pop(i);
        }
    }
    void pop(int i) {
        if(H[i >> 1]) {
            A[i >> 1] = M[i >> 1]*Q[i >> 1];
        } else {
            A[i >> 1] = A[i] + A[i^1];
        }
    }
    void update(int L, int R, int val) {
        L = L + N;
        R = R + N;
        int Lcopy = L, Rcopy = R;
        pushDown(L);
        pushDown(R);
        for(; L <= R; L = (L + 1) >> 1, R = (R-1) >> 1) {
            if(L & 1) {
                modifyHelper(L, val);
            }
            if(!(R&1)) {
                modifyHelper(R, val);
            }
        }
        //cout << " He llo " << endl;
        popUp(Lcopy);
        popUp(Rcopy);
        cout << " Done update " << endl;
        print();
    }
    int Query(int L, int R) {
        L = L + N;
        R = R + N;
        pushDown(L);
        pushDown(R);
        int sum = 0;
        print();
        for(; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
            //cout << L << "  " << R << endl;
            if(L&1) {
                sum += A[L];
            } 
            if(!(R&1)) {
                sum += A[R];
            }
        }
        return sum;
    }
    void print() {
        fri(i, 2*N) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};
/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 */

class RecursiveSegmentTree{
    int A[2*MAXN];
    int lazy[2*MAXN];
    int N;
    public:
    void buildTree(int a[], int node, int L, int R) {
        if(L > R) return;
        if(L == R) { // leaf node
            A[node] = a[L];
            return;
        }
        buildTree(a, node*2 + 1, L, L + (R - L)/2);
        buildTree(a, node*2 + 2, L + (R-L)/2 + 1, R);
        A[node] = A[node*2 + 1] + A[node*2 + 2];
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    int n, q;
    cin >> n >> q;
    //N = n;
    int a[n];
    fri(i, n) cin >> a[i];
    SegmentTree tree(n);
    tree.buildTree(a);
    int x, L, R, val;
    while(q--) {
        cin >> x;
        if(x == 1) {
            cin >> L >> R >> val;
            tree.update(L, R, val);
        } else if(x == 2) {
            cin >> L >> R;
            cout << tree.Query(L, R) << endl;
        }
    }
    return 0;
}
