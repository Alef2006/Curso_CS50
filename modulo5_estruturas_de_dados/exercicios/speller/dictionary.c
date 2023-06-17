
#include <stdbool.h>
#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>


typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

const unsigned int N = 26;
int count=0;

node *table[N];

bool check(const char *word)
{
    int hashNum=hash(word);
    node*cursor=table[hashNum];

    while(cursor!=NULL){
    if(strcmp(cursor->word,word)==0){
     return true;
    }

    cursor=cursor->next;
    }

    return false;
}

unsigned int hash(const char *word)
{
    return toupper(word[0]-'A');
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    FILE *DictiFile=fopen(dictionary,"r");

    if(DictiFile==NULL){
        return false;
    }

    char str[LENGTH+1];
    while(fscanf(DictiFile,"%s",str)!=EOF){


      node *temp=malloc(sizeof(node));

      if(temp==NULL){
          return false;
      }

      strcpy(temp->word,str);

      int hashNum=hash(str);

      if(table[hashNum]==NULL){
        temp->next=NULL;
      }else{
          temp->next=table[hashNum];
      }

      table[hashNum]=temp;
      count+=1;
    }
    fclose(DictiFile);
    return true;
}

unsigned int size(void)
{
    return count;
}

void freenode(node *n){
 if(n->next != NULL){
     freenode(n->next);
 }
 free(n);

}

bool unload(void)
{
    for(int i=0;i<N;i++){
      if(table[i]!=NULL){
          freenode(table[i]);
      }
    }
    return true;

}
