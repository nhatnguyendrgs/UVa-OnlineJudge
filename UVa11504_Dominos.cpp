/* UVa 11504 Dominos
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2499 */
 
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

#define DFS_WHITE -1
#define DFS_BLACK 1

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;
int V, E, u, v;

void graphDirected(){
    scanf("%d %d", &V, &E);
    AdjList.assign(V + 1, vii());
    for (int i = 0; i < E; ++i) {
        scanf("%d %d", &u, &v);
        AdjList[u].push_back(ii(v, 0));
    }
}

vi dfs_num,topoSort;
void topo(int u) {
    dfs_num[u] = DFS_BLACK;
    for (int j = 0; j < AdjList[u].size(); ++j){
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            topo(v.first);
    }
    topoSort.push_back(u);
}

int T,answer;

int main(){
    scanf("%d",&T);
    while(T--){
        graphDirected();
        topoSort.clear();dfs_num.assign(V+1,DFS_WHITE);
        for(int i=1;i<=V;++i){
            if(dfs_num[i]==DFS_WHITE){
                topo(i);
            }
        }
        answer=0;dfs_num.assign(V+1,DFS_WHITE);
        for(int i=topoSort.size()-1;i>=0;--i){
            if(dfs_num[topoSort[i]]==DFS_WHITE){
                ++answer;
                topo(topoSort[i]);
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
