#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define forr(i,k,n) for(ll i=k;i<n;i++)
#define rev(i,k) for(ll i=k;i>=0;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define MX LLONG_MAX
#define MN LLONG_MIN
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define MOD 1000003
using namespace std;
ll powermodm(ll x,ll n,ll M){ll result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
ll modInv(ll x,ll M){
    return powermodm(x,M-2,M);
}
vll adj[3005];
int color[3005];
ll pi[3005];
bool endD = false;
bool cycleVer[3005];
ll dis[3005];
bool visited[3005];
void dfs(ll s){
    color[s]= 1;
    // cout<<s<<'\n';
    forr(i,0,adj[s].size()){
        if(color[adj[s][i]]==0){
            pi[adj[s][i]] = s;
            dfs(adj[s][i]);
        }
        else if(color[adj[s][i]]==1 && adj[s][i]!=pi[s]){
            ll j= s;
            while(j!=adj[s][i]){
                cycleVer[j]=true;
                j=  pi[j];
            }
            cycleVer[adj[s][i]]=true;
            endD = true;
            return;
        }
        if(endD)
            return;
    }
    color[s]=2;
}
void bfs(ll s){
    dis[s] = 0;
    queue<pll> q;
    q.push({s,0});
    visited[s] = true;
    while(!q.empty()){
        pll u = q.front();
        q.pop();
        forr(i,0,adj[u.fi].size()){
            if(!cycleVer[adj[u.fi][i]] && !visited[adj[u.fi][i]]){
                dis[adj[u.fi][i]] = u.se+1;
                visited[adj[u.fi][i]] = true;
                q.push({adj[u.fi][i],u.se+1});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin>>n;
    // forr(i,1,n+1){
    //     color[i] = 'w';
    //     pi[i]=-1;
    //     cycleVer[i] = false;
    // }
    forr(i,0,n){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    // memset(color,'w',sizeof(color));
    // memset(pi,-1,sizeof(pi));
    // memset(cycleVer,false,sizeof(cycleVer));
 
    dfs(1);
    // cout<<"h";
    forr(i,1,n+1){
        if(cycleVer[i]){
            bfs(i);
        }
    }
    forr(i,1,n+1){
        cout<<dis[i]<<" ";
    }
    cout<<'\n';
    return 0;
}
