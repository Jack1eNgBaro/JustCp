#include<bits/stdc++.h>
using namespace std;
const int maxn = 132674;
int a[maxn + 1][4];
 
int main()
{ 
 multiset<int> ms[4];
 
 int n; cin >> n;
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<4;j++)
  {
   cin >> a[i][j];
   ms[j].insert(a[i][j]);
  }
 }
 
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<4;j++)
   ms[j].erase(ms[j].find(a[i][j]));
   
  int ix = *ms[2].begin() - *ms[0].rbegin();
  int iy = *ms[3].begin() - *ms[1].rbegin();
  if(ix >= 0 && iy >= 0){
   cout << *ms[0].rbegin() << ' ' << *ms[1].rbegin();
   return 0;
  }
  
  for(int j=0;j<4;j++)
   ms[j].insert(a[i][j]);
 }
 
 return 0;
}