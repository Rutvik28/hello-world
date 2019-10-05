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
#define MOD 1000000007
using namespace std;
ll powermodm(ll x,ll n,ll M){ll result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll adj[n+1][n+1];
    forr(i,1,n+1){
        forr(j,1,n+1){
            char ch;
            cin>>ch;
            adj[i][j] = ch-'0';
        }
    }
    ll dis[n+1][n+1];
    forr(i,1,n+1){
        forr(j,1,n+1){
 
            if(adj[i][j]==0)
                dis[i][j]=1000000;
            else
                dis[i][j] = 1;
        }
    }
    forr(k,1,n+1){
        forr(i,1,n+1){
            forr(j,1,n+1){
                if(i!=j)
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    // forr(i,1,n+1){
    //     forr(j,1,n+1){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    ll m;
    cin>>m;
    ll p[m];
    forr(i,0,m){
        cin>>p[i];
    }
    forr(i,1,n+1){
        dis[i][i] =0;
    }
    vll ans;
    bool f= false;
    ans.pb(0);
    // cout<<1<<'\n';
    forr(i,1,m){
        
            if(dis[p[ans.back()]][p[i]]<i-ans.back()){
                ans.pb(i-1);
                // i--;
            }
            // cout<<dis[p[ans.back()]][i]<<"\n";
        
    }
    ans.pb(m-1);
    // cout<<ans.size()<<" "<<f<<'\n';
    // if(!f){
    //     ans.pb(m-1);
    // }else{
    //     ll j=ans.size()-1;
    //     while(j>=0){
    //         if(f){
    //             bool f1 = false;
    //             for(ll i=ans[j];i>=ans[j-1];i--){
    //                 if(dis[p[i]][p[m-1]]==m-1-i){
    //                     ans.pop_back();
    //                     ans.push_back(i);
    //                     f1 = true;
    //                     break;
    //                 }
    //             }
    //             if(f1){
    //                 break;
    //             }
    //             ans.pop_back();
    //             f = !f;
    //             j--;
    //         }else{
    //             if(dis[p[ans[j]]][p[m-1]]==m-1-j){
    //                 break;
    //             }else{
    //                 ans.pop_back();
    //                 j--;
    //                 f = !f;
    //             }
    //         }
    //     }
    //     ans.push_back(m-1);
        
    // }
    cout<<ans.size()<<'\n';
        forr(i,0,ans.size()){
            cout<<p[ans[i]]<<" ";
        }
        cout<<'\n';
    return 0;
}
