/* UVa 118 - Mutant Flatworld Explorers
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=54 */

//nhatnguyendrgs (c)

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

struct robot{
    int x,y;
    char d;
}robot;

int n,m;
bool flat[104][104],destination;

void updateMove(char c){
    if(robot.d == 'S' && c == 'R' )
        robot.d = 'W';
    else if ( robot.d == 'S' && c == 'L' )
        robot.d = 'E';

    else if ( robot.d == 'N' && c == 'R' )
        robot.d = 'E';
    else if ( robot.d == 'N' && c == 'L' )
        robot.d = 'W';

    else if ( robot.d == 'E' && c == 'R' )
        robot.d = 'S';
    else if ( robot.d == 'E' && c == 'L' )
        robot.d = 'N';

    else if ( robot.d == 'W' && c == 'R' )
        robot.d = 'N';
    else if ( robot.d == 'W' && c == 'L' )
        robot.d = 'S';

    if(c=='F'){
        switch (robot.d){
            case 'N':
                if( robot.y == n && flat[robot.x][robot.y] == true ) break;
                else if(robot.y == n &&flat[robot.x][robot.y]==false){
                    flat[robot.x][robot.y]=true;
                    printf ("%d %d %c LOST\n", robot.x, robot.y, robot.d);
                    destination=true;
                    break;
                }
                robot.y++;
                break;

            case 'S':
                if( robot.y == 0 && flat[robot.x][robot.y] == true ) break;
                if(robot.y == 0 &&flat[robot.x][robot.y]==false){
                    flat[robot.x][robot.y]=true;
                    printf ("%d %d %c LOST\n", robot.x, robot.y, robot.d);
                    destination=true;
                    break;
                }
                robot.y--;
                break;

            case 'E':
                if( robot.x == m && flat[robot.x][robot.y] == true ) break;
                if(robot.x == m &&flat[robot.x][robot.y]==false){
                    flat[robot.x][robot.y]=true;
                    printf ("%d %d %c LOST\n", robot.x, robot.y, robot.d);
                    destination=true;
                }
                robot.x++;
                break;

            case 'W':
                if( robot.x == 0 && flat[robot.x][robot.y] == true ) break;
                if(robot.x == 0 &&flat[robot.x][robot.y]==false){
                    flat[robot.x][robot.y]=true;
                    printf ("%d %d %c LOST\n", robot.x, robot.y, robot.d);
                    destination=true;
                    break;
                }
                robot.x--;
                break;
        }
    }
}

int main(){
    scanf("%d%d",&m,&n);
    while(cin>>robot.x>>robot.y>>robot.d){
        char c[104];scanf("%s",c);
        destination=false;
        for(int i=0;c[i]&&!destination;i++) updateMove(c[i]);
        if(!destination) printf("%d %d %c\n",robot.x,robot.y,robot.d);
    }
    return 0;
}
