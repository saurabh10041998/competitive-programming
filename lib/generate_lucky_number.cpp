#include <bits/stdc++.h>

#define LOCAL true

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

vector<ll>lucky_numbers;

string bin(ll x) { 
    string ans = "";
    while(x != 0) {
        ans += ('0' + x % 2);
        x /= 2;
    }
    std::reverse(all(ans));
    return ans;
}

void generate_lucky_numbers() {
    lucky_numbers.push_back(0);
    for(ll i = 1; i <= 11; ++i){
        for(ll j = 0; j < (1 << i); ++j) {
            string str_ = bin(j); 
            string tmp = std::string(i - std::min(i, (ll)str_.size()), '0') + str_;
            regex re0("0"), re1("1");
            tmp = regex_replace(tmp, re0, "4");
            tmp = regex_replace(tmp, re1, "7");
            std::stringstream sstr(tmp);
            ll number;
            sstr >> number;
            //dbg(number);
            lucky_numbers.push_back(number);
        }
    }
}


void solve() {
    generate_lucky_numbers();
    dbg(lucky_numbers);
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
