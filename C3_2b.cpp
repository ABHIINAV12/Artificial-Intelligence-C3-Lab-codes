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
vector<string> v;
int check(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m) return 1;
    else return 0;
}
pair<int,pair<vector<string>,vector<string> > > bt(int x,int y,int x2,int y2,int st)
{
    
   //cout<<x<<y<<endl;
   //cout<<a[x][y]<<endl;
   int an=0;
    int ans=0;
    if(vis[x][y]==0&&a[x][y]==10)
    {an=1;}
    if(vis[x2][y2]==0&&a[x2][y2]==10)
    an++;
	if(st==0) return {an,{vector<string>(),vector<string>()}};
	vis[x][y]++;
    vis[x2][y2]++;
    vector<string> pth1,pth2;
    int pl1=-1,pl2=-1;
    fo(i,0,4)
    {
        int x1=x+d[i][0];
        int y1=y+d[i][1];
       // cout<<x1<<y1<<endl;
        if(check(x1,y1)&&a[x1][y1]!=-1)
        {
           pair<int,pair<vector<string>,vector<string> > >pt=bt(x1,y1,x2,y2,st-1);
           if(ans<pt.fi)
           {ans=pt.fi;
           pth1=pt.se.fi;
           pth2=pt.se.se;
           pl1=i;
           }
           else if(ans==pt.fi&&(sz(pth1)+sz(pth2))>(sz(pt.se.fi)+sz(pt.se.se)))
           {
           pth1=pt.se.fi;
           pth2=pt.se.se;
           pl1=i;
           }
        }
            
    }
    fo(i,0,4)
    {
        int x3=x2+d[i][0];
        int y3=y2+d[i][1];
       // cout<<x1<<y1<<endl;
        if(check(x3,y3)&&a[x3][y3]!=-1)
        {
            pair<int,pair<vector<string>,vector<string> > >pt=bt(x,y,x3,y3,st-1);
           if(ans<pt.fi)
           {ans=pt.fi;
           pth1=pt.se.fi;
           pth2=pt.se.se;
           pl2=i;
           }
           else if(ans==pt.fi&&(sz(pth1)+sz(pth2))>(sz(pt.se.fi)+sz(pt.se.se)))
           {
           pth1=pt.se.fi;
           pth2=pt.se.se;
           pl2=i;
           }
        }
    }
    vis[x][y]--;
    vis[x2][y2]--;
    if(pl2!=-1)
    pth2.pb(v[pl2]);
    else if(pl1!=-1)
    pth1.pb(v[pl1]);
    //cout<<ans<<endl;
    return {ans+an,{pth1,pth2}};
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
        vis[i][j]=0;
        int fr1=0,fr2=0,fr3=0,fr4=0;
        fo(i,0,n)
        fo(j,0,m)
        {
            cin>>a[i][j];
            if(a[i][j]==1) {fr1=i;fr2=j;}
            if(a[i][j]==2) {fr3=i;fr4=j;}
        }
        //vis[fr1][fr2]=1;
       pair<int,pair<vector<string>,vector<string> > > na=bt(fr1,fr2,fr3,fr4,st);
        reverse(all(na.se.fi));
        reverse(all(na.se.se));
        if(sz(na.se.fi)==0) cout<<"NIL"<<endl;
        else
        {fo(i,0,sz(na.se.fi))
        cout<<na.se.fi[i]<<" ";
        cout<<endl;
        }
        if(sz(na.se.se)==0) cout<<"NIL"<<endl;
        else
        {fo(i,0,sz(na.se.se))
        cout<<na.se.se[i]<<" ";
        cout<<endl;
        }
 
    }
}