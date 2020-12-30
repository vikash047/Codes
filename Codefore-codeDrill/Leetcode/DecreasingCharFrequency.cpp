#include<iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

struct CChar {
    int val;
    char c;
    bool operator<(const CChar &rhs) const {
        return c == rhs.c;
    }
    bool operator==(const CChar &rhs) const {
        return c == rhs.c;
    }
};
struct Comp{
    bool operator()(const CChar &a, const CChar &b) const {
        return a.val > b.val;
    }
};

int main() 
{
    int t;
    set<CChar, Comp> cs;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cs.clear();
        for(char a : s) {
            CChar temp;
            temp.c = a;
            temp.val = 0;
            //cout << a << "  ";
            auto it = find(cs.begin(), cs.end(), temp);
            if(it != cs.end()) {
                cout << "Hello  ";
                temp.val += (*it).val + 1;
                cout << (*it).c << "  " << (*it).val << endl;
                cs.erase(it);
            } else {
                cout << "Could not find the char " << endl;
                temp.val = 1;
            }
            cout << " New Insert is " << temp.c << "  " << temp.val << endl;
            cs.emplace(temp);
        }
        for(auto val : cs) {
            cout << val.c << "  " << val.val << endl;
        }
    }
}