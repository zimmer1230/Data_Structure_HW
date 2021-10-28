#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int mode; // 0=encode, 1=decode
int n,m; // n chunks, m equations

char target[5000];
int target_len;
int chunks[5000]; //There will be n chunks, standing for x0 x1 x2 ...
int trivial[5000][5000];
double matrix[5060][5060];
int x[5060];

void gaussian_elimination();
void back_substitution();

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
                                        printf("%.f ",matrix[i][j]);
                              }
                              printf("%.f\n",matrix[i][n]);

                    }

          }
          else if( mode==1 ){
                    scanf("%d",&n);
                    if(n>5000)
                              return 0;
                    for( int i=0; i<n; i++ ){
                              for(int j=0;j<n+1;j++){
                                        scanf("%lf",&matrix[i][j]);
                              }
                    }
                    gaussian_elimination();
                    back_substitution();
                    for(int i=0; i<n;i++)
                              printf("%d",x[i]);
          }
          return 0;
}

void swap(double *a, double *b){
          double temp = *a;
          *a = *b;
          *b = temp;
}

void gaussian_elimination()
{
    for (int i=0; i<n; ++i) // �p�G����������Y�Ƭ��s�A���ջP�U�����洫�C
    {
        if (matrix[i][i] == 0)
            for (int j=i+1; j<n; ++j)
                if (matrix[j][i] != 0)
                {
                    // �洫�W�����P�U�����C
                    for (int k=i; k<n+1;++k)
                        swap(&matrix[i][k],&matrix[j][k]);
                    break;
                }

        // �p�G�����Y�Ƴ��O�s�A���N���L�C
        if (matrix[i][i] == 0) continue;

        // ����������Y�ƽվ㦨�@�C���F���﨤�u�Ҭ��@�C
        double t = matrix[i][i];    // �����Y��
        for (int k=i; k<n+1; ++k)
            matrix[i][k] /= t;

        // ��P�U�����A�O�U�����������Y�ƤƦ��s�C
        for (int j=i+1; j<n; ++j)
            if (matrix[j][i] != 0)
            {
                double t = matrix[j][i];
                for (int k=i; k<n+1; ++k)
                    matrix[j][k] -= matrix[i][k] * t;
            }
    }
}

void back_substitution()
{
    for (int i=n-1; i>=0; --i)
    {
        if (matrix[i][i] == 0) return;  // �L�ѡB�h��

        double t = 0;
        for (int k=i+1; k<n+1; ++k)
            t += matrix[i][k] * x[k];
        x[i] = (int)( ( (matrix[i][n] - t))+0.5);
    }
}
