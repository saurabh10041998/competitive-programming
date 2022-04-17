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
  int n, k;
  ifstream cin("input.txt");
  ofstream cout("output.txt");
  cin >> n >> k;
  vector<pair<int,int>>ele;
  int x;
  for(int i = 0; i < n; ++i) {
    cin >> x;
    ele.push_back(make_pair(x, i + 1));
  }
  sort(ele.rbegin(), ele.rend());
  cout << ele[k - 1].first << endl;
  vector<int>indices;
  for(int i = 0; i < k; ++i) {
    indices.push_back(ele[i].second);
  } 
  sort(all(indices));
  for(auto in:indices)
    cout << in << " ";
  cout << endl;
}


int main() {
  //double start = clock();
  solve();
  //cerr << "[*] Time: " <<(clock() * 1.0 - start) / CLOCKS_PER_SEC << std::setprecision(3) << " s" << endl;
  return 0;
}
