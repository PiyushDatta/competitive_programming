// cpp test file
#include <bits/stdc++.h>
using namespace std;

// DEFINE
#define _MY_TEST_FILES true

// MACROS
#define ll long long
#define _debug(x) cout << x << endl

void solve() {
  // int n = 0;
  // cin >> n;
  // int k = 0;
  // cin >> k;

  // vector<int> a(n, 0);
  // for (int &it : a) {
  //   cin >> it;
  // }
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

  // keep this, testcases
  int t;
  cin >> t;

  // now we can run our algo
  for (int i = 1; i <= t; ++i) {
    // cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}
