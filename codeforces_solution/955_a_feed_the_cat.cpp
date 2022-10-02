#include <bits/stdc++.h>
#define LOCAL true
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
    int hh, mm;
    cin >> hh >> mm;
    hh = hh * 60 + mm;
    int h, d, c, n;
    cin >> h >> d >> c >> n;
    double ans = 0;
    if(hh >= 1200) { 
        ll p1 = (h / n + (h % n != 0));
        ans = p1 * c * 0.8;
    }else {
        ll p21 = h + (1200 - hh) * d;
        double p2 = (p21 / n + (p21 % n != 0)) * c * 0.8;
        double p1 = (h / n + (h % n != 0));
        p1 = p1 * c;
        //dbg(p1, p2);
        ans = std::min(p1, p2);
    }
    printf("%.4f\n", ans);
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
