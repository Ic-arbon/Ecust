#include <stdio.h>

int f(int i);
int main(){
    int n;
    int a[0];//no need to define an array!
    scanf("%d",&n);//给个正整数plz
    for(int i=1;i<=n;i++){
        printf("%d ",f(i));
    }
    printf("\n");
    return 0;
}

int f(int i){
    if(i==0) return 0;
    if(i==1) return 1;
    return f(i-2)+f(i-1);
}