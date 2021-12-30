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


vector<int>rk, p;

ll res; 

int getp(int v) {
	if(v == p[v]) return p[v];
	return p[v] = getp(p[v]);
}

ll get(int x) {
	return x * 1ll * (x - 1) / 2;
}


void merge(int u, int v) {	
	u = getp(u);
	v = getp(v);	
	if(rk[u] < rk[v]) std::swap(u, v);

	res -= get(rk[u]);
	res -= get(rk[v]);

	rk[u] += rk[v];

	res += get(rk[u]);

	p[v] = u;	
}

void solve() {
    int n, m;
    cin >> n >> m;
    res = 0;
    rk = p = vector<int> (n, 1);
    std::iota(all(p), 0);


    vector<pair<int, pair<int, int>>> e(n - 1);
    for(int i = 0; i < n - 1; ++i) {
    	cin >> e[i].second.first >> e[i].second.second >> e[i].first;
    	--e[i].second.first;
    	--e[i].second.second;
    }

    vector<pair<int,int>> q(m);
    for(int i = 0; i < m; ++i) {
    	cin >> q[i].first;
    	q[i].second = i;
    }
    vector<ll> ans(m);
    int pos = 0;
    std::sort(all(e));
    std::sort(all(q));
    for(int i = 0; i < m; ++i) {
    	while(pos < n - 1 && e[pos].first <= q[i].first) {    		
    		int u = e[pos].second.first;
    		int v = e[pos].second.second;
    		merge(u, v);
    		++pos;
    	}
    	ans[q[i].second] = res; 
    }
    for(auto x: ans) cout << x << " ";
    cout << endl;
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
