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
    vector<vector<ll>>repo;
    repo.push_back(arr);
    ll cnt = 0;
    while(true) {
        map<ll, ll> mp;
        for(ll i = 0; i < n; ++i){
            mp[arr[i]]++;
        }
        map<ll, ll>::iterator itr = mp.begin();
        bool ok = true;
        for(;itr != mp.end(); ++itr){
            if(itr->first != itr->second) { 
                ok = false;
                break;
            }
        }
        if(ok){
            break;
        }
        vector<ll>brr(n); 
        for(ll i = 0; i < n; ++i) {
            brr[i] = mp[arr[i]];
        }
        cnt++;
        repo.push_back(brr);
        arr = brr;
    }
    ll q; 
    cin >> q; 
    for(ll i = 0; i < q; ++i) { 
        ll x, k;
        cin >> x >> k; 
        cout << repo[std::min(cnt, k)][x - 1] << endl;
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
