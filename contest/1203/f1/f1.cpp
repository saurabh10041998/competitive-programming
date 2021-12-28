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
    vector<pair<int, int>> pos;
    vector<pair<int, int>> neg;
    int a, b;
    for(int i = 0; i < n; ++i) {
    	cin >> a >> b;
    	pair<int, int> cur = make_pair(a,b);
    	if(cur.second > 0) {
    		pos.push_back(cur);
    	}else {
    		cur.first = std::max(cur.first, std::abs(cur.second));				// maximum degrade of rating
    		neg.push_back(cur);
    	}
    }
    std::sort(all(pos));
    std::sort(all(neg), comp);				// reverse sort according the damage a + b;

    int taken = 0;
    // collection of positive rating process
    for(int i = 0; i < sza(pos); ++i) {
    	if(r >= pos[i].first){ 
    		++taken;
    		r += pos[i].second;
    	}
    }

    // initializing the dp size = |neg.size() + 1 | * (current rating  + 1)
    vector<vector<int>> dp(sza(neg) + 1, vector<int>(r + 1, 0));
    dp[0][r] = taken; 			// number of projects taken
    for(int i = 0; i < sza(neg); ++i) {
    	for(int cr = 0; cr <= r; ++cr) {
    		// whether I have sufficient cr to take up the current project..
    		if(cr >= neg[i].first && cr + neg[i].second >= 0) {	
    			// final state = max(final state reached taking the project diff route, current state project taken + 1)		
    			dp[i + 1][cr + neg[i].second] = std::max(dp[i + 1][cr + neg[i].second], dp[i][cr] + 1);
    		}
    		// carry forward the previous state(if they are significant) to next row in matrix
    		dp[i + 1][cr] = std::max(dp[i + 1][cr], dp[i][cr]);
    	}
    }
    int ans = 0;
    for(int i = 0; i <= r; i++)
    	ans = std::max(ans, dp[(int)neg.size()][i]);
    cout << (ans == n ? "YES" : "NO") << endl;
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
