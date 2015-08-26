/* UVa 469 - Wetlands of Florida
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=410 */
 
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

int dr[] = { 1, 1, 0, -1, -1, -1, 0, 1 }; // S,SE,E,NE,N,NW,W,SW
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // neighbors
char grid[MaxN+4][MaxN+4];
bool visited[MaxN+4][MaxN+4];
int ans;
int floodfill(int i, int j, int r, int c, int R, int C, char c_1) {
    if (i < r || i > R || j < c || j > C) return 0;
    if (grid[i][j] != c_1 || visited[i][j]==true) return 0;
    visited[i][j] = true;ans++;
    for (int d = 0; d < 8; d++) floodfill(i + dr[d], j + dc[d], r, c, R, C, c_1);
    return 0;
}

int T,n,m,x,y;

int main(){
    scanf("%d",&T);
    getchar (); getchar ();
    bool blank = false;
    for(int cases=1;cases<=T;cases++){
        if (blank) printf("\n");blank = true;
        char in[1004];
        n=0,m=0;
        while (gets(in)&&strlen(in)>0){
            if (in[0]=='L'||in[0]=='W'){
                strcpy (grid[n],in);
                m=strlen(in);
                n++;
            }
            else {
                sscanf(in,"%d%d",&x,&y);
                ans=0;
                for(int i=0;i<n;i++)
                    for(int j=0;j<m;j++)
                        visited[i][j]=false;
                floodfill(x-1,y-1,0,0,n-1,m-1,'W');
                printf ("%d\n", ans);
            }
        }
    }
    return 0;
}
