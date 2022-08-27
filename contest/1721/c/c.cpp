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
    vector<ll>brr(n);
    for(ll j = 0; j < n; ++j)
        cin >> brr[j];

    auto ptr = std::upper_bound(all(arr), brr[0]);
    ptr--;
    int idx = ptr - arr.begin();
    dbg(idx);
    vector<int>min,max;
    for(int i = 0; i <= idx; ++i) {
        min.push_back(brr[0] - arr[i]);
        max.push_back(brr[idx] - arr[i]);
    }
    dbg(min);
    dbg(max);
    for(int i = idx + 1; i < n; ++i) {
        min.push_back(brr[i] - arr[i]);
        max.push_back(brr[i] - arr[i]);
    }
    for(auto y: min)
        cout << y << " ";
    cout << endl;
    for(auto y: max)
        cout << y << " ";
    cout << endl;
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
