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
  int n;
  cin >> n;
  vector<int>arr(n);
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  } 
  int  chest_count = 0, bicep_count = 0, back_count = 0;
  if(n > 3) {
    // this is chest reps
    for(int i = 0; i < n; i += 3)
      chest_count += arr[i];
    for(int i = 1; i < n; i +=3)
      bicep_count += arr[i];
    for(int i = 2; i < n; i += 3)
      back_count += arr[i];
  }else {
      if(n == 1)
        chest_count = arr[0];
      if (n == 2) {
        chest_count = arr[0];
        bicep_count = arr[1];
      }
      if(n == 3){
        chest_count = arr[0];
        bicep_count = arr[1];
        back_count = arr[2];
      }
  }

  int ans = std::max(chest_count, std::max(bicep_count, back_count));
  if(ans == chest_count)
    cout << "chest" << endl;
  else if(ans == bicep_count)
    cout << "biceps" << endl;
  else
    cout << "back" << endl;
}

int main() {
  double start = clock();
  solve();
  cerr << "[*] Time: " << (clock() * 1.0 - start) / CLOCKS_PER_SEC << " s" << std::setprecision(3) << endl;
  return 0;
}
