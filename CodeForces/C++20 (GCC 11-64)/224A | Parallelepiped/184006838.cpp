#include<bits/stdc++.h>
using namespace std;
 
int main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
   
 int s1, s2, s3; cin >> s1 >> s2 >> s3;
 
 int a = sqrt(s1 * s3 / s2);
 int b = sqrt(s1 * s2 / s3);
 int c = sqrt(s2 * s3 / s1);
 
 cout << 4*(a + b + c);  
   
 return 0;
}