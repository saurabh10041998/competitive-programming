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

bool comp(pair<int,int> a, pair<int, int> b) {
	return a.first + a.second > b.first + b.second;
}

void solve() {
    int n, r;
    cin >> n >> r;
    vector<pair<int,int>> pos;
    vector<pair<int,int>> neg;
    for(int i = 0; i < n; ++i) {
    	pair<int, int> cur;
    	cin >> cur.first >> cur.second;
    	if(cur.second > 0) { 
    		pos.push_back(cur);
    	}else {
    		cur.first = std::max(cur.first, std::abs(cur.second));
    		neg.push_back(cur);
    	}
    }
    std::sort(all(pos));
    std::sort(all(neg), comp);
    int taken = 0;
    for(int i = 0; i < sza(pos); ++i) {
    	if(r >= pos[i].first) {
    		++taken;
    		r += pos[i].second;
    	}
    }

    vector<vector<int>> dp(neg.size() + 1, vector<int>(r + 1, 0));
    dp[0][r] = taken;
    for(int i = 0; i < sza(neg); ++i) {
    	for(int cr = 0; cr <= r; ++cr) {
    		if(cr >= neg[i].first && cr + neg[i].second >= 0) {
    			dp[i + 1][cr + neg[i].second] = std::max(dp[i + 1][cr + neg[i].second], dp[i][cr] + 1);
    		}
    		dp[i + 1][cr] = std::max(dp[i + 1][cr], dp[i][cr]);
    	}    	
    }
    int ans = 0;
    for(int cr = 0; cr <= r; ++cr)
    	ans = std::max(ans, dp[sza(neg)][cr]);
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
