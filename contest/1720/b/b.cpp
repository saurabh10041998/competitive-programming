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
    ll n,x, ans;
    cin >> n;
    set<pair<ll, ll>>st;
    for(ll i = 0; i < n; ++i) {
        cin >> x;
        st.insert({x, i});
    }
    set<pair<ll,ll>>::iterator itr = st.begin();
    set<pair<ll, ll>>::reverse_iterator ritr = st.rbegin();
    // this is crazy..
    pair<pair<ll,ll>, pair<ll,ll>>mima;
    pair<pair<ll,ll>, pair<ll,ll>>smima;
    mima.first.first = itr->first;
    mima.first.second = itr->second;
    
    itr++;
    smima.first.first = itr->first;
    smima.first.second = itr->second;

    mima.second.first = ritr->first;
    mima.second.second = ritr->second;

    ritr++;
    smima.second.first = ritr->first;
    smima.second.second = ritr->second;
    
    ll l1 = mima.first.second;
    ll r1 = mima.second.second;

    if(l1 > r1)
        std::swap(l1, r1);

    ll l2 = smima.first.second;
    ll r2 = smima.second.second;

    if(l2 > r2)
        std::swap(l2, r2);
    
    if(r1 < l2 || r2  < l1) {
        ll d1 = mima.second.first - mima.first.first;
        ll d2 = smima.second.first - smima.first.first;
        ans = d1  + d2;    
    } else if((l1 < l2 && r2 < r1) || (l2 < l1 && r1 < r2)) {
        ll d1 = mima.second.first - mima.first.first;
        ll d2 = smima.second.first - smima.first.first;
        ans = d1  + d2;    
    }else {
        ll d1 = smima.second.first - mima.first.first;
        ll d2 = mima.second.first - smima.first.first;
        ans = d1 + d2;
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
