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
    map<string, string> winning_combos;
    winning_combos["rock"] = "scissors";
    winning_combos["scissors"] = "paper";
    winning_combos["paper"] = "rock";
    map<int, string>player_codes;
    player_codes[0] = "F";
    player_codes[1] = "M";
    player_codes[2] = "S";
    player_codes[-1] = "?";
    
    vector<string>choices(3);
    cin >> choices[0] >> choices[1] >> choices[2];
    
    if(choices[1] == winning_combos[choices[0]] && choices[2] == winning_combos[choices[0]]) {
        cout << player_codes[0] << endl;
    }else if(choices[0] == winning_combos[choices[1]] && choices[2] == winning_combos[choices[1]]) {
        cout << player_codes[1] << endl;
    }else if(choices[0] == winning_combos[choices[2]] && choices[1] == winning_combos[choices[2]]) {
        cout << player_codes[2] << endl;
    }else {
        cout << player_codes[-1] << endl;
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
