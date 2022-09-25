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
    ll n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    ll ones(0), p1_first(INT_MAX), p1_last(-1);
    for(ll i = 0; i < n; ++i) {
        if(str[i] != '1')
            continue;
        ones++;
        if(p1_first == INT_MAX)
            p1_first = i;
        p1_last = i;
    }
    ll add =  0;
    if(ones > 0 && n - 1 - p1_last <= k) {
        k -= n - 1 - p1_last;
        ones--;
        add += 1;
    }
    if(ones > 0 && p1_first <= k) {
        k -= p1_first;
        ones--;
        add += 10;
    }
    cout << 11 * ones + add << endl;
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
