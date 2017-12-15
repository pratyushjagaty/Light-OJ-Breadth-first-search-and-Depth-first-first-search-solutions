/*
	##############################
	## Author: Pratyush Gaurav ###
	## College: NIT ROURKELA #####
	##############################
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long/*--------------------*/lli;
typedef long double/*------------------*/ld;
typedef unsigned long long/*-----------*/ulli;
typedef pair<lli, lli >/*--------------*/plli;
typedef vector<plli >/*----------------*/vplli;

#define rep(i,a)/*---------------------*/for(i = 0 ; i < a ; i++)
#define repr(i,a)/*--------------------*/for(i = a ; i >= 0 ; i--)
#define REP(i,a,b)/*-------------------*/for(i = a ; i <= b ; i++)
#define REPR(i,a,b)/*------------------*/for(i = a ; i >= b ; i--)

#define scan(N)/*----------------------*/scanf("%1d",&N)
#define print(N)/*---------------------*/printf("%lld",N)
#define scan2(N1,N2)/*-----------------*/scanf("%d %d",&N1,&N2)
#define print2(N1,N2)/*----------------*/printf("%lld %lld",N1,N2)
#define scan3(N1,N2,N3)/*--------------*/scanf("%lld %lld %lld",&N1,&N2,&N3)
#define print3(N1,N2,N3)/*-------------*/printf("%lld %lld %lld",N1,N2,N3)

#define lb/*---------------------------*/lower_bound
#define ub/*---------------------------*/upper_bound
#define pb/*---------------------------*/push_back
#define popb/*-------------------------*/pop_back

#define mem(a,b)/*---------------------*/memset(a,b,sizeof(a))
#define opt/*--------------------------*/ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sz/*---------------------------*/size()

#define MP/*---------------------------*/make_pair
#define bs/*---------------------------*/binary_search
#define gcd(a, b)/*--------------------*/__gcd(a, b)
#define lcm(a, b)/*--------------------*/((a)*((b)/gcd(a,b)))
#define sqr(x)/*-----------------------*/(x)*(x)
#define all(a)/*-----------------------*/a.begin(),a.end()

#define ff/*---------------------------*/first
#define ss/*---------------------------*/second

#define endl/*-------------------------*/'\n'
#define inf/*--------------------------*/(lli)2000000000000
#define MOD/*--------------------------*/(lli)1000000007
#define MAXN/*-------------------------*/100005

template<class T> bool is_prime(T n)
{
	if((n%2 == 0 and n > 2) or n < 2 )
		return false;
	for(T i = 3; i*i <= n ; i += 2)
	{
		if( n % i == 0)
			return false;
	}
	return true;
}
lli power(lli a,lli b)
{
    lli value;
    if(!b)
    	return 1;
    else if(b%2==0)
    {
        value = power(a,b/2)%MOD;
        return (value * value)%MOD;
    }
    else
    {
        value = power(a,b/2)%MOD;
        return ((a*value)%MOD*(value))%MOD;
    }
}
int r,c,vis[20][20],level[20][20],graph[20][20];
// Knight moves
int dirc [][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1} };
//min moves,total final count at the place
pair<int,int> ans[20][20];
class rider
{
    public:
        int x,y,k;
        rider(int a,int b,int c)
        {
            x = a;
            y = b;
            k = c;
        }
};
void bfs(int x,int y,int k)
{
    queue<rider> q;
    q.push(rider(x,y,0));
    while(!q.empty())
    {
        rider p = q.front();
        q.pop();
        int i;
        if(p.x < 0 or p.y < 0 or p.x >= r or p.y >= c)
            continue ;
        if(vis[p.x][p.y])
            continue;

        ans[p.x][p.y].first += (p.k)/k;
        if(p.k % k) ans[p.x][p.y].first++;
        ans[p.x][p.y].second++;
        vis[p.x][p.y] = 1;
        rep(i,8)
        {
            int dx = p.x + dirc[i][0];
            int dy = p.y + dirc[i][1];
            q.push(rider(dx,dy,p.k+1));
        }
    }
}
int main()
{
	opt;
    int t,z;
    cin >> t;
    REP(z,1,t)
    {
        cin >> r >> c;
        int i,j,cnt = 0,answer = INT_MAX;
        rep(i,r)
        {
            string s;
            cin >> s;
            rep(j,c)
            {
                if(s[j] == '.')
                    graph[i][j] = 0;
                else
                {
                    graph[i][j] = s[j] - '0';
                    cnt++;
                }
            }
        }
        rep(i,r)
        {
            rep(j,c)
            {
                if(graph[i][j] > 0)
                {
                    mem(vis,0);
                    bfs(i,j,graph[i][j]);
                }
            }
        }
        rep(i,r)
        {
            rep(j,c)
            {
                if(ans[i][j].second == cnt)
                {
                    answer = min(answer,ans[i][j].first);
                }
//                print2(ans[i][j].first,ans[i][j].second);
//                printf("\n");
            }
        }
        rep(i,20)
        {
            rep(j,20)
            {
                ans[i][j].first = 0;
                ans[i][j].second = 0;
            }
        }
        if(answer == INT_MAX)
            answer = -1;
        cout << "Case " << z << ": " << answer << endl;
    }
	return 0;
}








