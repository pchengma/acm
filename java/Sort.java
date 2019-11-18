import java.util.Arrays;

public class Sort {

    void shellSort(int arr[]) { 
        int n = arr.length; 
        for (int gap = n/2; gap > 0; gap /= 2) { // log(n)
            for (int i = gap; i < n; i++) { 
                int temp = arr[i]; 
                int j; 
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                    arr[j] = arr[j - gap]; 
                arr[j] = temp; 
            }
        }
    }
    
    void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        
        int L[] = new int [m - l + 1];
        int R[] = new int [r - m];
        
        for (int i = 0; i < n1; i++) {
            L[i] = arr[l+i];
        }
        
        for (int j = 0; j < n2; j++) {
            R[j] = arr[m+1+ j];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
            	arr[k++] = L[i++];
            }
            else {
            	arr[k++] = R[j++];
            }
        }
  
        while (i < n1) { 
        	arr[k++] = L[i++]; 
        }
  
        while (j < n2) { 
            arr[k++] = R[j++]; 
        } 
    } 
    
    void mergeSort(int arr[], int l, int r) { 
        if (l < r) { 
            int m = (l + r) / 2; 

            mergeSort(arr, l, m); 
            mergeSort(arr , m+1, r); 

            merge(arr, l, m, r); 
        } 
    }
    
    // A utility function to get maximum value in arr[] 
    static int getMax(int arr[], int n) { 
        int mx = arr[0]; 
        for (int i = 1; i < n; i++) 
            if (arr[i] > mx) 
                mx = arr[i]; 
        return mx;
    } 
  
    // A function to do counting sort of arr[] according to 
    // the digit represented by exp. 
    void countSort(int arr[], int n, int exp) { 
        int output[] = new int[n]; // output array 
        int i; 
        int count[] = new int[10]; 
        Arrays.fill(count,0); 
  
        // Store count of occurrences in count[] 
        for (i = 0; i < n; i++) {
            count[ (arr[i]/exp)%10 ]++; 
        }
  
        // Change count[i] so that count[i] now contains 
        // actual position of this digit in output[] 
        for (i = 1; i < 10; i++) {
            count[i] += count[i - 1]; 
        }

        // Build the output array 
        for (i = n - 1; i >= 0; i--) { 
            output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
            count[ (arr[i]/exp)%10 ]--; 
        } 
  
        // Copy the output array to arr[], so that arr[] now 
        // contains sorted numbers according to curent digit 
        for (i = 0; i < n; i++) {
            arr[i] = output[i]; 	
        }
    } 
  
    // The main function to that sorts arr[] of size n using 
    // Radix Sort 
    void radixSort(int arr[], int n) { 
        // Find the maximum number to know number of digits 
        int m = getMax(arr, n); 
  
        // Do counting sort for every digit. Note that instead 
        // of passing digit number, exp is passed. exp is 10^i 
        // where i is current digit number 
        for (int exp = 1; m/exp > 0; exp *= 10) {
            countSort(arr, n, exp); 
        }
    }
    
    /* This function takes last element as pivot, 
    places the pivot element at its correct 
    position in sorted array, and places all 
    smaller (smaller than pivot) to left of 
    pivot and all greater elements to right 
    of pivot */
    int partition(int arr[], int low, int high) { 
    	int pivot = arr[high];  
    	int i = (low-1); // index of smaller element 
    	for (int j=low; j<high; j++) { 
    		// If current element is smaller than or 
    		// equal to pivot 
    		if (arr[j] <= pivot) { 
    			i++; 
    			// swap arr[i] and arr[j] 
    			int temp = arr[i]; 
    			arr[i] = arr[j]; 
    			arr[j] = temp; 
    		} 
    	} 

    	// swap arr[i+1] and arr[high] (or pivot) 
    	int temp = arr[i+1]; 
    	arr[i+1] = arr[high]; 
    	arr[high] = temp; 

    	return i+1; 
    } 


    /* The main function that implements QuickSort() 
   	arr[] --> Array to be sorted, 
   	low  --> Starting index, 
   	high  --> Ending index 
   	*/
    void quickSort(int arr[], int low, int high) { 
    	if (low < high) { 
    		/* pi is partitioning index, arr[pi] is  
           	now at right place */
    		int pi = partition(arr, low, high); 

    		// Recursively sort elements before 
    		// partition and after partition 
    		quickSort(arr, low, pi-1); 
    		quickSort(arr, pi+1, high); 
    	} 
    }
    
}
