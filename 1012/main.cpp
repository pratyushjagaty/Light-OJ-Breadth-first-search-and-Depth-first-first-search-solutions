/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li      int32_t
#define lli     long long
#define ulli unsigned long long

#define pn          printf("\n")
#define nl          cout<<'\n'

#define rep(i,a,b)  for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define elif        else if
#define mset(a,b)   memset(a,b,sizeof(a))

#define pb      push_back
#define pob     pop_back
#define itr     iterator
#define sz()    size()
#define szof    sizeof
#define lb      lower_bound
#define ub      upper_bound
#define mp      make_pair
#define vlli    vector<lli>
#define plli    pair<lli,lli>
#define vplli   vector<plli >
#define Frst    first
#define Sec     second

#define Inf     100000000000
#define mod     1000000007
using namespace std;

lli a[202][202];
bool visited[202][202];

void dfs(lli x,lli y)
{
    visited[x][y]=1;

    if(a[x-1][y] && !visited[x-1][y])
    {
        dfs(x-1,y);
    }

    if(a[x][y-1] && !visited[x][y-1])
    {
        dfs(x,y-1);
    }

    if(a[x][y+1] && !visited[x][y+1])
    {
        dfs(x,y+1);
    }

    if(a[x+1][y] && !visited[x+1][y])
    {
        dfs(x+1,y);
    }
}

lli Power(lli a,lli b)
{
    lli result=1;

    while(b)
    {
        if(b%2)
        {
            result=(result*a)%mod;
        }

        b=b>>1;
        a=(a*a)%mod;
    }

 return result;
 }

int main()
{
    opt;

 lli T,t=1;
 cin>>T;

 while(T--)
 {
    lli N,M,i,j;
    cin>>N>>M;

    swap(N,M);

    memset(a,0,szof(a));
    memset(visited,0,szof(visited));

    lli x,y;

    rep(i,1,N+1)
    {
        string s;
        cin>>s;

        rep(j,0,M)
        {
            char ch=s[j];

            if(ch=='.' || ch=='@')
            {
                a[i][j+1]=1;
            }
            else
            {
                a[i][j+1]=0;
            }

            if(ch=='@')
            {
                x=i;
                y=j+1;
            }
        }
    }

     dfs(x,y);

    lli cnt=0;
    rep(i,1,N+1)
    {
        rep(j,1,M+1)
        {
            if(visited[i][j])
            {
                cnt++;
            }
        }
    }

    cout<<"Case "<<t++<<": "<< cnt;
    nl;
}





 return 0;
}
