#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numOfWays(int n, int x) {
    const int mod = 1e9 + 7;
    auto expo = [](int n, int p) -> int {
      int ans = 1;
      while (p) {
        if (p & 1) {
          ans = ans * n;
        }
        n = n * n;
        p >>= 1;
      }
      return ans;
    };

    vector<int> v = {0};
    for (int i = 1; expo(i, x) < n + 1; i++) {
      v.push_back(expo(i, x));
    }

    int size = v.size();

    vector<vector<int>> dp(size, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; expo(i, x) < n + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
        int take, notake;
        take = notake = 0;

        if (j >= v[i])
          take = dp[i - 1][j - v[i]];
        notake = dp[i - 1][j];

        dp[i][j] = (take + notake) % mod;
      }
    }
    return dp[size - 1][n];
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    Solution ob;
    cout << ob.numOfWays(n, x) << endl;
  }
  return 0;
}