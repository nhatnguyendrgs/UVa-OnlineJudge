/* UVa 10305 - Ordering Tasks
 *https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1246 */
 
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
const int MaxN = 1e2;
const int base = 1e9+7;

#define DFS_WHITE -1
#define DFS_BLACK 1

int n,m;
vector<vi> Adj;
stack<int> S;

vi dfs_num;
void topoSort(int u){
    for(int i=0;i<Adj[u].size();i++){
        int v=Adj[u][i];
        if(dfs_num[v]==DFS_WHITE)
            topoSort(v);
    }
    S.push(u);
    dfs_num[u]=DFS_BLACK;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        Adj.assign(n+4,vi()),dfs_num.assign(n+4,DFS_WHITE);
        int u,v;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            Adj[u].push_back(v);
        }
        for(int i=1;i<=n;i++){
            if(dfs_num[i]==DFS_WHITE) topoSort(i);
        }
        while(!S.empty()){
            printf("%d ",S.top());
            S.pop();
        }
        printf("\n");
    }
    return 0;
}
