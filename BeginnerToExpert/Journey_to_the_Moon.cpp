#include <bits/stdc++.h>

using namespace std;

void dfs(int source, vector<int> adj[], vector<int>& con, int cnt) {
    con[source] = cnt;
    for(int i = 0; i < adj[source].size(); i++) {
        int next = adj[source][i];
        if(con[next] == 0) {
            dfs(next, adj, con, cnt);
        }
    }
}
// Complete the journeyToMoon function below.
int journeyToMoon(int n, vector<vector<int> > astronaut) {
    vector<int> adj[n];
    for(int i = 0; i < astronaut.size(); i++) {
        adj[astronaut[i][0]].push_back(astronaut[i][1]);
        adj[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    vector<int> connected(n, 0);
    int cnt = 1;
    for(int i = 0; i < n; i++) {
        if(connected[i] == 0) {
            dfs(i, adj, connected, cnt);
            cnt++;
        }
    }
    map<int, int> mapping;
    for(int i = 0; i < n; i++) {
        mapping[connected[i]]++;
    }
    vector<int> out;
    map<int, int> :: iterator it;
    for(it = mapping.begin(); it != mapping.end(); ++it) {
        //cout << " pair " << it->first << "  "<< it->second << endl;
        out.push_back(it->second);
    }
    sort(out.begin(), out.end(), greater<int>());
   // cout << out.size() << endl;
    for(int i = 0; i < out.size(); i++){
        //cout << i << "  " << out[i] << endl;
        if(i > 0) {
            out[i] += out[i-1];
        }
    } 
    int ans = 0;
    int l = out[0];
    int r = out[out.size()-1];
    cout << l << "  " << r << endl;
    for(int i = 0; i < out.size(); i++) {
        if(i == 0) {
            ans += (l*(r - l));
        } else if(i != n-1) {
            ans += (out[i] - out[i-1])*(r - out[i]);
        } 
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n, p;
    cin >> n >> p;

    vector<vector<int> > astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = journeyToMoon(n, astronaut);

    cout << result << "\n";

    return 0;
}
