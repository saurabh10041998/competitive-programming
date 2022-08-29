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

ll gcd(ll a, ll b) {
    if(a < b)
        std::swap(a, b); 
    ll r = a % b;
    while(r != 0) { 
        a = b; 
        b = r; 
        r = a % b;
    }
    return b;
}

void solve() {
    ll n; 
    cin >> n; 
    vector<ll>arr(n);
    for(ll i = 0; i < n; ++i)
        cin >> arr[i];
    vector<ll>g(arr.begin(), arr.begin() + 2);
    for(ll i = 2; i < n; ++i) {
       g[i % 2] = gcd(arr[i], g[i % 2]);
    }
    vector<bool>good(2, true);
    for(int i = 0; i < n; ++i) { 
        good[i % 2] = good[i % 2] && (arr[i] % g[(i % 2) ^ 1] > 0);
    }
    ll ans = 0;
    for(int i = 0; i < 2; ++i) { 
        if(good[i]) {
            ans = std::max(ans, g[i ^ 1]);
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
