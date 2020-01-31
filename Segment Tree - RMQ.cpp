#include<bits/stdc++.h>
using namespace std;

#define int long long

struct data
{
    //Use required attributes
    int mn;

    //Default Values
    data()
    {
        mn=1e9;
    }

    data(int x)
    {
        mn=x;
    }
};

struct SegTree
{
    int N;
    vector<int> arr;
    vector<data> seg;
    vector<bool> clazy;
    vector<int> lazy;

    void init(int n)
    {
        N=n;
        arr.resize(N+5);
        for(int i=0;i<N;i++) cin>>arr[i];
        seg.resize(4*N+5);
        clazy.resize(4*N+5,false);
        lazy.resize(4*N+5,0);
    }

    //Write reqd merge functions
    void merge(data &cur,data &l,data &r)
    {
        cur.mn=min(l.mn,r.mn);
    }

    // Handle lazy propagation appriopriately
    void propagate(int node,int s,int e)
    {
        if(s!=e)
        {
            clazy[node<<1]=1;
            clazy[node<<1|1]=1;
            lazy[node<<1]=lazy[node];
            lazy[node<<1|1]=lazy[node];
        }
        seg[node].mn=lazy[node];
        clazy[node]=0;
    }

    void BUILD(int node,int s,int e)
    {
        if(s==e)
        {
            data base(arr[s]);
            seg[node]=base;
            return;
        }
        else
        {
            int mid=(s+e)>>1;
            BUILD(node<<1,s,mid);
            BUILD(node<<1|1,mid+1,e);
            merge(seg[node],seg[node<<1],seg[node<<1|1]);
        }
    }

    data RQUE(int node,int s,int e,int l,int r)
    {
        if(clazy[node]) propagate(node,s,e);

        if(r<s or l>e) return data();

        if(l<=s and e<=r) return seg[node];

        int mid=(s+e)/2;
        data left=RQUE(node<<1,s,mid,l,r);
        data right=RQUE(node<<1|1,mid+1,e,l,r);
        data curr;
        merge(curr,left,right);
        return curr;
    }

    data QUE(int node,int s,int e,int x)
    {
        if(clazy[node]) propagate(node,s,e);

        if(s==e) return seg[node];

        int mid=(s+e)>>1;
        if(x<=mid) return QUE(node<<1,s,mid,x);
        else return QUE(node<<1|1,mid+1,e,x);
    }

    void RUPD(int node,int s,int e,int l,int r,int val)
    {
        if(clazy[node]) propagate(node,s,e);

        if(r<s or l>e) return;

        if(l<=s and e<=r)
        {
            clazy[node]=1;
            lazy[node]=val;
            propagate(node,s,e);
            return;
        } 

        int mid=(s+e)>>1;
        RUPD(node<<1,s,mid,l,r,val);
        RUPD(node<<1|1,mid+1,e,l,r,val);
        merge(seg[node],seg[node<<1],seg[node<<1|1]);
    }

    void UPD(int node,int s,int e,int x,int val)
    {
        if(clazy[node]) propagate(node,s,e);

        if(s==e) 
        {
            clazy[node]=1;
            lazy[node]=val;
            propagate(node,s,e);
            return;
        }

        int mid=(s+e)>>1;
        if(x<=mid) return UPD(node<<1,s,mid,x,val);
        else return UPD(node<<1|1,mid+1,e,x,val);
        merge(seg[node],seg[node<<1],seg[node<<1|1]);
    }

    data query(int x)
    {
        return QUE(1,1,N,x);
    }

    data query(int l,int r)
    {
        return RQUE(1,1,N,l,r);
    }

    void update(int x,int val)
    {
        UPD(1,1,N,x,val);
    }

    void update(int l,int r,int val)
    {
        RUPD(1,1,N,l,r,val);
    }

};

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    int n=0;
    cin>>n;

    SegTree seg;
    seg.init(n);
    seg.BUILD(1,0,n-1);

    int q=0;
    cin>>q;

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<seg.query(l,r).mn<<"\n";
    }
    
    return 0;
}
