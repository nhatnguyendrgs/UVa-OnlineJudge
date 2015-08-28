/* UVa 10946 - You want what filled?
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1887 */
 
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

const int MaxN = 50;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };
char grid[MaxN+4][MaxN+4];
int cnt;
int floodfill(int i, int j, int r, int c, int R, int C, char c_1, char c_2) {
    if (i < r || i > R || j < c || j > C) return 0;
    if (grid[i][j] != c_1) return 0;
    grid[i][j] = c_2;cnt++;
    for (int d = 0; d < 8; d++) floodfill(i + dr[d], j + dc[d], r, c, R, C, c_1, c_2);
    return 0;
}

int x, y,cases;
typedef pair<int,char> ic;
ic value;
vector<ic> answer;

bool cmp(ic a,ic b){
    if(a.first>b.first) return true;
    if(a.first==b.first&&a.second<b.second) return true;
    return false;
}

int main(){
    while(scanf("%d%d",&x,&y)!=EOF){
        if(x==0 && y==0) break;
        answer.clear();
        for(int i=0;i<x;i++) scanf("%s",grid[i]);
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(grid[i][j]!='.'){
                    cnt=0;
                    value.second=grid[i][j];
                    floodfill(i, j, 0, 0, x-1, y-1, grid[i][j], '.');
                    value.first=cnt;
                    answer.push_back(value);
                }
            }
        }
        sort(answer.begin(),answer.end(),cmp);
        printf("Problem %d:\n",++cases);
        for(int i=0;i<answer.size();i++){
            printf("%c %d\n",answer[i].second,answer[i].first);
        }
   }
   return 0;
}
