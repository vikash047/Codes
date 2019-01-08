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

const int MAXN = 1e6+1;

int A[MAXN];
int BIT[MAXN] = {0};

class Bit
{
    int N;
    public:
    Bit(int n) {
        this->N = n;
    }
    void buildBit() {
        BIT[0] = 0;
        frei(i, 1, N) update(i, A[i]);
        //print();
    }
    void update(int i, int val) {
        while(i <= N) {
            BIT[i] += val;
            i += (i & -i);
        }
    }
    int64 getRangeSum(int l, int r) {
        return getSum(r) - getSum(l - 1);
    }
    int64 getSum(int i) {
        int64 sum = 0;
        while(i > 0) {
            //cout << i << endl;
            sum += BIT[i];
            //cout << " sum after " << sum << endl;
            i -= (i & -i);
        }
        return sum;
    }
    void print() {
        frei(i, 1, N) {
            cout << BIT[i] << " ";
        }
        cout << endl;
    } 
};

int main(int argc, char const *argv[])
{
    /* code */
    int n, q;
    cin >> n;
    frei(i, 1, n) cin >> A[i];
    cin >> q;
    int x, y;
    string s;
    Bit ob(n);
    ob.buildBit();
    fri(i, q) {
        cin >> s;
        if(s == "q") {
            cin >> x >> y;
            cout << ob.getRangeSum(x, y) << endl;
        } else {
            cin >> x >> y;
            ob.update(x, y);
        }
    }
    return 0;
}
