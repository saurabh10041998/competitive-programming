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


void solve() {
  ll n,q,x; 
  cin >> n >> q;
  vector<ll>arr(n);
  for(auto &y: arr)
    cin >> y;
  std::sort(all(arr), greater<ll>());
  vector<ll>pref(n);
  pref[0] = arr[0];
  for(int i = 1; i < n; ++i)
    pref[i] = pref[i - 1] + arr[i];
  auto bin_search = [](vector<ll>pref, ll n, ll key) -> ll {
    ll left = 0;
    ll right = n - 1;
    ll ans = -1;
    while(left <= right){
      ll mid = left + (right - left)/2LL;
      if(pref[mid] < key)
        left = mid + 1;
      else {
        ans = mid;
        right = mid - 1;
      }
    }
    return ans;
  };
  while(q--){
    cin >> x;
    if(x > pref[n - 1])
      cout << -1  << endl;
    else {
      ll ans = 0;
      ans = bin_search(pref, n, x);
      cout << ans +  1<< endl;
    }
  }  
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
