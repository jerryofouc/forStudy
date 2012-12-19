#include<stdio.h>
#include<string.h>
#define NHASH 29989
#define MUTI 31
typedef struct node* node_ptr;
typedef struct node{
	char* word;
	int count;
	node_ptr next;
} node;
node_ptr bin[NHASH];
int hash(char* word){
	int ret = 0;
	char* p = word;
	for(;*p;p++){
		ret = MUTI*ret + (int)(*p);
	}
	return ret%NHASH;
}
void incrCount(char* word){
	int h = hash(word);
	node_ptr p = bin[h];
	for(;p;p=p->next){
		if(strcmp(word,p->word) == 0){
			++p->count;
			return;
		}
	}
	
	node_ptr pNew = (node_ptr)malloc(sizeof(node));
	pNew->next = p;
	pNew->count = 1;
	pNew->word = (char*)malloc(strlen(word)+1);
	strcpy(pNew,p);
	bin[h] = pNew;	
}
void main(){
}
