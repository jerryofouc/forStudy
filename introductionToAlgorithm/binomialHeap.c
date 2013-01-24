#include<stdio.h>
#include<stdlib.h>
#define MIN_INT 0x10000000
#define MAX_INT 0x7FFFFFFF
typedef struct BioNode* BioNodePtr;
typedef struct BioNode{
	BioNodePtr parent;	
	BioNodePtr child;
	int degree;
	int key;
	int value;
	BioNodePtr sibling;
}BioNode;
BioNodePtr binomial_heap_mininum(BioNodePtr h){
	BioNodePtr y = NULL;
	int min = MAX_INT;
	BioNodePtr p = h;		
	while(p){
		if(p->key<min){
			min = p->key;
			y = p;
		}
		p = p->sibling;
	}
	return y;
}

void binomial_link(BioNodePtr y,BioNodePtr x){
	y->parent = x;	
	y->sibling = x->child;
	x->child = y;
	x->degree++;
}

BioNodePtr binomial_heap_merge(BioNodePtr h1,BioNodePtr h2){
	BioNodePtr h = NULL,p1 = h1,p2 = h2;
	h = (BioNodePtr)malloc(sizeof(BioNode));
	h->degree = -1;//sentinal
	h->sibling = NULL;
	BioNodePtr p = h;
	while(p1&&p2){
		if(p1->degree < p2->degree||(p1->degree == p2->degree&&p1->key>p2->key)){
			p->sibling = p1;
			p1 = p1->sibling;
		}else{
			p->sibling = p2;
			p2 = p2->sibling;
		}
		p = p->sibling;
		p->sibling = NULL;
	}
	p = h;		
	h = h->sibling;
	free(p);
}

BioNodePtr binomial_heap_Union(BioNodePtr h1, BioNodePtr h2){
	BioNodePtr h = binomial_heap_merge(h1,h2);
	if(h == NULL){
		return NULL;
	}
	BioNodePtr pre = NULL;
	BioNodePtr x = h;
	BioNodePtr next = x->sibling;
	while(next){
		if(x->degree != next->degree || (
					next->sibling!=NULL&&x->degree == next->sibling!->degree )){//case 1 and case 
				pre = x;
				x = next;
		}else if(x->key <= next->key){
			x->sibling = next->sibling;
			binomial_link(next,x);
		}else{
			if(pre == NULL){
				h = next;
			}else{
				pre->sibling = next;
			}
			binomial_link(x,next)
			x = next;
		}
		next = x->sibling;
	}
	return h;
}
BioNodePtr binomial_heap_Insert(BioNodePtr h1,BioNodePtr x){
	h2 = x;
	x->parent = NULL;
	x->sibling = NULL;	
	x->degree = 0;
	x->child = NULL;
	return binomial_heap_Union(h1,h2);	
}

int main(){
}
