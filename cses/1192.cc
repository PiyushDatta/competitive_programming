// cpp template test file
#include "bits/stdc++.h"
using namespace std;

// LOCAL JUDGING - REMOVE IF NEEDED
// #define _MY_TEST_FILES true
// #define _HAS_NUM_TESTCASES_INPUT true

// MACROS
#define ll long long
#define _debug(x) cout << x << endl

void dfs(vector<vector<string>> &building_mp, int i, int j) {
  int n = building_mp.size();
  int m = building_mp[0].size();
  if (i >= n || i < 0 || j >= m || j < 0)
    return;
  if (building_mp[i][j] == "#")
    return;
  building_mp[i][j] = "#";
  dfs(building_mp, i + 1, j);
  dfs(building_mp, i - 1, j);
  dfs(building_mp, i, j + 1);
  dfs(building_mp, i, j - 1);
}

void solve() {
  int n = 0;
  cin >> n;
  int m = 0;
  cin >> m;

  vector<vector<string>> building_mp(n, vector<string>(m));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      building_mp[i][j] = s[j];
    }
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (building_mp[i][j] == ".") {
        ++res;
        dfs(building_mp, i, j);
      }
    }
  }

  cout << res << endl;
}

// Driver program to test above function
int main() {
  // optional performance optimizations
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifdef _MY_TEST_FILES
  // for getting input from input.txt file
  freopen("input.txt", "r", stdin);
  // printing the output to output.txt file
  freopen("my_ans.txt", "w", stdout);
#endif

#ifdef _HAS_NUM_TESTCASES_INPUT
  // keep this, testcases
  int t;
  cin >> t;

  // now we can run our algo
  for (int i = 1; i <= t; ++i) {
    // cout << "Case #" << i << ": ";
    solve();
  }
#else
  solve();
#endif

  return 0;
}
