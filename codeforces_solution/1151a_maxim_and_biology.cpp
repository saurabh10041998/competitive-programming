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
    string str;
    cin >> str;
    int ans = INT_MAX;
    int a, c, t, g;
    int sum;
    for(int i = 0; i < n - 3; ++i) { 
        a = std::abs(str[i] - 'A');
        c = std::abs(str[i + 1] - 'C');
        t = std::abs(str[i + 2] - 'T');
        g = std::abs(str[i + 3] - 'G');
        sum = 0;
        sum += std::min(a, std::abs(26 - a));
        sum += std::min(c, std::abs(26 - c));
        sum += std::min(t, std::abs(26 - t));
        sum += std::min(g, std::abs(26 - g));
        ans = std::min(ans, sum);
    }
    cout << ans << endl;
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
