#include <bits/stdc++.h>

using namespace std;

#define LOCAL true

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

map<char, string> hundreds;
map<char, string> tens;
map<string, string> ones;
map<char, string> digs;

void populate_hundreds() {
  hundreds['1'] = "One";
  hundreds['2'] = "Two";
  hundreds['3'] = "Three";
  hundreds['4'] = "Four";
  hundreds['5'] = "Five";
  hundreds['6'] = "Six";
  hundreds['7'] = "Seven";
  hundreds['8'] = "Eight";
  hundreds['9'] = "Nine";
}

void populate_tens() {
  tens['2'] = "Twenty";
  tens['3'] = "Thirty";
  tens['4'] = "Forty";
  tens['5'] = "Fifty";
  tens['6'] = "Sixty";
  tens['7'] = "Seventy";
  tens['8'] = "Eighty";
  tens['9'] = "Ninety";
}

void populate_ones() { 
  ones["10"] = "Ten";
  ones["11"] = "Eleven";
  ones["12"] = "Twelve";
  ones["13"] = "Thirteen";
  ones["14"] = "Fourteen";
  ones["15"] = "Fifteen";
  ones["16"] = "Sixteen";
  ones["17"] = "Seventeen";
  ones["18"] = "Eighteen";
  ones["19"] = "Nineteen";
}

void populate_digs() {
  digs['1'] = "One";
  digs['2'] = "Two";
  digs['3'] = "Three";
  digs['4'] = "Four";
  digs['5'] = "Five";
  digs['6'] = "Six";
  digs['7'] = "Seven";
  digs['8'] = "Eight";
  digs['9'] = "Nine";
}

string rtrim(const string &s) {
  return std::regex_replace(s, regex("\\s+$"),string(""));
}

string numberToWords(int x) {
  populate_hundreds();
  populate_tens();
  populate_ones();
  populate_digs();
  string nums = to_string(x);
  int n = nums.size();
  int j = 0;
  string billions = "";
  string millions = "";
  string thousands = "";
  string hundredss = "";
  while(j < nums.size()){
    if((n - j) == 10) {
      // billions part
      billions = digs[nums[j]];
      billions += " Billion";
      j++;
    }
    if((n - j) > 6 && (n - j) <= 9) {
      if((n - j) == 9) {
        if(nums[j] - '0' > 0) {
          millions = hundreds[nums[j]];
          millions += " Hundred";
        }
        j++;
      }
      if((n - j) == 8) {
        if((nums[j] - '0') > 1) {
          millions += " " + tens[nums[j]];
          j++;
        }else{
          if(nums[j] == '1') {
            millions += " " + ones[nums.substr(j,2)];
            j += 2;
          }else 
            j += 1;
        }
      }
      if((n - j) == 7) {
        if(nums[j] - '0' > 0)
          millions += " " + digs[nums[j]];
        j++;
        
      }
      if(millions != "")
        millions += " Million";  
    }

    if((n - j) > 3 && (n - j) <= 6) {
      if((n - j) == 6) {
        if(nums[j] - '0' > 0) {
          thousands = hundreds[nums[j]];
          thousands += " Hundred";
        }
        j++;
      }
      if((n - j) == 5) {
        if(nums[j] - '0' > 1){
          thousands += " " + tens[nums[j]];
          j += 1;
        }else {
          if(nums[j] - '0' == 1) {
            thousands += " " + ones[nums.substr(j, 2)];
            j += 2;
          }else 
            j += 1;
        }
      }
      if((n - j) == 4) {
        if(nums[j] - '0' >= 1)
          thousands += " " + digs[nums[j]]; 
        j++;
      }
      if(thousands != "")
        thousands += " Thousand";
    }
    if((n - j) > 0 && (n - j) <= 3) {
      if((n - j) == 3) {
        if(nums[j] - '0' > 0) {
          hundredss = hundreds[nums[j]];
          hundredss += " Hundred";
        }
        j++;
      }
      if((n - j) == 2) {
        if(nums[j] - '0' > 1){
          hundredss += " " + tens[nums[j]];
          j += 1;
        }else {
          if(nums[j] - '0' == 1) {
            hundredss += " " + ones[nums.substr(j, 2)];
            j += 2;
          }else 
            j += 1;
        }
      }
      if((n - j) == 1) {
        if(nums[j] - '0' >= 1)
          hundredss += " " + digs[nums[j]]; 
        j++;
      }
    }
    j++;

  }
  string raw_ans = billions + " " +  millions + " " +  thousands + " "  + hundredss;
  stringstream sstr(raw_ans);
  string ans, word;
  while(sstr >> word) {
    ans += word;
    ans += " ";
  }
  return rtrim(ans);
}

void solve() {
  string ans = numberToWords(1);
  cout << ans << endl;
  
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
