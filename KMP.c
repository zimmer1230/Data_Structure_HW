#include <stdio.h>
#include <string.h>
int kmp(char*, char*);
char str[10000]={};
char pat[10000]={};
int failure_function[10000];
int main(){
          scanf("%s",str);
          scanf("%s",pat);
          printf("%d",kmp(str,pat));
return 0;
}


int kmp(char *s, char *p){
/*
    KMP solution for searching pattern in a string
    Time Complexity: O(m+n)
    Space Complexity: O(m)
    args:
        s: target string
        p: pattern
    returns:
        is_match: a boolean value to show if the pattern exists in s
*/
    int n = strlen(s);
    int m = strlen(p);

    // Build failure function recording longest proper suffix and prefix
    // dp
    for(int i=1;i<m;i++){
        int j = failure_function[i-1];
        while (p[j] != p[i]){
          if (j == 0)
                    break;
          j = failure_function[j-1];
          if (p[j] == p[i])
            failure_function[i] = j + 1;
        else
            failure_function[i] = 0;
        }
    }

    int i = 0;
    int j = 0;
    while (i < n){
        if (s[i] != p[j]){
            if (j == 0){
                i += 1;
                continue;
            }
            // Lookup the longest proper suffix and prefix before current character
            j = failure_function[j-1];
        }
        else{
            i += 1;
            j += 1;
        }

        if (j == m)
            return 1;
    }
    return 0;
}
