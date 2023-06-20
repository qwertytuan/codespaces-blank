#include <stdio.h>

int main() {
	int n;
	printf("Nhap n:");
	scanf("%d", &n);
	int arr[n];
	 for(int i=0;i<n;i++) {
	 	printf("Nhap arr[%d]: ",i);
		scanf("%d",&arr[i]);	
	 }

	int max = arr[0];
	
	for (int i = 0; i < n; i++) {
		max = (arr[i] > max) ? arr[i]: max;
	}
	printf("%d", max);
}