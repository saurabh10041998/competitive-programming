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
    string str1;
    string str2; 
    cin >> str1 >> str2;
    bool check = true;
    int n1 = sza(str1);
    int n2 = sza(str2);
    if(n1 != n2){
        cout << "NO" << endl;
        return;
    }else {
       vector<int>indices;
       int cnt = 0;
       for(int i = 0; i < n1; ++i) { 
           if(str1[i] != str2[i]) { 
                ++cnt;
                indices.push_back(i);
           }
       }
       if(cnt == 2) {
           if((str1[indices[0]] != str2[indices[1]]) ||(str1[indices[1]] != str2[indices[0]])) {
                check = false; 
               
           }
       }else { 
            check = false;
       }
       cout << (check ? "YES" : "NO") << endl;
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
