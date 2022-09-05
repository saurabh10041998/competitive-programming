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
    int n; 
    cin >> n; 
    vector<pair<int, int>>arr(n);
    vector<vector<int>>dp(n + 1, vector<int>(n + 1, false));
    for(int i = 0; i < n; ++i) { 
        cin >> arr[i].first >> arr[i].second;
        dp[arr[i].first][arr[i].second] = true;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = arr[i].first; j <= arr[i].second; ++j) {
            if((j == arr[i].first or dp[arr[i].first][j - 1]) and (j == arr[i].second or dp[j + 1][arr[i].second])) {
                cout << arr[i].first << " " << arr[i].second << " " << j << endl;
                break;
            }
        }
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
