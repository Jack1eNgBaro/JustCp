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
 int tc; cin >> tc;
 while(tc--)
 {
  int n, k; cin >> n >> k;
  int a[n], b[n];
  for(int &i: a) cin >> i;
  for(int &i: b) cin >> i;
  
  int mx = *max_element(a, a + n);
  priority_queue<pii, vector<pii>, greater<pii>> q;
  for(int i=0;i<n;i++){
   q.push({b[i], a[i]});
  }
  
  int sum = k;
  while(q.size())
  {
   while(q.size() && q.top().second <= sum) q.pop();
   if(q.size() && k >= q.top().first){
    k -= q.top().first;
    sum += k;
   }
   else break;
//   cout << k << ' ';
  } 
  if(sum >= mx) cout << "YES\n";
  else cout << "NO\n";
 }
 return 0;
}