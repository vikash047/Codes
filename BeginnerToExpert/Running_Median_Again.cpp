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

class Comp {
    public:
    bool operator()(int a, int b) {
        return a > b;
    }
};
class Solve {
    private:
    priority_queue<int> mxpq;
    priority_queue<int, vector<int>, Comp> mnpq;
    bool sizeDiff() {
        return (abs(mxpq.size() - mnpq.size()) < 2);
    }
    void correctTheTree() {
        if(mxpq.size() > mnpq.size()) {
            mnpq.push(mxpq.top());
            mxpq.pop();
        } else {
            mxpq.push(mnpq.top());
            mnpq.pop();
        }
    }
    public:
    void Add(int n) {
        if(mxpq.empty() && mnpq.empty()) {
            mxpq.push(n);
        } else if(n > mxpq.top()) {
            mnpq.push(n);
            if(!sizeDiff()) {
                correctTheTree();
            }
        } else {
            mxpq.push(n);
            if(!sizeDiff()) {
                correctTheTree();
            }
        }
    }
    int GetMedian(){
        int median;
        if(mnpq.size() == mxpq.size()) {
            median = mxpq.top();
            mxpq.pop();
            if(!sizeDiff()) correctTheTree();
        } else {
            if(mnpq.size() > mxpq.size()) {
                median = mnpq.top();
                mnpq.pop();

            } else {
                median = mxpq.top();
                mxpq.pop();
            }
            if(!sizeDiff()) correctTheTree();
        }
        return median;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while(t--) {
        Solve ob;
        int x;
        scanf("%d", &x);
        while(x != 0) {
            if(x == -1) {
                printf("%d\n", ob.GetMedian());
            } else {
                ob.Add(x);
            }
            scanf("%d", &x);
        }
    }
   
    return 0;
}
