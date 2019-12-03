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

void add_slef(int &a, int b, int mod = 0) {
    a += b;
    if(mod > 0 && a >= mod) a -= mod;
}

void sub_slef(int &a, int b, int mod = 0) {
    a -= b;
    if(mod > 0 && a < 0) a += mod;
}

int mul(int a, int b, int mod = 0) {
    if(mod > 0) {
        return (int)((int64)a*b%mod);
    }
    return a*b;
}

vector<string> split(string s, string del) {
        vector<string> ans;
        if(s.size() == 0) {
            return ans;
        }
        size_t pos = 0;
        while((pos = s.find(del)) != string::npos) {
            string str = s.substr(0, pos);
            ans.push_back(str);
            s.erase(0, pos + del.size());
        }
        return ans;
}
const int mod = 998244353;
class DigitRotation{
    public:
    int sumRotations(string x) {
        int n = x.size();
        vector<int> digit(n);
        for(int i = 0; i < n; i++) {
            digit[i] = x[i] - '0';
        }
        vector<int> cost(n);
        cost[n-1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            cost[i] = mul(cost[i+1], 10, mod);
        }
        int num = 0;
        for(int i = 0; i < n; i++) {
            add_slef(num, mul(digit[i], cost[i], mod), mod);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j  = i+1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(digit[k] == 0 && i == 0) {
                        continue;
                    }
                    int curr = num;
                    sub_slef(curr, mul(digit[i], cost[i], mod), mod);
                    sub_slef(curr, mul(digit[j], cost[j], mod), mod);
                    sub_slef(curr, mul(digit[k], cost[k], mod), mod);
                    add_slef(curr, mul(digit[i], cost[j], mod), mod);
                    add_slef(curr, mul(digit[j], cost[k], mod), mod);
                    add_slef(curr, mul(digit[k], cost[i], mod), mod);
                    add_slef(ans, curr, mod);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    string s;
    cin >> s;
    DigitRotation dr;
    cout << dr.sumRotations(s) << endl;
    return 0;
}
