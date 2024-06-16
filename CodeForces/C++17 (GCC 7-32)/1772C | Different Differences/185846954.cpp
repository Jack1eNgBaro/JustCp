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
  int k, n; cin >> k >> n;
  vector<int> v;
  v.push_back(n);
  
  for(int i=1; 
   v.size() < k && v.back() - i > 0 && v.size() + v.back()-i >= k;
    ++i)
   v.push_back(v.back() - i);
  for(int i=v.back()-1; v.size() < k; --i) v.push_back(i);
  
  sort(v.begin(), v.end());
  
  set<int> se;
  for(auto x: v) cout << x << " "; cout << "\n";
  for(int i=1;i<k;i++) se.insert(v[i] - v[i - 1]);
//  cout << ": " << se.size() << "\n";
 }
 return 0;
}