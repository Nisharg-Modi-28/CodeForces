#include<bits/stdc++.h>
using namespace std;

#define fast_cin()     \
ios_base::sync_with_stdio(false); \
cin.tie(NULL);                  \
cout.tie(NULL)

void solve() {
    int n,m;
    cin >> n >> m;

    vector<int> dist(1e4+1,1e8);
    dist[n] = 0;

    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(n);

    while(!pq.empty()) {
        int node = pq.top();
        pq.pop();

        int adj1 = 2*node,adj2 = node-1;

        if(adj1 <= 1e4 && dist[adj1] > dist[node] + 1) {
            dist[adj1] = dist[node] + 1;
            pq.push(adj1);
        }
        if(adj2 >= 0 && adj2 <= 1e4 && dist[adj2] > dist[node] + 1) {
            dist[adj2] = dist[node] + 1;
            pq.push(adj2);
        }
    }

    cout << dist[m] << endl; 
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