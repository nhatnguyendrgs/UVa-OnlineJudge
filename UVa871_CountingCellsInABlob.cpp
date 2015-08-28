/* UVa 871 - Counting Cells in a Blob
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=812 */
  
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

const int MaxN = 25;

int dr[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
char grid[MaxN+4][MaxN+4];
int cnt;
int floodfill(int i, int j, int r, int c, int R, int C, char c_1, char c_2) {
    if (i < r || i > R || j < c || j > C) return 0;
    if (grid[i][j] != c_1) return 0;
    grid[i][j] = c_2;cnt++;
    for (int d = 0; d < 8; d++) floodfill(i + dr[d], j + dc[d], r, c, R, C, c_1, c_2);
    return 0;
}

int T,n,m,result;
string s;

int main(){
    scanf("%d\n\n",&T);
    while(T--){
        n=0,m=0;
        while(getline(cin,s)){
            if(s.size()==0) break;
            m=s.length();
            for(int j=0;j<m;++j)
                grid[n][j]=s[j];
            n++;
        }
        result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt=0;
                    floodfill(i,j,0,0,n-1,m-1,'1','.');
                    result=max(result,cnt);
                }
            }
        }
        if(T==0) printf("%d\n",result);
        else printf("%d\n\n",result);
    }
    return 0;
}
