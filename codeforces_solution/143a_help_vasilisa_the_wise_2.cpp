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

struct node {
    int arr[5];
    int r1, r2, c1, c2, d1, d2;
    void done() {
        r1 = arr[1] + arr[2];
        r2 = arr[3] + arr[4]; 
        c1 = arr[1] + arr[3];
        c2 = arr[2] + arr[4];
        d1 = arr[1] + arr[4];
        d2 = arr[2] + arr[3];
    }
}t[10005];

vector<bool>visited(10, false);
vector<int>brr(10, 0);
int ans = 0;

void dfs(int step) {
    if(step == 4)  {
        for(int i = 0; i < 4; ++i) {
            t[ans].arr[i + 1] = brr[i];
        }
        t[ans].done();
        ++ans;
        return;
    }
    for(int i = 1; i <= 9; ++i) {
        if(!visited[i]) { 
            brr[step] = i;
            visited[i] = true;
            dfs(step + 1); 
            visited[i] = false;
        }
    }
}

void solve() {
    dfs(0);
     int r1, r2, c1, c2, d1, d2;
     bool ok = false;
     cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
     // iterating over all generated ans base
     for(int i = 0; i < ans; ++i) {
        if(t[i].r1 == r1 && t[i].r2 == r2 && t[i].c1 == c1 && t[i].c2 == c2 && t[i].d1 == d1 && t[i].d2 == d2) {
            ok = true;
            cout << t[i].arr[1] << " " << t[i].arr[2] << endl;
            cout << t[i].arr[3] << " " << t[i].arr[4] << endl;
            break;
        }
     }
     if(!ok)
         cout << -1 << endl;
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
