#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 int tc; cin >> tc;
 while(tc--)
 {
  int n; cin >> n;
  map<int,int> mp;
  vector<int> a(n);
  for(int &i: a)
  {
   cin >> i;
   mp[i]++;
  }
  auto f = *mp.rbegin();
  int x = -1;
  if(f.second >= 2) x = 1; 
  else x = 0;
  
  mp.erase(mp.find(f.first));
  
  int mx = 0;
  if(x == 0){
   auto it = mp.rbegin();
   mx = (*it).first;
  }
  
  for(int i=0;i<n;i++)
  {
   if(a[i] < f.first) a[i] = a[i] - f.first;
   else{
    if(x == 1){
     a[i] = a[i] - f.first;
    }
    else{
     a[i] = a[i] - mx;
    }
   }
  }
  for(int i: a) cout << i << ' '; cout << "\n";
 }
   
 return 0;
}