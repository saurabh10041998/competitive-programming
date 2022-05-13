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

using cd = complex<double>;
const double PI = std::acos(-1);


void fft(vector<cd>&a, bool invert) {
  int n = a.size();
  if(n == 1)
    return;
  vector<cd> a0(n/2);
  vector<cd> a1(n/2);
  
  for(int i = 0; 2 * i < n; ++i) {
    a0[i] = a[2 * i];
    a1[i] = a[2 * i + 1];
  }
  fft(a0, invert);
  fft(a1, invert);

  double ang;
  if(!invert) {
    ang = 2 * PI / n;
  }else {
    ang = 2 * PI / n * -1;
  }
  cd w(1);
  cd wn(cos(ang), sin(ang));
  for(int i = 0; 2 * i < n; ++i){
    a[i] = a0[i] + w * a1[i];
    a[i + n/2] = a0[i] - w * a1[i];
    if(invert){
      a[i] /= 2;
      a[i + n/2] /= 2;
    }    
    w *= wn;
  }
}


void solve() {
  vector<int>a(2);
  a[0] = 1;
  a[1] = 1;
  vector<int>b(2);
  b[0] = 1;
  b[1] = 1;
  // (x+1)(x + 1) = degree 2 --> points = 3 so array of size of 4..
  vector<cd>pa(a.begin(), a.end());
  vector<cd>pb(b.begin(), b.end());

  pa.resize(4); 
  pb.resize(4);

  fft(pa, false);
  fft(pb, false);

  for(int i = 0; i < 4; ++i)
    pa[i] *= pb[i];
  
  fft(pa, true);

  //printing the result..

  vector<int>result(4);
  for(int i = 0; i < 4; ++i)
    result[i] = std::round(pa[i].real());

  cout << "=== Coefficients of multiplications are ===" << endl;
  for(auto x: result)
    cout << x << " ";
  cout << endl;
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
