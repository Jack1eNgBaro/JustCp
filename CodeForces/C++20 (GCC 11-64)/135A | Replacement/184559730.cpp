#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
   
 int n; cin >> n;
 int a[n]; for(int &i: a) cin >> i;
 int i = max_element(a, a + n) - a;
 if(a[i] == 1)
    a[i] = 2;
 else 
  a[i] = 1;
 sort(a, a + n);
 for(int i: a) cout << i << ' ';
 return 0;
}