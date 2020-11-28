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
 
int n,m;
int policy[mex][mex];
vector<string> v;
int check(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m) return 1;
    else return 0;
}
pair<int,vector<string> >bt(int x,int y,int st)
{
    
   // cout<<x<<y<<endl;
   //cout<<a[x][y]<<endl;
    int an=0,ans=0;
    if(vis[x][y]==0&&a[x][y]==10)
    {an=1;}
    if(st==0) return {an,vector<string>()};
    vis[x][y]++;
    vector<string> pth;
    int pl=-1;
    fo(i,0,4)
    {
        int x1=x+d[i][0];
        int y1=y+d[i][1];
       // cout<<x1<<y1<<endl;
        if(check(x1,y1)&&a[x1][y1]!=-1)
        {
            //cout<<x1<<y1<<endl;
           // vis[x1][y1]++;
           pair<int,vector<string> > pt=bt(x1,y1,st-1);
           if(ans<pt.fi)
           {ans=pt.fi;
           pth=pt.se;
           pl=i;
           }
           else if(ans==pt.fi&&sz(pth)>sz(pt.se))
           {pth=pt.se;
           pl=i;
           }
            //vis[x1][y1]--;
        }
            
    }
    vis[x][y]--;
    if(pl!=-1)
    pth.pb(v[pl]);
     
    //cout<<ans<<endl;
    return {ans+an,pth};
}
int main()
{
         v.pb("up");
        v.pb("down");
        v.pb("right");
        v.pb("left");
    test
    {
       
        
        
        int st;
        cin>>n>>m>>st;
        fo(i,0,n)
        fo(j,0,m)
        {vis[i][j]=0;
        policy[i][j]=-1;
        }
        int fr1=0,fr2=0;
        fo(i,0,n)
        fo(j,0,m)
        {
            cin>>a[i][j];
            if(a[i][j]==1) {fr1=i;fr2=j;}
        }
        //vis[fr1][fr2]=1;
        pair<int,vector<string> > na=bt(fr1,fr2,st);
        reverse(all(na.se));
        fo(i,0,sz(na.se))
        cout<<na.se[i]<<" ";
        cout<<endl;
 
    }
}