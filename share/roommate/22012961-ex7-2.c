#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int randMax=10;//随机数上限

void min_fun(int *a,int *res1,int *res2){
    int min=randMax,lmin=randMax;
    for (int i=0;i<10;i++){
        if(min>a[i]){
            lmin=min;
            min=a[i];
        }
    }
    *res1=min;
    *res2=lmin;
}

int main(){
    srand(time(NULL));
    int a[10];
    int res1,res2;
    for (int i=0;i<10;i++){
        a[i]=rand()%randMax;
    }
    for (int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    min_fun(a,&res1,&res2);
    //为了在主函数输出(unnecessary&foolish)修改主函数中变量,传入地址
    printf("\n最小值%d\n次最小值%d\n",res1,res2);
    return 0;
}