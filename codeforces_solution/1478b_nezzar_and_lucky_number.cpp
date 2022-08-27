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
    int n, d; 
    cin >> n >> d;
    if(d == 0) d += 10;
    int mx = 10 * d;
    vector<bool>dp(200, false);
    dp[0] = true;
    for(int i = 0; 10 * i  + d <= mx; ++i) {
        for(int j = 0; 10 * i + d + j <= mx; ++j) {
            dp[10 * i  + d + j] = dp[10 * i + d + j] || dp[j];
        }
    }
    ll x;
    for(int i = 0; i < n; ++i) { 
        cin >> x;
        if(x >= mx * 1LL) {
            cout << "YES" << endl;
        }else {
            cout << (dp[x] ? "YES": "NO") << endl;
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
