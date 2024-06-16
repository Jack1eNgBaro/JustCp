/*
  The only thing we have to fear is fear itself.
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
 
struct ele{
 int val, id;
};
int cmp(ele a, ele b){
 return a.val < b.val;
}
 
int main()
{
 file();
 int tc; cin >> tc;
 while(tc--){
  int n, k; cin >> n >> k;
  ele a[n];
  for(int i=0;i<n;i++){
   cin >> a[i].val;
   a[i].id = i;
  }
  sort(a, a + n, cmp);
  vector<int> pos(n), b(n);
  for(int &i: b) cin >> i;
  sort(b.begin(), b.end());
  
  for(int i=0;i<n;i++){
   pos[a[i].id] = b[i];
  }
  
  for(auto x: pos) cout << x << ' '; cout << "\n";
  
 }
 
 return 0;
}