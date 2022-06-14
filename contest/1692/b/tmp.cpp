#include<bits/stdc++.h>
using namespace std;

int main(){
  map<int,int>mp;
  mp[3]=1;
  mp[4]=1;
  mp[5]=1;
  mp[6]=1;
  mp[7]=1;
  
  for(auto x: mp) 
    mp[x.first] = 0;
  for(auto x: mp)
    cout << x.first << " " << x.second << endl;
  return 0;
}
