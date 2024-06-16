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
 
char s[maxn + 1];
int main()
{
 file(); 
 int n, k; cin >> n >> k;
 
 stack<int> st;
 vector<pii> v;
 
 for(int i=0;i<n;i++)
 {
  cin >> s[i];
  if(s[i] == '(')
   st.push(i);
  else{
   v.push_back({st.top(), i}); st.pop();
  }
 }
 
 sort(v.begin(), v.end());
// for(auto x: v) cout << x.first << ' ' << x.second <<"\n";
 
 vector<int> a;
 int i = 0;
 while(a.size() < k){
  a.push_back(v[i].first);
  a.push_back(v[i].second);
  i++;
 }
 sort(a.begin(), a.end());
 for(auto x: a) cout << s[x];
 
 return 0;
}