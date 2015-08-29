/* UVa 11956 - Brainfuck
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3107 */
 
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

int T;
string s;
int memory[100],pointer;

int main(){
    scanf("%d\n",&T);
    for(int cases=1;cases<=T;cases++){
        getline(cin,s);
        for(int i=0;i<100;i++)
            memory[i]=0;
        pointer=0;
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case '>':
                    pointer++;
                    if (pointer == 100)
                        pointer = 0;
                    break;
                case '<':
                    pointer--;
                    if (pointer == -1)
                        pointer = 99;
                    break;
                case '+':
                    memory[pointer]++;
                    if (memory[pointer] == 256)
                        memory[pointer] = 0;
                    break;
                case '-':
                    memory[pointer]--;
                    if (memory[pointer] == -1)
                        memory[pointer] = 255;
                    break;
                case '.':
                    break;
            }
        }
        printf("Case %d:",cases);
        for(int i=0;i<100;i++)
            printf(" %02X", memory[i]);
        printf("\n");
    }
    return 0;
}
