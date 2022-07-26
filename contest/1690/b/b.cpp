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
	vector<int>arr(n);
	vector<int>brr(n);
	bool ok = true;
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for(int i = 0; i < n; ++i) {
		cin >> brr[i];
		if(arr[i] < brr[i])
			ok = false;
	}
	if(!ok) {
		cout << "NO" << endl;
	}else {
		int max_diff = -1;
		for(int i = 0; i < n; ++i) {
			max_diff = std::max(max_diff, arr[i] - brr[i]);
		}
		for(int i = 0; i < n; ++i) {
			arr[i] = std::max(0, arr[i] - max_diff);
		}
		bool ok = true;
		for(int i = 0; i < n; ++i) {
			if(arr[i] != brr[i]) {
				ok = false;
				break;
			}
		}
		cout << (ok ? "YES": "NO") << endl;
	}
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