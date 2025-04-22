#include<bits/stdc++.h>
using namespace std;

#define fast_cin()     \
ios_base::sync_with_stdio(false); \
cin.tie(NULL);                  \
cout.tie(NULL)

bool isLeaf(int node,vector<vector<int>> &adj,vector<int> &visited) {
    for(auto it:adj[node]) {
        if(!visited[it]) return false;
    }
    return true;
}

void solve() {
    int n,m;
    cin >> n >> m;

    int cats[n+1] = {-1};

    for(int i=1;i<=n;i++) {
        cin >> cats[i];
    }
    // int parent[n+1] = {-1};

    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // parent[v] = u;
    }
    vector<int> visited(n+1,0);
    int count = 0;
    queue<pair<int,int>> q;
    q.push({1,cats[1]}); // node,cats
    
    while(!q.empty()) {
        int node = q.front().first;
        int c = q.front().second;
        q.pop();
        visited[node] = true;

        // if(node != 1 && adj[node].size() == 1 && c <= m) {// leaf node 
        //     count++;
        // }
        if(c > m) {
            count++;
            continue;
        }
        if(cats[node] ==0)  c = 0;
        for(auto it:adj[node]) {
            if(!visited[it]) q.push({it,c + cats[it]});
        }
    }
    cout << count << endl;
}

int main() {
    fast_cin();
    //int t;	cin >> t;
    //while(t--) {
        solve();
    //}
    return 0;
}
    // std::ifstream fi("input.txt");
    // std::ofstream fo("output.txt");