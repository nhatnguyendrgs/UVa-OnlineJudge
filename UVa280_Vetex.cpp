/* UVa - 280 - Vertex
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=216 */
 
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

int n,q,u,v;
vector<vi> Adj;

vi dfs_num;
void dfs(int u){
    for(int j=0;j<Adj[u].size();j++){
        int v=Adj[u][j];
        if(dfs_num[v]==DFS_WHITE){
            dfs_num[v]=DFS_BLACK;
            dfs(v);
        }
    }
}

queue<int> Q;

int main(){
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        Adj.assign(n+4,vi());
        while(1){
            scanf("%d",&u);
            if(u==0) break;
            while(1){
                scanf("%d",&v);
                if(v==0) break;
                Adj[u].push_back(v);
            }
        }
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            scanf("%d",&u);
            dfs_num.assign(n+4,DFS_WHITE);
            dfs(u);
            for(int i=1;i<=n;i++){
                if(dfs_num[i]==DFS_WHITE) Q.push(i);
            }
            if(Q.size()==0)
                printf("0\n");
            else{
                printf("%d ",Q.size());
                while(Q.size()>1){
                    printf("%d ", Q.front());
                    Q.pop();
                }
                printf("%d\n",Q.front());
                Q.pop();
            }
        }
    }
    return 0;
}
