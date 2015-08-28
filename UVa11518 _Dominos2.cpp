/* UVa 11518 - Dominos 2
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2513 */
 
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
#define DFS_GRAY 2

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int MaxN = 50;

int T,n,m,l;
vector<vi> Adj;
int answer,u,v;

vi dfs_num;
void dfs(int u){
    if(dfs_num[u]==DFS_WHITE)++answer;
    dfs_num[u]=DFS_BLACK;
    for(int i=0;i<Adj[u].size();++i){
        if(dfs_num[Adj[u][i]]==DFS_WHITE)
            dfs(Adj[u][i]);
    }
}

int main(){
    scanf("%d",&T);
    for(int cases=1;cases<=T;++cases){
        scanf("%d%d%d",&n,&m,&l);
        Adj.assign(n+4,vi());dfs_num.assign(n+4,DFS_WHITE);
        for(int i=1;i<=m;++i){
            scanf("%d%d",&u,&v);
            Adj[u].push_back(v);
        }
        answer=0;
        for(int i=1;i<=l;++i){
            scanf("%d",&u);
            dfs(u);
        }
        printf("%d\n",answer);
    }
    return 0;
}
