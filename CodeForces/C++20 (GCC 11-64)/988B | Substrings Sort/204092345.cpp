/*
  "There is no light without dark
  There is no joy without pain
  You can't have a rainbow without a little rain"
         ~ Andrew Tate
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int,int>
#define bit(x, i) ((x >> i) & 1)
 
const int mod = 1e9 + 7;
const int maxn = 1e6;
const int base = 31;
 
void file()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
}
 
int cmp(string a, string b){
 if(a.size() != b.size()) return a.size() < b.size();
 return a < b;
}
 
string a[maxn + 1];
int main()
{
 file();
 int n; cin >> n;
 for(int i=1;i<=n;i++) cin >> a[i];
 sort(a + 1, a + n + 1, cmp);
 for(int i=1;i<n;i++){
  int ok = 0;
  for(int j=i+1;j<=n;j++){
   if(a[j].find(a[i]) != -1){
    ok = 1;
    break;
   }
  }
  if(!ok) return cout << "NO\n", 0;
 }
 for(int i=2;i<=n;i++){
  for(int j=1;j<i;j++){
   if(a[i].find(a[j]) == -1) return cout << "NO\n", 0;
  }
 }
 
 
 cout << "YES\n";
 for(int i=1;i<=n;i++) cout << a[i] << "\n";
 return 0;
}