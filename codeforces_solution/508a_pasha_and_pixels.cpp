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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>>arr(n + 1, vector<bool>(m + 1, false));
    auto isInside = [&](int x, int y) -> bool {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };
    int x, y;
    for(int i = 0; i < k; ++i) {
        cin >> x >> y;
        arr[x][y] = true;
        for(int dx = -1; dx <= 1; ++dx) {
            for(int dy = -1; dy <= 1; ++dy) {
                int x1 = x + dx;
                int y1 = y + dy;
                if(isInside(x1, y1) && arr[x1][y1]) {
                    int x2 = x + dx + 1;
                    int y2 = y + dy;
                    if(isInside(x2, y2) && arr[x2][y2]) {
                        int x3 = x + dx;
                        int y3 = y + dy + 1;
                        if(isInside(x3, y3) && arr[x3][y3]) {
                            int x4  = x + dx + 1;
                            int y4 = y + dy + 1;
                            if(isInside(x4, y4) && arr[x4][y4]) {
                                cout << i + 1 << endl;
                                return;
                            }
                        }
                    }
                } 
            }
        }
    }
    cout << 0 << endl;
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
