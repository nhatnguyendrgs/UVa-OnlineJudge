/* UVa 11426 - GCD - Extreme (II)
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2421 */
 
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

const int MaxN = 4000000;

int Div[MaxN+4],p,Exp;
long long result[MaxN+4],F[MaxN+4],aux,Pow;
void solve(){
    memset(Div,-1,sizeof(Div));  
    for(int i = 2;i<=4000000;++i){
        if(Div[i]==-1){
            Div[i] = i;
            if(i<=2000)
                for(int j = i*i;j<=4000000;j += i)
                    Div[j] = i;
        }
    }
    memset(F,-1,sizeof(F));
    result[1] = 0;
    F[1] = 1;
    for(int i = 2;i<=4000000;++i){
        p = Div[i]; Exp = 0;
        aux = i; Pow = 1;
        while(aux%p==0){
            Pow *= p;
            ++Exp;
            aux /= p;
        }
        F[i] = ((Exp+1)*Pow-Exp*(Pow/p))*F[aux];
        result[i] = result[i-1]+F[i]-i;
    }
}

int N;

int main(){
    solve();
    while(scanf("%d",&N)!=EOF){
        if(N==0) break;
        else printf("%lld\n",result[N]);
    }
    return 0;
}
