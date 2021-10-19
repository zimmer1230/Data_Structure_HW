#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int mode; // 0=encode, 1=decode
int n,m; // n chunks, m equations

char target[1000];
int target_len;
int chunks[1000]; //There will be n chunks, standing for x0 x1 x2 ...
int trivial[1000][1000];
int matrix[1060][1060];

void gauss(int);

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

                    for( int i=0; i<n; i++ ){
                              trivial[i][i] = 1;
                              trivial[i][n]= chunks[i];
                              for(int j=0; j<n+1; j++){
                                        printf( "%d ",trivial[i][j] );
                              }
                              printf("\n");
                    }

                    for( int i=0; i<m; i++ ){
                              for( int j=0; j<n; j++ ){
                                        matrix[i][j] = pow( (i+1),j );
                                        matrix[i][n]+=matrix[i][j]*chunks[j];
                                        printf("%d ",matrix[i][j]);
                              }
                              printf("%d\n",matrix[i][n]);

                    }

          }
          else if( mode==1 ){
                    scanf("%d",&n);
                    for( int i=0; i<n; i++ ){
                              for(int j=0;j<n+1;j++){
                                        scanf("%d",&matrix[i][j]);
                              }
                    }
                    gauss(n);
                    for(int i=0;i<n;i++)
                              printf("%d",matrix[i][n]);
          }
          return 0;
}

void swap(int a, int b){
          int temp = a;
          a = b;
          b = temp;
}

void gauss(int n)
