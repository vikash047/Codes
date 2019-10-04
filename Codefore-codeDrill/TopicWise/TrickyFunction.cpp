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

struct Point {
    int x;
    int y;
};

bool CompareY(Point a, Point b) {
    return a.y < b.y;
}

bool CompareX(Point a, Point b) {
    return a.x < b.x;
}

int Dist(Point a, Point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int PairWiseDistance(vector<Point> inputs, int l, int r) {
    int min = INT_MAX;
    for(int i = l; i <= r; i++) {
        for(int j = i + 1; j <= r; j++) {
            int d = Dist(inputs[i], inputs[j]);
            if(d < min) {
                min = d;
            }
        }
    }
    return min;
}

int FindClosestInBox(vector<Point> inputs, int d) {
    sort(inputs.begin(), inputs.end(), CompareY);
    int min = d;
    for(int i = 0; i < inputs.size(); i++) {
        for(int j =  i + 1; j < inputs.size(); j++) {
            if(abs(inputs[i].y - inputs[j].y) < d) {
                int dist = Dist(inputs[i], inputs[j]);
                if(dist < min) {
                    min = dist;
                }
            }
        }
    }
    return min;
}

int ClosestPoint(vector<Point> inputs, int l, int r) {
    if(l == r) {
        return INT_MAX;
    }
    if(r - l < 4) {
        return PairWiseDistance(inputs, l, r);
    }
    int mid = (r + l)/2;
    int dl;
    int dr;
    Point midpoint = inputs[ l + (r - l)/2];
    dl = ClosestPoint(inputs, l, mid);
    dr = ClosestPoint(inputs, mid + 1, r);
    int d = min(dl, dr);
    vector<Point> box;
    int k = 0;
    for(int i = l; i <= r; i++) {
        if(abs(inputs[i].x - midpoint.x) < d) {
            box[k++] = inputs[i];
        }
    }
    return min(d, FindClosestInBox(box, d));
}
int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    int a[n];
    int sum[n];
    vector<Point> points;
    Point p;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i] = i == 0 ? a[i] : sum[i-1] + a[i];
        p.x = i;
        p.y = sum[i];
        points.push_back(p);
    }
    sort(points.begin(), points.end(), CompareX);
    cout << ClosestPoint(points, 0, points.size() - 1) << endl;
   
    return 0;
}
