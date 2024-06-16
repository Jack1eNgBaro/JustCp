#include<bits/stdc++.h>
 
////Ta thuat
//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,fma")
 
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
 
/*
    0: cha -> con
    1: con -> cha
*/
 
int sg[4*N][2];
int leaf[4*N][2];
vector<ii> adj[N];
 
int numnode = 0;    
void build(int id, int l, int r, int type){
    sg[id][type] = ++numnode;
    if(l == r){
        leaf[l][type] = numnode;
        return;
    }
    int m = l + r >> 1;
    build(id << 1, l, m, type);
    build(id << 1 | 1, m + 1, r, type);
    if(type == 0){
        adj[sg[id][type]].pb({sg[id<<1][type], 0});
        adj[sg[id][type]].pb({sg[id<<1|1][type], 0});
    }else{
        adj[sg[id<<1][type]].pb({sg[id][type], 0});
        adj[sg[id<<1|1][type]].pb({sg[id][type], 0});
    }
}
 
#define vi vector<int>
vi merge(vi a, vi b){
    if(a.size() > b.size()) swap(a, b);
    for(auto x: a) b.pb(x);
        return b;
}
 
vi get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return {};
    if(l >= u && r <= v){
        vi ans;
        ans.pb(id);
        return ans;
    }
    int m = l + r >> 1;
    vi g1 = get(id << 1, l, m, u, v);
    vi g2 = get(id << 1 | 1, m + 1, r, u, v);
    return merge(g1, g2);
}
 
int d[N];
int n, Q, s;
 
void solve(){
    cin >> n >> Q >> s;
    build(1, 1, n, 0);
    build(1, 1, n, 1);
 
    For(i,1,n){
        adj[leaf[i][0]].pb({leaf[i][1], 0});
        adj[leaf[i][1]].pb({leaf[i][0], 0});
    }
 
    For(i,1,Q){
        int type; cin >> type;
        if(type == 1){
            int x, y, w; cin >> x >> y >> w;
            //duong di 1 chieu tu u->v
            adj[leaf[x][0]].pb({leaf[y][0], w});
            adj[leaf[x][1]].pb({leaf[y][1], w});
        }else{
            int u, l, r, w; cin >> u >> l >> r >> w;
            vi vec = get(1, 1, n, l, r);
 
            if(type == 2){
                //duong di 1 chieu tu u -> [l, r]
                for(auto x: vec){
                    adj[leaf[u][1]].pb({sg[x][0], w});
                }    
            }else{
                for(auto x: vec){
                    adj[sg[x][1]].pb({leaf[u][0], w});
                }
            }
        }
    }
 
    memset(d, 0x3f, sizeof(d));
 
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, leaf[s][0]});
    int inf = d[leaf[s][0]];
    d[leaf[s][0]] = 0;
 
    while(q.size()){
        auto [dis, u] = q.top(); q.pop();
        if(dis != d[u]) continue;
 
        for(auto [v, w]: adj[u]){
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    For(i,1,n){
        if(d[leaf[i][0]] == inf) cout << "-1 ";
        else cout << d[leaf[i][0]] << " ";
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