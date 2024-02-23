// cpp template test file
#include "bits/stdc++.h"
using namespace std;

// LOCAL JUDGING - REMOVE IF NEEDED
// #define _MY_TEST_FILES true
#define _HAS_NUM_TESTCASES_INPUT true

// MACROS
#define ll long long
#define _debug(x) cout << x << endl

void solve() {
  int n = 0;
  cin >> n;

  vector<int> a(n, 0);
  for (int &it : a) {
    cin >> it;
  }

  int min_ele_idx = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] < a[min_ele_idx]) {
      min_ele_idx = i;
    }
  }
  a[min_ele_idx]++;
  cout << accumulate(a.begin(), a.end(), 1LL, multiplies<ll>()) << endl;
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
