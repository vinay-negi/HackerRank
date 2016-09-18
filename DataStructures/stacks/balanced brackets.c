#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct node{
    char data;
    struct node *next;
}node;
void push(node **top,char c){
    node *p=(node*)malloc(sizeof(node));
    p->data=c;
    p->next=NULL;
    if(*top==NULL){
        *top=p;
        return;
    }
    p->next=*top;
    *top=p;
}
int pop(node **top,char c){
    if(*top==NULL)return 0;
    node *t=*top;
    if(t->data=='('&&c==')'){
        *top=t->next;
        free(t);
        return 1;
    }
   else if(t->data=='['&&c==']'){
        *top=t->next;
        free(t);
        return 1;
    }
   else if(t->data=='{'&&c=='}'){
        *top=t->next;
        free(t);
        return 1;
    }
    return 0;
        
    
}
int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        char* s = (char *)malloc(10240 * sizeof(char));
        scanf("%s",s);
        node *top=NULL;
        int flag=1;
        while(*s&&flag){
             if(*s=='{'||*s=='('||*s=='[')
                 push(&top,*s);
            else if(*s=='}'||*s==')'||*s==']')
                {
                flag=pop(&top,*s);
                if(!flag){
                    printf("NO\n");
                    break;
                }
                    
            }
            s++;
        }
        if(flag==1&&top==NULL){
            printf("YES\n");
        }
        else if(flag==1)
            printf("NO\n");
        
        
         
        } 
    
    return 0;
}

