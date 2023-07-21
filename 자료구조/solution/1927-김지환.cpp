//acmicpc 1927
//authored by jihwankim
//23-07-21 PM 03:11

#include <bits/stdc++.h>

using namespace std;

int n;
int heap[100005];
int heapSize = 0;

int top() {
	if(heapSize == 0) return 0;
	return heap[1]; 
}

void pop() {
	if(heapSize == 0) return ;
	
	swap(heap[1], heap[heapSize]);
	heap[heapSize--] = 0;
	int parentIdx = 1;
	
	while(2*parentIdx <= heapSize) {
		int left = parentIdx*2;
		int right = parentIdx*2+1;
		if((heap[left] > heap[right]) && right <= heapSize) {
			left = right;
		}
		if((heap[left] < heap[parentIdx]) && heap[left] != 0) {
			swap(heap[left], heap[parentIdx]);
			parentIdx = left;
		}
		else break;
	}
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void push(int num) {
	heap[++heapSize] = num;
	
	int childIdx = heapSize;
	while(childIdx) {
		int parentIdx = childIdx/2;
		if(heap[parentIdx] > heap[childIdx]) {
			swap(heap[childIdx], heap[parentIdx]);	
		} 
		else break;
		
		childIdx = parentIdx;
	}
}

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		int num;
		cin >> num;
		if(num == 0) {
			cout << top() << "\n";
			pop();
		}
		else push(num);
	}	
}

void printHeap() {
	for(int i = 1; i<=n; i*=2) {
		for(int j = i; j<i*2; j++) {
			if(heap[j] == 0) break;
			cout << heap[j] << " ";
		}
		cout << "\n";
	}
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	
	return 0;
}
// PM 04:10
