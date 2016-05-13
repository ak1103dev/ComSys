#include<stdio.h>
#include<stdlib.h>

#define N 65536
#define MAX 255
#define MIN 0

void merge(int *A, int *L, int leftCount, int *R, int rightCount) {
	int i, j, k;
	i = 0; j = 0; k =0;

	while(i < leftCount && j < rightCount) {
		if(L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void mergeSort(int *A, int n) {
	int mid, *L, *R;
	if(n < 2) return;

	mid = n / 2;

	L = (int*) malloc(mid * sizeof(int));
	R = (int*) malloc((n - mid) * sizeof(int));

	for(int i = 0; i < mid; i++) L[i] = A[i];
	for(int i = mid; i < n; i++) R[i - mid] = A[i];

	mergeSort(L, mid);
	mergeSort(R, n - mid);
	merge(A, L, mid, R, n - mid);
	free(L);
	free(R);
}

int main() {
	int A[N];
	for(int i = 0; i < N; i++) {
		A[i] = rand() % (MAX + 1) + MIN;
	}

	mergeSort(A, N);

	for(int i = 0;i < N; i++) {
		printf("%d\n", A[i]);
	}

	return 0;
}