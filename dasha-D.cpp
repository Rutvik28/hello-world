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
ll id[100005];
ll size[100005];
void initialize(ll n){
    forr(i,0,n+1){
        id[i] = i;
        size[i] = 1;
    }
}
ll root(ll i){
    while(id[i]!=i){
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}
void union1(ll a,ll b){
    ll root_A = root(a),root_B = root(b);
    if(root_A!=root_B){
        if(size[root_A]>size[root_B]){
            id[root_B]=root_A;
            size[root_A]+=size[root_B];
        }else{
            id[root_A]=root_B;
            size[root_B]+=size[root_A];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    initialize(n);
    forr(i,0,k){
        ll u,v;
        cin>>u>>v;
        union1(u,v);
    }
    ll c = 0;
    forr(i,1,n+1){
        if(id[i]==i){
            c++;
        }
    }
    cout<<(k-(n-c))<<'\n';
    return 0;
 
}
