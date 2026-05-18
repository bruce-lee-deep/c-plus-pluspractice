#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;
    vector<long long> prev = { 1 };
    for (int i = 1; i <= n; ++i) {
        vector<long long> curr(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            curr[j] = (prev[j - 1] + prev[j]) % MOD;
        }
        prev = move(curr);
    }
    for (int i = 0; i < prev.size(); ++i) {
        if (i > 0) cout << " ";
        cout << prev[i];
    }
    cout << endl;
    return 0;
}