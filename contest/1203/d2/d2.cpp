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
    string s, t;
    cin >> s >> t;
    vector<int>rg(sza(t));
    for(int i = sza(t) - 1; i >= 0; --i) {
    	int pos = sza(s) - 1;
    	if(i + 1 < (int)t.size()) pos = rg[i + 1] - 1; 		// limiting the right bound
    	while(s[pos] != t[i]) --pos;
    	rg[i] = pos;     	
    }      
    int pos = 0;
    int ans = 0;
    for(int i = 0; i < sza(s); i++) {
    	int rpos = sza(s) - 1;				// last section checking i = rg[t.size()] + 1 ... s.size()]
    	if(pos < sza(t))  rpos = rg[pos] - 1;
    	ans = std::max(ans, rpos - i + 1);
    	if(pos < sza(t) && t[pos] == s[i]) ++pos;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
