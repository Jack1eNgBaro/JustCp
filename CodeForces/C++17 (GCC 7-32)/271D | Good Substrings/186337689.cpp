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
 
string s, t;
int k;
 
struct Node{
 Node *next[30]; 
};
typedef Node* node;
 
bool isgood(char c){
 if(t[c-'a'] == '1') return 1;
 return 0;
}
 
int main()
{
 file();
 cin >> s >> t >> k;
 node head = new Node();
 
 int ans = 0;
 for(int i=0;i<s.size();i++)
 {
  int cnt = 0;
  node p = head;
  for(int j=i;j<s.size();j++){
   if(!isgood(s[j])) ++cnt;
   if(cnt > k) break;
   
   int c = s[j] - 'a';
   if(p->next[c] == NULL){
    p->next[c] = new Node();
    ans++;
   }
   p = p->next[c];
  }
 }
 cout << ans;
 return 0;
}