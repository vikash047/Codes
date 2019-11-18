#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

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

double pr[303][303][303];
double ev[303][303][303];

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    vector<int> p(n+1);
    int cnt[4] = {0, 0, 0, 0};
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        cnt[p[i]]++;
    }
    // I have sushi 1, 2, 3 on a dish -> if i am going to eat 1 -> 0, 2 -> 1, 3 -> 2;
    // so 3 is decresing 
    // p[a][b][c] -> to occur state a, b, c what is probability
    // ev[a][b][c] -> what is occur state of expected value a, b, c;
    // there is posiblility of state of 0 so prop os that s = pw + pw^2 + pw^3 ... 
    // final state is 0, 0, 0
    pr[cnt[1]][cnt[2]][cnt[3]] = 1;
    for(int c = n; c >= 0; c--) {
        for(int b = n; b >= 0; b--) {
            for(int a = n; a >= 0; a--) {

                if(a == 0 && b == 0 && c == 0) continue;
                if(a + b + c > n) continue;

                double p_waste = (double)(n - (a + b + c))/n;
                double ev_waste = p_waste/(1 - p_waste) + 1; // + 1 state transition changing to state from here;
                ev[a][b][c] += ev_waste*pr[a][b][c]; 

                if(a != 0) {
                    double p_go = (double) a/(a + b + c);
                    pr[a-1][b][c] += pr[a][b][c]*p_go;
                    ev[a-1][b][c] += ev[a][b][c]*p_go;
                }
                if(b != 0) {
                    double p_go = (double) b/(a + b + c);
                    pr[a+1][b-1][c] += pr[a][b][c]*p_go;
                    ev[a+1][b-1][c] += ev[a][b][c]*p_go;
                } 
                if(c != 0) {
                    double p_go = (double) c/(a + b + c);
                    pr[a][b+1][c-1] += pr[a][b][c]*p_go;
                    ev[a][b+1][c-1] += ev[a][b][c]*p_go;
                }   
            }
        }
    }
    cout << setprecision(10) << ev[0][0][0] << endl;
    return 0;
}
