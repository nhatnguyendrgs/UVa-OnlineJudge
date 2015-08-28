/* UVa 824 - Coast Tracker
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=765 */
 
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

bool nextMove(int d, int pos[][3]){
    switch (d) {
        case 0: return pos[0][1] == 1;
        case 1: return pos[0][0] == 1;
        case 2: return pos[1][0] == 1;
        case 3: return pos[2][0] == 1;
        case 4: return pos[2][1] == 1;
        case 5: return pos[2][2] == 1;
        case 6: return pos[1][2] == 1;
        case 7: return pos[0][2] == 1;
    }
}

int x, y, a, b, d, cur_d,c, pos[3][3];

int main(){
    while (scanf("%d",&y)!=EOF) {
        if (y == -1) break;
        scanf("%d%d",&x,&d);
        pos[1][1] = '1';
        for (int i = 0; i < 8; i++) {
            scanf("%d%d%d",&b,&a,&c);
            pos[1-(a-x)][1+b-y] = c;
        }
        for (int i = 0; i < 8; i++) {
            cur_d = (d + i + 5) % 8;
            if (nextMove(cur_d, pos)) {
                printf("%d\n",cur_d);
                break;
            }
        }
    }
    return 0;
}
