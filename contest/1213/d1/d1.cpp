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
    int n, k;
    cin >> n >> k;
    vector<int>arr(n);
    for(auto &x: arr)
    	cin >> x;
    vector<int>poss;
    for(int i = 0; i < n; i++) {
    	int x = arr[i];
    	while(x > 0) {
    		poss.push_back(x);
    		x /= 2;
    	}    	
    }
    ll ans = INT_MAX;
    for(auto res: poss) {
    	vector<int> cnt;
    	for(int i = 0; i < n; i++) {
    		int x = arr[i];
    		int divs = 0;
    		while(x > res) {
    			++divs;
    			x /= 2;
    		}
    		if(x == res) {
    			cnt.push_back(divs);
    		}
    	}
    	if(sza(cnt) < k) continue;
    	std::sort(all(cnt));
    	ans = std::min(ans, accumulate(cnt.begin(), cnt.begin() + k, 0LL));
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
