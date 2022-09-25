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
    int n, x;
    cin >> n  >> x;
    vector<int>arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<int>maxx(n + 1, INT_MIN);
    maxx[0] = 0;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum = 0;
        for(int j = i; j < n; ++j) { 
            sum += arr[j]; 
            maxx[j - i + 1]  = std::max(maxx[j - i + 1], sum);
        }
    }
    vector<int>ans(n + 1);
    for(int k = 0; k <= n; ++k) {
        int bst = 0;
        for(int i = 0; i <= n; ++i) { 
            bst = std::max(bst, maxx[i] + std::min(i, k) * x);
        }
        ans[k] = bst;
    }
    for(int i = 0; i <= n; ++i)
        cout << ans[i] << " \n"[i == n];
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
