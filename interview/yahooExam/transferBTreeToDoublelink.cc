/**
*1.build a binary tree form the preOrder array and inOrder array
*2.tranverse the binary tree built to the double linked list
*
*
*/
#include<iostream>
using namespace std;
struct Node{
	int value;
	Node* left;
	Node* right;
};

void transferToDoubleLinkList(Node* root,Node** head,Node **tail){
	if(root==NULL){
		*head = NULL;	
		*tail = NULL;
	}else{
		Node *leftHead  = NULL;	
		Node *leftTail = NULL;
		transferToDoubleLinkList(root->left,&leftHead,&leftTail);
		Node *rightHead  = NULL;	
		Node *rightTail = NULL;
		transferToDoubleLinkList(root->right,&rightHead,&rightTail);
		if(leftTail != NULL){
			leftTail->right = root;
		}
		root->left = leftTail;
		if(rightHead != NULL){
			rightHead -> left = root; 
		}
		root->right = rightHead;
		if(leftHead == NULL){
			*head = root;
		}else{
			*head = leftHead;
		}
		if(rightTail == NULL){
			*tail = root;
		}else{
			*tail = rightTail;
		}
	}
}

void inOrderTraverse(Node* root){
	if(root == NULL){
		return ;
	}else{
		inOrderTraverse(root->left);
		cout << root->value<<" ";
		inOrderTraverse(root->right);
	}
}

int findInOrderIndex(int inOrder[],int inStart,int inEnd,int key){
	for(int i=inStart;i<=inEnd;i++){
		if(inOrder[i] == key){
			return i;
		}
	}
	return -1;
}

Node* buildTree(int preOrder[],int preStart,int preEnd,
			int inOrder[],int inStart,int inEnd){
	if(preStart>preEnd){
		return NULL;
	}else if(preStart==preEnd){
		Node* root = new Node();
		root->left = NULL;
		root->right = NULL;
		root->value = preOrder[preStart];
		return  root;
	}else{
		Node* root = new Node();
		int rootValue = preOrder[preStart];
		int rootInOrderIndex = findInOrderIndex(inOrder,inStart,inEnd,rootValue);
		int preMid = preStart+(rootInOrderIndex-inStart);	
		Node* left = buildTree(preOrder,preStart+1,preMid,inOrder,inStart,rootInOrderIndex-1);
		Node* right = buildTree(preOrder,preMid+1,preEnd,inOrder,rootInOrderIndex+1,inEnd);
		root->left = left;
		root->right = right;
		root->value = rootValue;
		return root;
	}
}
void printDList(Node* head){
	while(head){
		cout << head->value<<" ";
		head = head->right;
	}
	cout <<endl;
}
int main(){
	int preOrder[7] = {10,6,4,8,14,12,16};		
	int inOrder[7]  = {4,6,8,10,12,14,16};		
	Node* root = buildTree(preOrder,0,6,inOrder,0,6);
	inOrderTraverse(root);
	cout <<endl;
	Node* head = NULL;
	Node* tail = NULL;
	transferToDoubleLinkList(root,&head,&tail);
	if(head == NULL){
		cout << "NULL"<<endl;
	}
	printDList(head);
}
