#include <bits/stdc++.h>

using namespace std;

#define LOCAL true

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


unsigned getNthUglyNo(unsigned n){
  vector<unsigned>ugly(n + 1);
  ugly[1] = 1;
  unsigned i2 = 1; 
  unsigned i3 = 1;
  unsigned i5 = 1;
  unsigned next_multiple_2 = ugly[i2] * 2;
  unsigned next_multiple_3 = ugly[i3] * 3;
  unsigned next_multiple_5 = ugly[i5] * 5;

  for(int i = 2; i <= n; ++i) {
    ugly[i] =  std::min(next_multiple_2, std::min(next_multiple_3, next_multiple_5));
    if(ugly[i] == next_multiple_2) {
        i2 += 1;
        next_multiple_2 = ugly[i2] * 2;
    }
    if(ugly[i] == next_multiple_3) {
      i3 += 1;
      next_multiple_3 = ugly[i3] * 3;
    }
    if(ugly[i] == next_multiple_5) {
      i5 += 1;
      next_multiple_5 = ugly[i5] * 5;
    }
  }
  return ugly[n];
  
}

void solve() {
  unsigned ans = getNthUglyNo(150);
  cout << "\x1B[33m[*] " << 150 << " th ugly number is : " << ans << endl;
}

int main() {
    double start = clock();
    int tc = 1;
    //cin >> tc;
    while(tc--) {
       solve();
    }
    cerr << "[*] Time: " << (clock() * 1.0 - start) / CLOCKS_PER_SEC << std::setprecision(3) << " s" << endl;
    return 0;
}
