#include<bits/stdc++.h>
using namespace std;

#define fast_cin()     \
ios_base::sync_with_stdio(false); \
cin.tie(NULL);                  \
cout.tie(NULL)

bool hasAtMostThreeNonZeroDigits(unsigned long long num) {
    int count = 0;
    while (num != 0) {
        if (num % 10 > 0) {
            count++;
            if (count > 3) return false; // Early exit if count exceeds 3
        }
        num /= 10;
    }
    return true;
}

void solve() {
    unsigned long long L, R;
    cin >> L >> R;

    unsigned long long result = 0;
    for (unsigned long long i = L; i <= R; ++i) {
        if (hasAtMostThreeNonZeroDigits(i)) {
            result++;
        }
    }

    cout << result << endl;
}

int main() {
    fast_cin();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}