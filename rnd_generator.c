#include <stdio.h>

int main(){
    int prnd=3;
    int m=31;
    for(int i=0;i<100;i++){
        printf("%d\n",prnd=(7*prnd+4)%9);
    }


}
