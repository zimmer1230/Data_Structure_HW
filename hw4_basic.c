#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
int main(){
    int p,n,m,input;
    scanf("%d%d%d",&p,&m,&n);
    bool* bucket=(bool*)calloc(m,sizeof(bool));
    while(n--){
        scanf("%d",&input);
        printf("%d ",input);
        (bucket[input%p%m]==1)?printf("0\n"):printf("1\n");
        bucket[input%p%m]=1;
    }


}
