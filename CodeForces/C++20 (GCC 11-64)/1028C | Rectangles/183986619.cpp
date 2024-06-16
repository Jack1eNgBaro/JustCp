#include <iostream>
#include <set>
using namespace std;
 
int main()
{
 int a[140000][4], N;
 multiset<int> s[4];
 
 cin >> N;
 
 for(int i = 0; i < N; ++i)
 {
  for(int j = 0; j < 4; ++j)
  {
   cin >> a[i][j];
   s[j].insert(a[i][j]);
  }
 }
 
 for(int i = 0; i < N; ++i)
 {
  for(int j = 0; j < 4; ++j)
  {
   s[j].erase(s[j].find(a[i][j]));
  }
  
  if(*s[0].rbegin() <= *s[2].begin() && *s[1].rbegin() <= *s[3].begin())
  {
   cout<< *s[0].rbegin() << " " << *s[1].rbegin() <<endl;
   break;
  }
  
  for(int j = 0; j < 4; ++j)
  {
   s[j].insert(a[i][j]);
  }
 }
 
 return 0;
}