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
    vector<ll>even;
    vector<ll>odd; 
    vector<ll>s_even;
    vector<ll>s_odd;
    ll x;
    for(ll i = 0; i < n; ++i) {
        cin >> x;
        if(x % 2 != 0) {
            odd.push_back(x);
            s_odd.push_back(x);
        }else {
            even.push_back(x);
            s_even.push_back(x);
        }
    }
    std::sort(s_odd.begin(), s_odd.end());
    std::sort(s_even.begin(), s_even.end());
    bool ok = true;
    for(ll i = 0;  i < s_even.size(); ++i) {
        if(s_even[i] != even[i]) {
            ok = false;
            break;
        }
    }
    if(ok) {
        for(ll i = 0; i < s_odd.size(); ++i) {
            if(s_odd[i] != odd[i]) { 
                ok = false;
                break;
            }
        }
    }
    cout << (ok ? "Yes": "No") << endl;
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
