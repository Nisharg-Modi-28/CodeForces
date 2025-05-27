#include<bits/stdc++.h>
using namespace std;

#define fast_cin()     \
ios_base::sync_with_stdio(false); \
cin.tie(NULL);                  \
cout.tie(NULL)

int solve(int i,int j,string & str,string s2,vector<vector<int>> & mem) {
    int n = str.size();
    if(j == 3) return 1;
    
    if(i == n) return 0;

    if(mem[i][j] != -1) return mem[i][j];

    int use = 0;
    if(str[i] == s2[j]) use = solve(i+1,j+1,str,s2,mem);

    int not_use = solve(i+1,j,str,s2,mem);

    return (mem[i][j] = use + not_use);
}

int main() {
    fast_cin();
    
    string str;
    cin >> str;
    int n = str.size();
    vector<vector<int>> mem(n+1,vector<int> (3+1,0));
    for(int i=0;i<=n;i++) {
        mem[i][3] = 1;
    }
    // mem[n][0] = mem[n][1] = mem[n][2] = 0;
    string s2 = "QAQ";
    for(int i=n-1;i>=0;i--) {
        for(int j=2;j>=0;j--) {
            int use = 0;
            if(str[i] == s2[j]) use = mem[i+1][j+1];

            int not_use = mem[i+1][j];

            mem[i][j] = use + not_use;
        }
    }
    cout << mem[0][0] << endl;

    return 0;
}
