#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int mode; // 0=encode, 1=decode
int n,m; // n chunks, m equations

char target[1000];
int target_len;
int chunks[1000];
int main(){
          scanf("%d",&mode);
          if( mode==0 ){
                    scanf("%d%d",&n,&m);
                    scanf("%s",target);
                    target_len = strlen(target);
                    int pos = 0; // position of the target
                    for( int i=0;i<n ;i++ ){
                              char tmp_str[1000]={};
                              for(int j=0; j<(target_len/n); j++){
                                        tmp_str[j]=target[pos++];
                              }
                              chunks[i]=atoi(tmp_str);
                    }



          }
          else if( mode==1 ){

          }


          return 0;
}
