#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define debug(x,len) cout<<#x<<": ";for(int i=0;i<=(len);i++)cout<<(x)[i]<<" ";puts("");
#define lowbit(x) ((-(x))&(x))
const int INF = 0x3f3f3f3f;

const int MAX=2e5+10;

ll tr1[MAX],tr2[MAX],a[MAX],sum[MAX],n,m;

void add1(ll x,ll c){
    for(int i=x;i<=n;i+=lowbit(i)) tr1[i]+=c;

    return;
}

void add2(ll x,ll c){
    for(int i=x;i<=n;i+=lowbit(i)) tr2[i]+=c;

    return;
}

ll query1(ll x){
    ll res=0;
    for(int i=x;i;i-=lowbit(i)) res+=tr1[i];
    
    return res;
}

ll query2(ll x){
    ll res=0;
    for(int i=x;i;i-=lowbit(i)) res+=tr2[i];
    
    return res;
}

int main(void){
#ifndef _LOCAL 
   std::ios::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
#endif

   
    scanf("%lld%lld",&n,&m);
   
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    
    for(int i=1;i<=m;i++){
        char op[2];ll l,r,c;
        scanf("%s%lld%lld",op,&l,&r);
        if(op[0]=='C'){
            scanf("%lld",&c);
            add1(l,c),add1(r+1,-c);
            add2(l,c*l),add2(r+1,-(r+1)*c);
        } else{
            ll ans = query1(r)*(ll)(r+1)-query2(r)-(query1(l-1)*(ll)(l+1-1)-query2(l-1));

            printf("%lld\n",ans+sum[r]-sum[l-1]);
        }
    }


    return 0;
}