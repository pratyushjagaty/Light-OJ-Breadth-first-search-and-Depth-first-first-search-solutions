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

char graph[15][15],vis[15][15];
lli total,n;
char last;
//graph moves
lli dirc[][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
class Node
{
    public:
        lli x,y,time;
        Node(lli a,lli b,lli t)
        {
            x = a;
            y = b;
            time = t;
        }
        Node(){}
};
int bfs(Node node,char cur)
{
    if(cur == last)
        return node.time;
    mem(vis,0);
    queue<Node> q;
    q.push(node);
    while(!q.empty())
    {
        Node p = q.front();
        q.pop();
        lli i;
        rep(i,4)
        {
            lli a = p.x + dirc[i][0];
            lli b = p.y + dirc[i][1];
            if(a < 0 or a >= n or b < 0 or b >= n)
                continue ;
            if(graph[a][b] == cur+1)
                return bfs(Node(a,b,p.time+1),cur+1);
            else if(!vis[a][b] and (graph[a][b] == '.' or (isalpha(graph[a][b]) && graph[a][b] <= cur)))
            {
                q.push(Node(a,b,p.time+1));
                vis[a][b] = 1;
            }
        }
    }
    return -1;
}
int main()
{
	opt;
	lli t,z;
	cin >> t;
	REP(z,1,t)
    {
        cin >> n;
        lli i,j;
        last = 'A';
        Node node;
        rep(i,n)
        {
            string s;
            cin >> s;
            rep(j,n)
            {
                graph[i][j] = s[j];
                if(s[j] == 'A')
                {
                    node.x = i;
                    node.y = j;
                    node.time = 0;
                }
                if(s[j] >= 'A' and s[j] <= 'Z')
                {
                    last = max(last,s[j]);
                }
            }
        }
        int ans = bfs(node,'A');
        cout << "Case " << z << ": ";
        ans >= 0 ? cout << ans << endl : cout << "Impossible\n";
    }
	return 0;
}








