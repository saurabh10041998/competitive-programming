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
    ll n;
    cin >> n;
    vector<ll>arr(n);
    for(ll i = 0; i < n; ++i)
        cin >> arr[i];
    vector<pair<ll,ll>>ans;
    auto applyOp = [&] (ll x,ll i) {
        if((x + arr[i]) & 1)
            ans.push_back({1, i + 1});
        else
            ans.push_back({i + 1, n});
    };
    ll x = (arr[0] + arr[n - 1]) & 1 ? arr[0] : arr[n - 1];
    for(ll i = 1; i < n - 1; ++i) {
        applyOp(x, i);
    }
    cout << n - 1 << endl;
    if(n > 1)cout << 1 << " " << n << endl;
    for(auto a: ans)
        cout << a.first << " " << a.second << endl;
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
