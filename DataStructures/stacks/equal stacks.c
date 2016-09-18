#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n1; 
    int n2; 
    int n3; 
    int s1=0,s2=0,s3=0;
    scanf("%d %d %d",&n1,&n2,&n3);
    int *h1 = (int *)malloc(sizeof(int) * n1);
    for(int h1_i = 0; h1_i < n1; h1_i++){
       scanf("%d",&h1[h1_i]);s1+=h1[h1_i];
    }
    int *h2 = (int *)malloc(sizeof(int) * n2);
    for(int h2_i = 0; h2_i < n2; h2_i++){
       scanf("%d",&h2[h2_i]);s2+=h2[h2_i];
    }
    int *h3 = (int *)malloc(sizeof(int) * n3);
    for(int h3_i = 0; h3_i < n3; h3_i++){
       scanf("%d",&h3[h3_i]);s3+=h3[h3_i];
    }
    int i=0,j=0,k=0;
    while(s1!=s2||s1!=s3){
    	while(s1>s2&&i<n1)
    	{s1-=h1[i];i++;}
    	while(s2>s3&&j<n2)
    	{s2-=h2[j];j++;}
    	while(s3>s1&&k<n3)
    	{s3-=h3[k];k++;}
	}
    printf("%d",s3);
    
    return 0;
}

