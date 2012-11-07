#include<iostream>
using namespace std;
/**
*There are n continuous rectangles,the width of each rectangle is 1,the height 
*for each one is contained in a int array h,h[i] is the height of i-th rectangle.
*A combined rectangle means select several continuous rectangles, the width is the number of the selected
*continuous rectangle, and the height is the lowest one of the continuous rectangles.
*Please find a combined rectangle whose area is bigest.
*O(n)
*
*/
void printArray(int a[],int n){
	for(int i=0;i<n;i++){
		cout << a[i]<<" "; 
	}
	cout << endl;
}
int findBigestRectangle(int h[],int n){
	int* hStack = new int[n+1]; 	
	int top = 0;//the rear of the hStack
	hStack[0] = 0;
	int* maxArea = new int[n+1];
	int max = -1;
	maxArea[0] = 0;
	for(int i=1;i<=n;i++){
	//	printArray(hStack,top+1);
	//	printArray(maxArea,i);
		if(h[i]>=h[hStack[top]]){
			if(h[i]>h[hStack[top]]*(i-hStack[top])+maxArea[hStack[top]]){
				maxArea[i] = h[i];	
			}else{
				maxArea[i] = h[hStack[top]]*(i-hStack[top])+maxArea[hStack[top]];	
			}
		
		}else{
			while(h[hStack[top]] > h[i]){
				top--;		
			}
			if(top!=0){//consider the specific problem
				maxArea[i] = h[hStack[top]]*(i-hStack[top])+maxArea[hStack[top]];
			}else{
				maxArea[i] = i*h[i];
			}

		}
		hStack[++top] = i;
		if(max<maxArea[i]){
			max = maxArea[i];
		}
	}	
//	printArray(maxArea,n+1);
	delete[] hStack;
	delete[] maxArea;
	return max;
}
int main(){
	int h[9] = {0,3,5,4,3,7,1,4,2};
	cout << findBigestRectangle(h,8)<<endl;
	int h1[9] = {0,1,1,1,1,1,1,1,1};
	cout << findBigestRectangle(h1,8)<<endl;
}
