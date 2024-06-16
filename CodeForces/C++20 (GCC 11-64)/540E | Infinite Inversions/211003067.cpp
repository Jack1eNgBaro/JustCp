#include<bits/stdc++.h>
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
const int N = 1e9;
 
unordered_map<int,int> bit;
void add(int id, int val){
 while(id >= 1){
  bit[id] += val;
  id -= id & (-id);
 }
}
 
int get(int id){
 int ans = 0;
 while(id <= N){
  ans += bit[id];
  id += id & (-id);
 }
 return ans;
}
 
map<int,int> mp; //->pos tra ve val
void swap(int a, int b){
 if(mp[a] == 0) mp[a] = a;
 if(mp[b] == 0) mp[b] = b;
 
 int t = mp[b];
 mp[b] = mp[a];
 mp[a] = t;
 
// cout << a << " " << mp[a] << "\n";
// cout << b << " " << mp[b] << "\n";
}
 
vector<pair<int,ii>> a;
int Q;
void solve(){
    cin >> Q;
    vector<int> se;
//    cout << Q << "\n";
    while(Q--){
        int l, r; cin >> l >> r;
        se.pb(l);
        se.pb(r);
        swap(l, r); 
    }
 for(auto x: mp) a.pb({x.fi, {x.se, x.se}});
 
    sort(se.begin(), se.end());
    se.erase(unique(se.begin(), se.end()), se.end());
 
    for(int i=1;i<se.size();i++){
        if(se[i] > se[i-1]+1){
            a.pb({se[i-1]+1, {se[i-1]+1, se[i]-1}});
        }
    }
    
    int ans = 0;
    sort(a.begin(), a.end());
    for(auto it: a){
//     cout << it.fi << " ";
//     cout<< it.se.fi << " " << it.se.se << "\n";
  int nguyenbao = (it.se.fi == it.se.se);
  
  if(nguyenbao){
   ans += get(it.se.fi+1);
   add(it.se.fi, 1);
  }else{
   int l = it.se.fi, r = it.se.se;
   ans += (r-l+1)*get(it.se.se+1);
   add(it.se.fi, r-l+1);
  }
 }
 cout << ans;
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