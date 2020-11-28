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
int check(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m) return 1;
    else return 0;
}
int bt(int x,int y,int st)
{
    
   // cout<<x<<y<<endl;
   //cout<<a[x][y]<<endl;
   int an=0;
    int ans=0;
    if(vis[x][y]==0&&a[x][y]==10)
    {an=1;}
	if(st==0) return an;
	vis[x][y]++;
    fo(i,0,4)
    {
        int x1=x+d[i][0];
        int y1=y+d[i][1];
       // cout<<x1<<y1<<endl;
        if(check(x1,y1)&&a[x1][y1]!=-1)
        {
            //cout<<x1<<y1<<endl;
           // vis[x1][y1]++;
            ans=max(bt(x1,y1,st-1),ans);
            //vis[x1][y1]--;
        }
            
    }
    vis[x][y]--;
    //cout<<ans<<endl;
    return ans+an;
}
int main()
{
    test
    {
        
        int st;
        cin>>n>>m>>st;
        fo(i,0,n)
        fo(j,0,m)
        vis[i][j]=0;
        int fr1=0,fr2=0;
        fo(i,0,n)
        fo(j,0,m)
        {
            cin>>a[i][j];
            if(a[i][j]==1) {fr1=i;fr2=j;}
        }
        vis[fr1][fr2]=1;
        cout<<bt(fr1,fr2,st)<<endl;
 
    }
}