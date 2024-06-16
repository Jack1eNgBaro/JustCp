#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int main()
{
 file();
 pii a, b;
   cin >> a.first >> a.second;
  cin >> b.first >> b.second;
  
 if(a.first == b.first){
  int edge = abs(a.second - b.second);
  cout << a.first + edge << " " << a.second << " ";
  cout << b.first + edge << " " << b.second << " ";
  return 0;
 }
 
 if(a.second == b.second){
  int edge = abs(a.first - b.first);
  cout << a.first << " " << a.second + edge << " ";
  cout << b.first << " " << b.second + edge << " ";
  return 0;
 }
 
 if(a > b) swap(a, b); 
 int kx = abs(a.first - b.first);
 int ky = abs(a.second - b.second);
 if(kx == ky){
  if(a.second < b.second){
   cout << a.first << ' ' << a.second + kx << " ";
   cout << b.first << ' ' << b.second - ky << " ";
   return 0;
  }
  else{
   cout << a.first << ' ' << a.second - kx << " ";
   cout << b.first << ' ' << b.second + ky << " ";
   return 0;
  }
 }
 
 cout << -1;
 return 0;
}