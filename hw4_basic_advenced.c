#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int p,n,m,input;
unsigned int hash(unsigned int x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x%m;
}
int main(){
    int p,n,m,input;
    scanf("%d%d%d",&p,&m,&n);
    bool* bucket=(bool*)calloc(m,sizeof(bool));
    while(n--){
        scanf("%d",&input);
        printf("%d ",input);
        (bucket[hash(input)]==1)?printf("0\n"):printf("1\n");
        bucket[hash(input)]=1;
    }


}

