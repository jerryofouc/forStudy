#include<iostream>
#include<stdlib.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
const int MAX_LEVEL = 50;
const int MAX_INT = 0x7fffffff;
const int MIN_INT = 0x90000000;
typedef struct node* node_ptr;
typedef struct node{
	int key;
	int value;
	node_ptr forward[MAX_LEVEL];
}node;
node NIL;
typedef struct list{
	int level;
	node_ptr head;
}list;
list* initList(){
	NIL.key = MAX_INT;
	list* l = new list();
	l->level = 1;
	l->head = new node();
	for(int i=0;i<MAX_LEVEL;i++){
		l->head->forward[i] = &NIL;
	}
	return l;
}
int search(list* l,int key){
	node_ptr x = l->head;
	for(int i=l->level;i>0;i--){
		while(x->forward[i]->key<key){
			x = x->forward[i];
		}
	}
	if(x->forward[1]->key == key){
		return x->forward[1]->value;
	}else{
		return MIN_INT;
	}
}
int randMaxLevel(){
	int level = 1;
	while(rand()%10<5&&level<MAX_LEVEL){
		level++;
	}
	return level;

}
int min(int a,int b){
	return a>b?b:a;
}
void insertNode(list* list, int key,int value){
	node_ptr update[MAX_LEVEL];		
	node_ptr x = list->head;
	for(int i=list->level;i>0;i--){
		while(x->forward[i]->key<key){
			x = x->forward[i];
		}
		update[i] = x;
	}
	if(x->forward[1]->key == key){
		x->forward[1]->value = value;
		return ;
	}else{
		node_ptr p= new node();
		p->key = key;
		p->value = value;
		int gl = randMaxLevel();
		if(gl>list->level){
			cout <<gl<<endl;
			for(int i = gl;i>list->level;i--){
				update[i] = list->head;
			}
			list->level = gl;
		}
		for(int i = 1;i<=list->level;i++){
			p->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = p;	
		}
	}
	
}
void deleteNode(list* list,int key){
	node_ptr update[MAX_LEVEL];
	node_ptr x = list->head;
	for(int i=list->level;i>0;i--){
		while(x->forward[i]->key<key){
			x = x->forward[i];
		}
		update[i] = x;
	}
	if(x->forward[1]->key != key){
		return;
	}else{
		for(int i=1;i<list->level;i++){
			if(update[i]->forward[i] != x){
				break;
			}else{
				update[i]->forward[i] = x->forward[i];
			}
		}
		delete x;
		for(int i=list->level;i>0;i--){
			if(list->head->forward[i] == &NIL){
				list->level--;
			}
		}
	}
	
	
}
int main(){
	srand(time(NULL));
	list* l = initList();	
	cout << "init complete"<<endl;
	for(int i=0;i<100000;i++){
		insertNode(l,i,i+1);
		if(i>10000&&i%5000==0){
			cout << i<<endl;
			
		}
	}
	cout << "insert complete"<<endl;
	cout << search(l,999)<<endl;	
}
