#include<iostream>
using namespace std;
struct Node{
	int value;
	Node* left;
	Node* right;
};
Node* insertIntoTree(Node* root,int key){
	Node* newNode = new Node();
	newNode->value = key;
	newNode->left = NULL;
	newNode->right = NULL;
	if(root == NULL){
		root = newNode;
	}else{
		Node* parent =	 NULL;
		Node* cur = root;
		while(cur){
			parent = cur;
			if(key<cur->value){
				cur = cur->left;	
			}else{
				cur = cur->right;
			}
		}
		if(key<parent->value){
			parent->left = newNode; 	
		}else{
			parent->right = newNode;
		}
	}
	return root;
}

void inOrderWalk(Node* root,int& i,int array[],int n){
	if(!root){
		return;
	}
	if(root->left){
		inOrderWalk(root->left,i,array,n);
	}
	array[i++] = root->value;
	if(root->right){
		inOrderWalk(root->right,i,array,n);
	}
	
}

void insertionSort(int array[],int n){
	Node* root = NULL;
	for(int i=0;i<n;i++){
		root = insertIntoTree(root,array[i]);
	}
	int i=0;
	inOrderWalk(root,i,array,n);
}

void print(int array[],int n){
	for(int i=0;i<n;i++){
		cout << array[i]<<" ";
	}
	cout << endl;
}
int main(){
	int array[10] = {5,67,7,2,3,2,4,21,5,66};
	print(array,10);
	insertionSort(array,10);
	print(array,10);
	int array1[10] = {5};
	print(array1,1);
	insertionSort(array1,1);
	print(array1,1);
}
