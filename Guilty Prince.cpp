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
#define MEM(a, b) memset(a, (b), sizeof(a))
#define _for(i, j, k, in) for (int i = j; i < k; i += in)
#define _rfor(i, j, k, in) for (int i = j; i >= k; i -= in)
#define _foritaretor(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
const double pi = acos(-1.0);

lld r, c, i, j, p_r, p_c;
int data[20+1][20+1];

int bfs()
{
	queue<pair<int,int>>trace;
	trace.push({p_r,p_c});
	int count=1,t_r,t_c;

	while (!trace.empty())
	{
		t_r=trace.front().first;
		t_c=trace.front().second;
		trace.pop();

			data[t_r][t_c]=1;

			i=t_r+1;
			j=t_c;


			if((i>=0 && i<r && j>=0 && j<c) && data[i][j]!=1 && data[i][j]!=-1){
				data[i][j]=1;
				trace.push({i,j});
				count++;
			}


			i=t_r;
			j=t_c-1;

			if((i>=0 && i<r && j>=0 && j<c) && data[i][j]!=1 && data[i][j]!=-1){
				data[i][j]=1;
				trace.push({i,j});
				count++;
			}

			j=t_c+1;

			if((i>=0 && i<r && j>=0 && j<c) && data[i][j]!=1 && data[i][j]!=-1){
				data[i][j]=1;
				trace.push({i,j});
				count++;
			}

			i=t_r-1;
			j=t_c;

			if((i>=0 && i<r && j>=0 && j<c) && data[i][j]!=1 && data[i][j]!=-1){
				data[i][j]=1;
				trace.push({i,j});
				count++;
			}
		
	}
	return count;
	
}
void solve()
{
	char ch;
	cin >> c >> r;

	_for(i, 0, r, 1)
		_for(j, 0, c, 1)
	{
		cin >> ch;
		if (ch == '#')
			data[i][j] = -1;
		else if (ch == '.')
			data[i][j] = 0;
		else
			p_r = i, p_c = j, data[i][j] = 0;
	}

	cout << bfs() << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	//read;write;
	lld t, i;
	cin >> t;
	_for(i, 0, t, 1)
	{
		cout << "Case " << i + 1 << ": ";
		solve();
	}

	return 0;
}
