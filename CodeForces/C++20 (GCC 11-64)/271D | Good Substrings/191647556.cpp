#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
 
const int maxn = 1e5;
const int mod = 1e9 + 7;
 
string s, t;
int k;
 
int good(char c){
 return t[c - 'a'] == '1';
}
 
struct Node{
 Node* next[30];
};
typedef Node* node;
 
main(){
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
 std::ios::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 
 cin >> s >> t >> k;
 int n = s.size();
 node head = new Node();
 
 int ans = 0;
 for(int i=0;i<n;i++)
 {
  node p = head;
  int cnt = 0;
  for(int j=i;j<n;j++){
   if(!good(s[j])) ++cnt;
   if(cnt > k) break;
   
   int c = s[j] - 'a';
   if(p->next[c] == NULL){
    ++ans;
    p->next[c] = new Node();
   }
   p = p->next[c];
  }
 }
 cout << ans;
 return 0;
}