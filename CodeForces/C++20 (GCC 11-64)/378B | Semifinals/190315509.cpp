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
 
int n;
int a[maxn + 1][2];
int id[maxn + 1][2];
int ok[maxn + 1][2];
 
int main()
{
 file();
 cin >> n;
 vector<int> v;
 for(int i=1;i<=n;i++)
 {
  cin >> a[i][0] >> a[i][1];
  v.push_back(a[i][0]);
  v.push_back(a[i][1]);
 }
 
 sort(v.begin(), v.end());
 for(int i=1;i<=n;i++){
  id[i][0] = lower_bound(v.begin(), v.end(), a[i][0]) - v.begin() + 1;
  id[i][1] = lower_bound(v.begin(), v.end(), a[i][1]) - v.begin() + 1;
 }
  
 for(int i=1;i<=n/2;i++){
  ok[i][0] = ok[i][1] = 1;
 } 
 
 int mx = 0;
 for(int i=0;i<=n/2;i++){
  mx = max(mx, n - 2 * i);
 }
 
 for(int i=1;i<=n;i++){
  if(id[i][0] <= mx) ok[i][0] = 1;
  if(id[i][1] <= mx) ok[i][1] = 1;
 }
 
 for(int i=1;i<=n;i++) cout << ok[i][0]; cout << "\n";
 for(int i=1;i<=n;i++) cout << ok[i][1]; cout << "\n";
 
 return 0;
}