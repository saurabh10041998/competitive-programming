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


int e_gcd(int a, int b, int &x, int &y) { 
    if(b == 0) { 
        x = 1;
        y = 0;
        return a;   
    }
    int x1, y1;
    int d = e_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return d;
}

void solve() {
    ll a, b, n;
    cin >> n; 
    cin >> a >> b;
    for(ll i = 0; i <= n; ++i) { 
        if(a * i <= n && (n - a * i) % b == 0) { 
            cout << "YES" << endl;
            cout << i << " " << (n - a * i) / b << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
