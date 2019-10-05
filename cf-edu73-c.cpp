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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll q;
    cin>>q;
    while(q--){
        ll c,m,x;
        cin>>c>>m>>x;
        if(c<=m && c<=x){
            cout<<c<<'\n';
        }else if(m<=x){
            cout<<m<<'\n';
        }else{
            if(max(c-x,m-x)>=2*min(c-x,m-x)){
                cout<<(x+min(c-x,m-x))<<'\n';
            }else{
                cout<<(x+(c-x+m-x)/3)<<'\n';
            }
        }
    }
    return 0;
 
}
