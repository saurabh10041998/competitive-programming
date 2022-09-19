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
    int n, n1, n2;
    cin >> n >> n1 >> n2; 
    int x;
    priority_queue<int,vector<int>>pq;
    for(int i = 0; i < n; ++i){ 
        cin >> x;
        pq.push(x);
    }
    if(n1 < n2) {
        double sum = 0;
        double m1, m2;
        for(int i =  0; i < n1; ++i) {
            sum += pq.top();
            pq.pop();
        }
        m1 = sum / (n1 * 1.0);
        sum = 0;
        for(int i = 0; i < n2; ++i) {
            sum += pq.top();
            pq.pop();
        }
        m2 = sum / (n2 * 1.0);
        printf("%.6lf\n", m1 + m2);
    }else {
        double sum = 0;
        double m1, m2;
        for(int i = 0; i < n2; ++i) {
            sum += pq.top();
            pq.pop();
        }
        m1 = sum / (n2 * 1.0);
        sum = 0;
        for(int i =  0; i < n1; ++i) {
            sum += pq.top();
            pq.pop();
        }
        m2 = sum / (n1 * 1.0);
        printf("%.6lf\n",m1 + m2);
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
