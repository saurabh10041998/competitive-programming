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
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	vector<int>arr(n - k  + 1);
	int cnt = 0;
	for(int i = 0; i < k; ++i){
		if(str[i] == 'W')
			cnt++;
	}
	arr[0] = cnt;
	int j = 1;
	for(int i = k; i < n; ++i) {
		if(str[i - k] == 'B' && str[i] == 'B'){
			arr[j] = arr[j - 1];
		}
		if(str[i - k] == 'W' && str[i] == 'W'){
			arr[j] = arr[j - 1];
		}
		if(str[i - k] == 'W' && str[i] == 'B') {
			arr[j] = arr[j - 1] - 1;
		}
		if(str[i - k] == 'B' && str[i] == 'W') {
			arr[j] = arr[j - 1] + 1;
		}
		++j;
	}
	int ans = INT_MAX;
	for(int i = 0; i < n - k + 1; ++i) {
		ans = std::min(ans, arr[i]);
	}
	cout << ans << endl;
}

int main() {
    double start = clock();
    int tc = 1;
    cin >> tc;
    while(tc--) {
       solve();
    }
    cerr << "[*] Time: " << (clock() * 1.0 - start) / CLOCKS_PER_SEC << std::setprecision(3) << " s" << endl;
    return 0;
}
