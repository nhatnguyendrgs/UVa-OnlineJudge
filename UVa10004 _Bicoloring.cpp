/* UVa 10004 - Bicoloring
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=945 */

//nhatnguyendrgs (c) 2015

#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "deque"
#include "set"
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf = 1e9;

int V, E, u, v;
vector<vii> AdjList;

void graphUndirected(){
    scanf("%d", &E);
    AdjList.assign(V + 4, vii());
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        AdjList[u].push_back(ii(v, 0));
        AdjList[v].push_back(ii(u, 0));
    }
}

bool isBipartite;
void bfs(int s){
    vi d(V + 4, inf); d[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (d[v.first] == inf) {
                d[v.first] = d[u] + 1;
                q.push(v.first);
            }
            else if ((d[v.first] % 2) == (d[u] % 2)) isBipartite = false;
        }
    }
}

int main(){
    while(scanf("%d",&V)!=EOF){
        if(V==0) break;
        graphUndirected();
        isBipartite=true;
        bfs(0);
        (isBipartite==false)?printf("NOT BICOLORABLE.\n"):printf("BICOLORABLE.\n");
    }
    return 0;
}
