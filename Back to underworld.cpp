#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define lld long long int
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
const double pi = acos(-1.0);
map<lld,vector<lld>>data;
map<lld,bool>visit;
map<lld,lld>type;
lld solve(lld node){
    visit[node]=true;
    type[node]=1;
    lld lykan=0,vampire=1,i;
    queue<lld>trace;
    trace.push(node);

    while (!trace.empty())
    {
        node=trace.front();
        trace.pop();
        for(i=0;i<data[node].size();i++){
            if(!visit[data[node][i]]){
                trace.push(data[node][i]);
                visit[data[node][i]]=true;
                if(type[node]==1){
                    type[data[node][i]]=0;
                    lykan++;
                }else{
                    type[data[node][i]]=1;
                    vampire++;
                }
            }
        }
    }
    return max(lykan,vampire);
}
int main()
{
    ios_base::sync_with_stdio(false);
    read;write;
    lld n,t,i,x,y,ans,c=1;
    cin>>t;
    while (t--)
    {
        ans=0;
        cin>>n;
        cout<<"Case "<<c++<<": ";
        data.clear();visit.clear();type.clear();
        for(i=0;i<n;i++){
            cin>>x>>y;
            data[x].push_back(y);
            data[y].push_back(x);
        }
        for(auto it=data.begin();it!=data.end();it++){
            if(!visit[it->first])
            ans+=solve(it->first);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
