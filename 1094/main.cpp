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
//first element is node and second element is the weight
vector<pair<lli,lli> > graph[30005];
pair<lli,lli> max_point;
lli vis[30005];

void dfs(lli x,lli weight)
{
    if(vis[x])
        return ;
    lli i;
    vis[x] = 1;
    rep(i,graph[x].size())
    {
        if(!vis[graph[x][i].first])
        {
            if(max_point.second < weight + graph[x][i].second)
            {
                max_point.first = graph[x][i].first;
                max_point.second = graph[x][i].second + weight;
            }
            dfs(graph[x][i].first,weight+graph[x][i].second);
        }
    }
}
int main()
{
	opt;
	lli t,z;
	scan(t);
	REP(z,1,t)
	{
        lli i,n,u,v,w;
        scan(n);
        rep(i,n-1)
        {
            scan3(u,v,w);
            graph[u].push_back(make_pair(v,w));
            graph[v].push_back(make_pair(u,w));
        }
        max_point.first = 0;
        max_point.second = 0;
        dfs(0,0);
        mem(vis,0);
        max_point.second = 0;
        dfs(max_point.first,0);
        printf("Case %lld: %lld\n",z,max_point.second);
        rep(i,n)
        {
            vis[i] = 0;
            graph[i].clear();
        }
	}
	return 0;
}








