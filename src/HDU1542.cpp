#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define debug(x,len) cout<<#x<<": ";for(int i=0;i<=(len);i++)cout<<(x)[i]<<" ";puts("");
#define lowbit(x) ((-(x))&(x))
const int INF = 0x3f3f3f3f;

const int MAX = 1e6+10;
struct seg{
    double x,y1,y2;
    int cnt;
    bool operator< (const seg b) const{
        return this->x < b.x;
    }
}segs[2*MAX];
ll n;
vector<double> ve;

struct node{
    ll l,r,cnt;
    double len;
}tr[8*MAX];

ll find(double y){
    return lower_bound(ve.begin(),ve.end(),y)-ve.begin();
}

void build(ll u,ll l,ll r){
    tr[u].l = l,tr[u].r=r;
    if(l==r){
        tr[u].cnt=0;tr[u].len=0;
        return;
    }
    ll mid=(l+r)>>1;
    tr[u].cnt=0;tr[u].len=0;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    
    return;
}

void pushup(ll u){
    if(tr[u].cnt) tr[u].len = ve[tr[u].r+1]-ve[tr[u].l];
    else if(tr[u].l != tr[u].r){
        tr[u].len = tr[u<<1].len + tr[u<<1|1].len; 
    }
    else{
        tr[u].len = 0;
    }
}

void modify(ll u,ll l,ll r,ll v){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].cnt+=v;
        pushup(u);
    }
    else{
        ll mid = (tr[u].l+tr[u].r)>>1;
        if(l<=mid) modify(u<<1,l,r,v);
        if(r>mid) modify(u<<1|1,l,r,v);
        pushup(u);
    }
}

double solve(){
    double x1,x2,y1,y2;
    double res=0;
    for(int i=1,j=0;i<=n;i++){
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        segs[j++] = {x1,y1,y2,1};
        segs[j++] = {x2,y1,y2,-1};
        ve.push_back(y1),ve.push_back(y2);
    }
    
    sort(ve.begin(),ve.end());
    sort(segs,segs+n*2);
    ve.erase(unique(ve.begin(),ve.end()),ve.end());
    build(1,0,ve.size()-2);

    for(int i=0;i<n*2;i++){
        if(i>0) res+=tr[1].len*(segs[i].x-segs[i-1].x);
        modify(1,find(segs[i].y1),find(segs[i].y2)-1,segs[i].cnt);
    }
    return res;
}

int main(void){
#ifndef _LOCAL 
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif

    ll cnt=1;
    while(scanf("%lld",&n),n){
        printf("Test case #%lld\nTotal explored area: %.2lf\n\n",(ll)cnt++,solve());
    }

    return 0;
}