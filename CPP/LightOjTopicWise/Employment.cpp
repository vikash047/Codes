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


int prefer[202][101];
int emp[101];
int cmp[101];
int n;

bool checkPriority(int c, int e1, int e2) 
{
    for(int i = 1; i <= n; i++) {
        if(prefer[c][i] == e1) {
            return true;
        }
        if(prefer[c][i] == e2) {
            return false;
        }
    }
}

void stableMatching() 
{
    memset(cmp, -1, sizeof(cmp));
    memset(emp, -1, sizeof(emp));
    int freecount = n;
    while(freecount > 0) {
        //cout << freecount << endl;
        int m;
        for(int i = 1; i <= n; i++) {
            if(emp[i] == -1) {
                m = i;
                break;
            }
        }
        for(int i = 1; i <= n && (emp[m] == -1); i++) {
            int c = prefer[m][i];
            //cout << m << "  " << c  <<  "  " << cmp[c-n] << endl;
            if(cmp[c - n] == -1) {
                cmp[c - n] = m;
                emp[m] = c;
                freecount--;
                //cout << " In free " << endl;
            } else {
                int e1 = cmp[c-n];
                if(!checkPriority(c, e1, m)) {
                    cmp[c-n] = m;
                    emp[e1] = -1;
                    emp[m] = c;
                   // cout << " IN full " << endl;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << "(" << cmp[i] << " " << i+n << ")" << " ";
    }
    cout << endl; 

}

void print() {
    for(int i = 1; i <= 2*n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << prefer[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cin >> n;
        for(int i = 1; i <= 2*n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> prefer[i][j];
            }
        }
       // print();
        cout << "Case " << cs << ": ";
        stableMatching();

    }
    return 0;
}
