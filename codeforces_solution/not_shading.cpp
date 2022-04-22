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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  --r;
  --c;
  bool hasBlack = false;
  vector<vector<char>>arr(n, vector<char>(m));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> arr[i][j];
      hasBlack |= (arr[i][j]  == 'B');
    }
  }
  if(!hasBlack) {
    cout << -1 << endl;
    return;
  }
  if(arr[r][c] == 'B'){
    cout << 0 << endl;
    return;
  }
   bool oneMove = false;
   for(int i = 0; i < n; ++i)
     oneMove  |= (arr[i][c] == 'B');
   for(int i = 0; i < m; ++i)
     oneMove |= (arr[r][i] == 'B');

   cout << (oneMove ? 1 :  2 ) << endl;
}


int main() {
  double start = clock();
  int tc = 1;
  cin >> tc;
  while(tc--){
    solve();
  }
  cerr << "[*] Time " << (clock() * 1.0 - start) / CLOCKS_PER_SEC << " s" << std::setprecision(3) << endl;
  return 0;
}
