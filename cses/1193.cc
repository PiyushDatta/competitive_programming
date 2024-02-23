// https://cses.fi/problemset/task/1193

// cpp template test file
#include "bits/stdc++.h"
using namespace std;

// LOCAL JUDGING - REMOVE IF NEEDED
// #define _MY_TEST_FILES true
// #define _HAS_NUM_TESTCASES_INPUT true

// MACROS
#define ll long long
#define _debug(x) cout << x << endl

void solve() {
  int n = 0;
  cin >> n;
  int m = 0;
  cin >> m;

  queue<pair<int, int>> q;
  vector<vector<int>> path(n, vector<int>(m, 0));
  vector<vector<char>> grid(n, vector<char>(m, '#'));
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  // URDL
  vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int start_i = 0;
  int start_j = 0;
  int end_i = 0;
  int end_j = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') {
        start_i = i;
        start_j = j;
      } else if (grid[i][j] == 'B') {
        end_i = i;
        end_j = j;
      } else if (grid[i][j] == '#') {
        vis[i][j] = true;
      }
    }
  }
  q.push({start_i, start_j});
  vis[start_i][start_j] = true;

  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int new_i = i + dirs[d][0];
      int new_j = j + dirs[d][1];
      if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
          !vis[new_i][new_j] && grid[new_i][new_j] != '#') {
        vis[new_i][new_j] = true;
        path[new_i][new_j] = d;
        q.push({new_i, new_j});
      }
    }
  }

  if (!vis[end_i][end_j]) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  vector<int> res;
  while (end_i != start_i || end_j != start_j) {
    int d = path[end_i][end_j];
    res.push_back(d);
    end_i -= dirs[d][0];
    end_j -= dirs[d][1];
  }
  reverse(res.begin(), res.end());
  cout << res.size() << endl;
  for (int c : res) {
    cout << "URDL"[c];
  }
  cout << endl;
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
