package exercise;

public class Sort {

	public void mergeArray(int a[], int first, int mid, int last, int temp[]) {
		int i = first, j = mid + 1;
		int m = mid, n = last;
		int k = 0;
		
		while (i <= m && j <= n) {
			if (a[i] <= a[j]) {
				temp[k++] = a[i++];
			}
			else {
				temp[k++] = a[j++];
			}
		}
		
		while (i <= m) {
			temp[k++] = a[i++];
		}
		
		while (j <= n) {
			temp[k++] = a[j++];
		}
		
		for (i = 0; i < k; i++) {
			a[first + 1] = temp[i];
		}
	}
	
	public void mergeSort(int a[], int first, int last, int temp[]) {
		if (first < last) {
			int mid = (first + last) / 2;
			mergeSort(a, first, mid, temp);
			mergeSort(a, mid + 1, last, temp);
			mergeArray(a, first, mid, last, temp);
		}
	}
}
