#include<bits/stdc++.h>
using namespace std;
 
int mCheck(int x, int a, int b){
    return (x >= a && x <= b);
}
 
int main(){
    int t; cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        
        if(a == c || a == d 
           || b == c || b == d){
               cout << "YES\n";
               continue;
           }
        
        int x = mCheck(a, c, d);
        int y = mCheck(b, c, d);
        cout << (x != y ? "YES\n" : "NO\n");
        
    }
}
 