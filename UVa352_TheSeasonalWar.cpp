/* UVa 352 - The Seasonal War
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=288 */

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
int floodfill(int i, int j, int r, int c, int R, int C, char c_1, char c_2) {
    if (i < r || i > R || j < c || j > C) return 0;
    if (grid[i][j] != c_1) return 0;
    grid[i][j] = c_2;
    for (int d = 0; d < 8; d++) floodfill(i + dr[d], j + dc[d], r, c, R, C, c_1, c_2);
    return 0;
}

int N,cases,result;

int main(){
    while(cin>>N){
        for(int i=0;i<N;i++)
            scanf("%s",grid[i]);
        result=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]=='1'){
                    result++;
                    floodfill(i,j,0,0,N-1,N-1,'1','0');
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",++cases,result);
    }
    return 0;
}
