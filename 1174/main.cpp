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

#define scan(N)/*----------------------*/scanf("%lld",&N)
#define print(N)/*---------------------*/printf("%lld",N)
#define scan2(N1,N2)/*-----------------*/scanf("%lld %lld",&N1,&N2)
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

vector<lli> graph[105],level_src(105),level_des(105),vis(105);
lli n,r,u,v,src,des,maxi;

void bfs(lli x,lli chk)
{
    queue<lli> q;
    q.push(x);
    lli i;
    chk ? level_des[x] = 0 : level_src[x] = 0;
    vis[x] = 1;
    while(!q.empty())
    {
        lli p = q.front();
        q.pop();
        rep(i,graph[p].size())
        {
            if(!vis[graph[p][i]])
            {
                q.push(graph[p][i]);
                chk ? level_des[graph[p][i]] = level_des[p]+1 : level_src[graph[p][i]] = level_src[p]+1;
                vis[graph[p][i]] = 1;
            }
        }
    }
    //printf("\n");
    //printf("level of 3 is %lld and level of 2 is %lld\n",level[3],level[2]);
}
int main()
{
	opt;
    lli z,t;
    scan(t);
    REP(z,1,t)
    {
        scan(n);
        scan(r);
        lli i;
        rep(i,r)
        {
            scan2(u,v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        scan2(src,des);
        lli ans = 0;
        bfs(src,0);
        rep(i,105)
        {
            //graph[i].clear();
            vis[i] = 0;
        }
        bfs(des,1);
        rep(i,105)
        {
            ans = max(ans,level_src[i]+level_des[i]);
        }
        printf("Case %lld: %lld\n",z,ans);
        rep(i,105)
        {
            graph[i].clear();
            vis[i] = level_src[i] = level_des[i] = 0;
        }
    }
	return 0;
}








