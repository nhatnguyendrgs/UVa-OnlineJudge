/* UVa 11902 - Dominator
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3053*/
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
const int inf = 1e9;
const int MaxN = 1e2;
const int base = 1e9+7;

int T,N,grid[MaxN][MaxN];
vector<vi> Adj;
vi dfs_num,firstVisit;
bool result[MaxN][MaxN];

void graphDirected(){
    scanf("%d",&N);
    Adj.assign(N+4,vi());
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&grid[i][j]);
            if(grid[i][j]==1) Adj[i].push_back(j);
        }
    }
}

void dfs(int u,int X){
    if(u==X) return;
    dfs_num[u]=DFS_BLACK;
    for(int j=0;j<Adj[u].size();j++){
        if(dfs_num[Adj[u][j]]==DFS_WHITE){
            dfs(Adj[u][j],X);
        }
    }
}

void printLine (){
    printf ("+");
    for ( int i = 0; i < N * 2 - 1; i++ ) printf ("-");
    printf ("+\n");
}

int main(){
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++){
        graphDirected();
        dfs_num.assign(N,DFS_WHITE),firstVisit.assign(N,DFS_WHITE);
        dfs(0,-1);
        for(int i=0;i<N;i++) firstVisit[i]=dfs_num[i];
        printf ("Case %d:\n", cases);
        printLine ();
        for ( int i = 0; i < N; i++ ) {
            dfs_num.assign(N,DFS_WHITE);
            dfs (0, i);
            printf ("|");
            for ( int j = 0; j < N; j++ ) {
                if (firstVisit[j]==DFS_BLACK && dfs_num[j]==DFS_WHITE) printf ("Y|");
                else printf ("N|");
            }
            printf("\n");
            printLine ();
        }
    }
    return 0;
}
