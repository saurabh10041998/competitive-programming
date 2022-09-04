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
    vector<pair<ll, ll>>arr(n);
    map<pair<ll, ll>, ll>mp;
    for(ll i = 0; i < n; ++i) { 
        cin >> arr[i].first >> arr[i].second;
        mp[arr[i]] = i + 1;
    }
    std::sort(all(arr), [&](pair<ll, ll>a, pair<ll, ll>b) -> bool {
       return (a.second - a.first) > (b.second - b.first);     
    });
    ll l = arr[0].first;
    ll r = arr[0].second;
    int cnt = 0;
    for(ll i = 0; i < n; ++i) { 
        if((arr[i].first >= l) && (arr[i].second <= r)) {
            cnt++;
        }
    }
    if(cnt != n) {
        cout << -1 << endl;
    }else {
        cout << mp[{l, r}] << endl;
    }
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
