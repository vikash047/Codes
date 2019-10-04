#include<bits/stdc++.h>
#include<string>
using namespace std;

pair<string, string> getSmartString(string s) {
    istringstream buf(s);
    istream_iterator<string> beg(buf), end;
    vector<string> tokens(beg, end);
    string v1 = tokens[0];
    string v2 = tokens[1];
    string value = tokens[2];
    string v3 = "";
    for(int i = 0; i < value.size(); i++) {
        if(value[i] == '-') {
            break;
        }
        v3 += value[i];
    }
    pair<string, string> ans = make_pair(v2 + "$" + v3, v1);
    return ans;
}

int stoi(string s) {
    int res = 0;
    for(int i = 0; i < s.size(); i++) {
        res = res*10 + (int)(s[i] - '0');
    }
    return res;
}

int main(int argc, char const *argv[]) 
{
    string line;
    ifstream myfile("/Users/vikkumamicrosoft.com/Desktop/debugdata14.txt");

    map<string, int> mapping;

    if(myfile.is_open()) {
        while(getline(myfile, line)) {
            //cout << line << endl;
            pair<string, string> tt = getSmartString(line);
            if(mapping.find(tt.first) != mapping.end()) {
                mapping[tt.first]  = mapping[tt.first] + stoi(tt.second);
            } else {
                mapping[tt.first] = stoi(tt.second);
            }
            //break;
        }
        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    cout << "Date \t" << " Env \t" << "Total \t"  << endl;;
    for(map<string, int> :: iterator it = mapping.begin(); it != mapping.end(); ++it) {
        string s1 = it->first;
        cout << s1.substr(0, s1.find('$')) << "\t" << s1.substr(s1.find('$') + 1) << "\t" << it->second << endl;
    }
    return 0;
}