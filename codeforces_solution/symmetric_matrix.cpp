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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n, m;
    cin >> n >> m;
    bool ok = false;
    for(int i = 0; i < n; ++i) {
        vector<vector<int>> arr(2, vector<int>(2, 0));
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k) {
                cin >> arr[j][k];
            }
        }
        if(arr[0][1] != arr[1][0])
            ok |= false;
        else
            ok |= true;
    }
    ok &= (m % 2 == 0);
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    double start = clock();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    cerr << "[*] Time: " << (clock() * 1.0 - start) / CLOCKS_PER_SEC << std::setprecision(2) << " s" << endl;
    return 0;
}
