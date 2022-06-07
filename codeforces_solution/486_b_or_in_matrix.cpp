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
		int n, m, x;
		cin >> n >> m;
		vector<vector<int>>brr(n, vector<int>(m));
		vector<vector<int>>arr(n, vector<int>(m,1));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cin >> brr[i][j];
			}
		}
		for(int i = 0; i < n; ++i) { 
			for(int j = 0; j < m; ++j) { 
				if(!brr[i][j]) {
					for(int k = 0; k < m; ++k)
						arr[i][k] = 0;
					for(int k = 0; k < n; ++k)
						arr[k][j] = 0;
				}
			}
		}
		bool flag = true;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				int ans = 0;
				for(int k = 0; k < m; ++k)
					ans |= arr[i][k];
				for(int k = 0; k < n; ++k)
					ans |= arr[k][j];
				if(ans != brr[i][j]) {
					flag = false;
					break;
				}

			}
			if(!flag)
				break;
		}
		if(!flag)
			cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
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
