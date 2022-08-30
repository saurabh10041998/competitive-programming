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
    int n, m, sx, sy; 
    cin >> n >> m >> sx >> sy; 
    vector<vector<bool>>grid(n + 1, vector<bool>(m + 1, false)); 
    auto check = [&](int x1, int x2) -> bool { 
        if(x1 < 1 || x1 > n) return false;
        else if (x1 < 1 || x2 > m) return false;
        return grid[x1][x2] == false;
    };
    vector<pair<int, int>> ans;
    for(int i  = sx, j = sy; ;) {
        if(grid[i][j]) break;
        ans.push_back({i, j});
        grid[i][j] = true;
        for(int k = j + 1; k <= m; ++k) {
            if(check(i, k)) {
                ans.push_back({i, k});
                grid[i][k] = true;
                j = k;
            }
        }
        for(int k  = j - 1; k >= 1; --k) {
            if(check(i, k)) {
                ans.push_back({i, k});
                grid[i][k] = true;
                j = k;
            }
        }
        for(int k = 1; k <= n; ++k) {
            if(check(k, j)) {
                i = k;
                break;
            }
        }
    }
    assert(ans.size() == n * m);
    for(auto p: ans)
        cout << p.first << " " << p.second << endl;
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
