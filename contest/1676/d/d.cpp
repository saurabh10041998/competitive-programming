#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define endl "\n"

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>>arr(n, vector<int>(m, 0));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }

  auto inside = [](int i, int j, int n, int m) -> bool {
    if(i >= 0 &&  i  < n && j >= 0 && j < m)
      return true;
    return false;
  };
  
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      // sum of diagonal1
      int x = std::min(i, j);
      int d1i = i - x;
      int d1j = j - x;
      int d1 = 0;
      while(1) {
        if(!inside(d1i, d1j, n, m))
          break;
        d1 += arr[d1i][d1j];
        ++d1i;
        ++d1j;
      }

      // sum of diagonal2
      int d2i = i;
      int d2j = j;
      int d2 = 0;
      // upper right diagoanal
      while(1) {
        if(!inside(d2i,d2j, n, m))
          break;
        d2 += arr[d2i][d2j];
        --d2i;
        ++d2j;
      } 
      //lower left diagonal
      d2i = i + 1;
      d2j = j - 1;
      while(1){
        if(!inside(d2i,d2j,n,m))
          break;
        d2 += arr[d2i][d2j];
        ++d2i;
        --d2j;
      }
      ans = std::max(ans, d1 + d2 - arr[i][j]);
    }
  }
  cout << ans << endl;
  
}

int main() {
    double start = clock();
    int tc = 1;
    cin >> tc;
    while(tc--) {
       solve();
    }
    cerr << "[*] Time: " << (clock() * 1.0 - start) / CLOCKS_PER_SEC << std::setprecision(3) << " s" << endl;
    return 0;
}
