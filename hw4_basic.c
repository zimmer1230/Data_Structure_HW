#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct bit{
    unsigned int f_0;
    unsigned int f_1;
    unsigned int f_2;
    unsigned int f_3;
    unsigned int f_4;
    unsigned int f_5;
    unsigned int f_6;
    unsigned int f_7;
};
typedef struct bit bit;

int main(){
    int p,n,m,input;
    scanf("%d%d%d",&p,&m,&n);
    bit* bucket=(bit*)calloc(1+(m/8),sizeof(bit));
    while(n--){
        scanf("%d",&input);
        printf("%d ",input);



    }


}
