#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 
const int mod=1e9+7;
const int mex=2001;
#define ll long long 
#define test int t;cin>>t;while(t--)
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,a,n) for(int i=a;i<n;i++)
#define rfo(i,a,b) for(int i=a;i>=b;i--)
#define bg begin()
#define en end()
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define veci vector<ll int>
#define veclli vector<long long int> 
#define all(x) x.begin(),x.end()
#define sci(x) scanf("%d",&x);
#define scc(x) scanf("%c",&x);
#define scs(x) scanf("%s",x);
#define debug(arr,n) for(int i=0;i<n;i++) printf("%d ",arr[i]);
#define sz(x) x.size()
#define loop(x) for(auto it=x.begin();it!= x.end();it++)
int vis[mex][mex];
int a[mex][mex]; 
int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int n,m,vl=0,g=0;
int check(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m) return 1;
    else return 0;
}
int hr()
{
    int cnt=0;
    fo(i,0,n)
    fo(j,0,m)
    if(a[i][j]==10&&vis[i][j]==0) cnt++;
 
    if(cnt) return 1;
    else return 0;
}
int bt(int x,int y,int x2,int y2,int st)
{
    
   // cout<<x<<y<<endl;
   //cout<<a[x][y]<<endl;
   int an=0;
    int ans=0;
    if(g==1) return 0;
    if(hr()==0)
    {
        g=1;
        //cout<<"y"<<endl;
        return 0;
    }
    if(vis[x][y]==0&&a[x][y]==10)
    {an=1;}
    if(vis[x2][y2]==0&&a[x2][y2]==10)
    an++;
	if(st==0) return an;
    
	vis[x][y]++;
    vis[x2][y2]++;
    fo(i,0,4)
    {
        int x1=x+d[i][0];
        int y1=y+d[i][1];
       // cout<<x1<<y1<<endl;
        if(check(x1,y1)&&a[x1][y1]!=-1)
        {
            //cout<<x1<<y1<<endl;
           // vis[x1][y1]++;
            
            ans=max(bt(x1,y1,x2,y2,st-1),ans);
            if(g==1) return 0;
           // if(g==1) return 0;
           
            //vis[x1][y1]--;
        }
            
    }
    fo(i,0,4)
    {
        int x3=x2+d[i][0];
        int y3=y2+d[i][1];
       // cout<<x1<<y1<<endl;
        if(check(x3,y3)&&a[x3][y3]!=-1)
        {
            //cout<<x1<<y1<<endl;
           // vis[x1][y1]++;
            ans=max(bt(x,y,x3,y3,st-1),ans);
            if(g==1) return 0;
            //vis[x1][y1]--;
        }
    }
    vis[x][y]--;
    vis[x2][y2]--;
    if(g==1) return 0;
    //cout<<ans<<endl;
    return ans+an;
}
int main()
{
    test
    {
        g=0;
        vl=0;
        
        int st;
        cin>>n>>m>>st;
        fo(i,0,n)
        fo(j,0,m)
        vis[i][j]=0;
        int fr1=0,fr2=0,fr3=0,fr4=0;
        fo(i,0,n)
        fo(j,0,m)
        {
            cin>>a[i][j];
            if(a[i][j]==1) {fr1=i;fr2=j;}
            if(a[i][j]==2) {fr3=i;fr4=j;}
            if(a[i][j]==10) vl++;
        }
        //cout<<vl<<endl;
        //vis[fr1][fr2]=1;
       // cout<<g<<endl;
       int y=bt(fr1,fr2,fr3,fr4,st);
        if(g==1) cout<<vl<<endl;
        else
        cout<<y<<endl;
 
    }
}