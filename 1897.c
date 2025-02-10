#include<stdio.h>

int operacoes(int n, int m, int num) {
int op[6],minimo;

if(n*2 == m || n*3 == m || n/2 == m || n/3 == m || n+7 == m || n-7 == m || num>10) return num;
else{
    op[0]=operacoes(n*2,m,num+1);
    op[1]=operacoes(n*3,m,num+1);
    op[2]=operacoes(n/2,m,num+1);
    op[3]=operacoes(n/3,m,num+1);
    op[4]=operacoes(n+7,m,num+1);
    op[5]=operacoes(n-7,m,num+1);
    minimo=op[0];
    for(int i=1;i<6;i++){
        if(op[i]<=minimo) minimo=op[i];
    }
    return minimo;
}

}

int main() {
int n, m;

scanf("%d %d", &n, &m);
printf("%d\\n", operacoes(n, m, 1));

}