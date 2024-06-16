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
 
int pf[maxn + 1];
int main()
{
 file();
 int n; cin >> n; 
 if(n & 1){
  return cout << "No\n", 0;
 }
 
 int m = 0, k = 0;
 for(int i=1;i<=n;i++)
 {
  char ch; cin >> ch;
  int x = ch == '(' ? 1 : -1;
  if(x == 1){
   ++k;
  }else{
   --k;
  }
  m = min(m, k);
 }
 if(k == 0 && m >= -1){
  cout << "Yes\n";
 }else{
  cout << "No\n";
 }
 
 return 0;
}