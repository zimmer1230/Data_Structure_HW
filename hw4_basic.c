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
#define h_input input%p%m
        switch(h_input%8){
        case 0:
            if(bucket[h_input/8].f_0==0){
                printf("1\n");
                bucket[h_input/8].f_0=1;
            }
            else{
                printf("0\n");
            }
            break;
        case 1:
            if(bucket[h_input/8].f_1==0){
                printf("1\n");
                bucket[h_input/8].f_1=1;
            }
            else{
                printf("0\n");
            }
            break;
        case 2:
            if(bucket[h_input/8].f_2==0){
                printf("1\n");
                bucket[h_input/8].f_2=1;
            }
            else{
                printf("0\n");
            }
            break;
        case 3:
            if(bucket[h_input/8].f_3==0){
                printf("1\n");
                bucket[h_input/8].f_3=1;
            }
            else{
                printf("0\n");
            }
            break;
        case 4:
            if(bucket[h_input/8].f_4==0){
                printf("1\n");
                bucket[h_input/8].f_4=1;
            }
            else{
                printf("0\n");
            }
            break;
        case 5:
            if(bucket[h_input/8].f_5==0){
                printf("1\n");
                bucket[h_input/8].f_5=1;
            }
            else{
                printf("0\n");
            }
            break;
        case 6:
            if(bucket[h_input/8].f_6==0){
                printf("1\n");
                bucket[h_input/8].f_6=1;
            }
            else{
                printf("0\n");
            }
            break;
        case 7:
            if(bucket[h_input/8].f_7==0){
                printf("1\n");
                bucket[h_input/8].f_7=1;
            }
            else{
                printf("0\n");
            }
            break;
        }

    }


}
