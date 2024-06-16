#include<bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#define MOD 1000000007
#define fi first
#define se second
#define int long long
#define ii pair<int,int>
#define Dennis ""
#define heap_max(a) priority_queue<a>
#define heap_min(a) priority_queue<a, vector<a>, greater <a>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define el cout << '\n'
#define rep(i, n) for(int i = 0; i < (n); i++)
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Fod(i, a, b) for(int i = (a); i >= (b); i--)
#define bit(x, i) ((x >> i) & 1)
 
using namespace std;
template <class X, class Y> bool minimize(X &a, Y b){
    if (a > b) return a = b, true;
    return false;
}
template <class X, class Y> bool maximize(X &a, Y b){
    if (a < b) return a = b, true;
    return false;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {return l + rng() % (r - l + 1);}
const int N = 1e6 + 5;
 
#define vi vector<int> 
 
struct Node{
 Node* next[2];
 int cnt = 0;
};
typedef Node* node;
 
node head = new Node();
 
void add(int val){
 node p = head;
 Fod(i,31,0){
  int x = bit(val, i);
  if(p->next[x] == NULL){
   p->next[x] = new Node();
  }
  p = p->next[x];
  p->cnt++;
 }
}
 
void del(int val){
 node p = head;
 Fod(i,31,0){
  int x = bit(val, i);
  if(p->next[x] == NULL){
   return;
  }
  p = p->next[x];
  p->cnt--;
 }
}
 
int query(int pp, int ll){
 node p = head;
 int ans = 0;
 Fod(i,31,0){
  int x = bit(ll, i);
  int y = bit(pp, i);
  if(x == 1){
   if(p->next[y] != NULL){
    ans += p->next[y]->cnt;
   }
  }
  if(p->next[x^y] == NULL) break;
  p = p->next[x^y];
 }
 return ans;
}
 
void solve(){
    int q; cin >> q;
    while(q--){
     int t, p; cin >> t >> p;
     if(t == 1) add(p);
     else if(t == 2) del(p);
  else{
   int l; cin >> l;
   cout << query(p, l) << "\n";
  }    
    }
}
 
main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int bla = uniform_int_distribution<int>(1, 100)(rng);
    #define TASK ""
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}