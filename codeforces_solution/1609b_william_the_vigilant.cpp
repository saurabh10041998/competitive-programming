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
    int n, q;
    cin >> n >> q;
    string str; 
    cin >> str;
    int num = 0;
    for(int i = 0; i < n - 2; ++i) { 
        if(str.substr(i, 3) == "abc")
            num++;
    }
    int t;
    char x;
    for(int i = 0; i < q; ++i) { 
        cin >> t >> x;
        t--;
        for(int j = std::max(0, t - 2); j <= std::min(t, n - 3); ++j) {
            if(str.substr(j, 3) == "abc") {
                num--;
            }
        }
        str[t] = x;
        for(int j = std::max(0, t - 2); j <= std::min(t, n - 3); ++j) {
            if(str.substr(j, 3) == "abc") {
                num++;
            }
        }
        cout << num << endl;
    }
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
