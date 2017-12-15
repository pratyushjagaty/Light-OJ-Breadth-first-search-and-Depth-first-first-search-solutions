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
lli n,ans = 0;
vector<lli> graph[20005],vis(20005);
void reset()
{
    lli i;
    rep(i,20005)
    {
        graph[i].clear();
        vis[i] = 0;
    }
}
void dfs(lli x,set<lli> &vampire,set<lli> &lykan)
{
    if(vis[x])
        return ;
    vis[x] = 1;
    lli i;
    if(vampire.find(x) == vampire.end() and lykan.find(x) == lykan.end())
    {
        vampire.insert(x);
        //printf("vampire %lld\n",x);
        rep(i,graph[x].size())
        {
            if(!vis[graph[x][i]])
            {
                lykan.insert(graph[x][i]);
                //printf("lykan %lld\n",graph[x][i]);
                dfs(graph[x][i],vampire,lykan);
            }

        }
    }
    else if(vampire.find(x) != vampire.end() and lykan.find(x) == lykan.end())
    {
        rep(i,graph[x].size())
        {
            if(!vis[graph[x][i]])
            {
                lykan.insert(graph[x][i]);
                //printf("lykan %lld\n",graph[x][i]);
                dfs(graph[x][i],vampire,lykan);
            }
        }
    }
    else if(vampire.find(x) == vampire.end() and lykan.find(x) != lykan.end())
    {
        rep(i,graph[x].size())
        {
            if(!vis[graph[x][i]])
            {
                vampire.insert(graph[x][i]);
                //printf("vampire %lld\n",graph[x][i]);
                dfs(graph[x][i],vampire,lykan);
            }
        }
    }
}
int main()
{
	opt;
	lli z,t;
	scan(t);
	REP(z,1,t)
	{
        lli i,u,v;
        scan(n);
        ans = 0;
        rep(i,n)
        {
            scan2(u,v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        rep(i,20001)
        {
            if(graph[i].size() and !vis[i])
            {
                set<lli> vampire,lykan;
                dfs(i,vampire,lykan);
                ans += max(vampire.size(),lykan.size());
            }
        }
        printf("Case %lld: %lld\n",z,ans);
        reset();
	}
	return 0;
}








