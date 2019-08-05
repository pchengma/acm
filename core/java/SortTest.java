package core.java;

public class SortTest {

	public static void main(String[] args) {
		Sort sort = new Sort();
		int a[] = {10, 7, 8, 9, 1, 5};
		int temp[] = {1, 2};
		//sort.mergeSort(a, 0, 5);
		sort.shellSort(a);
        for (int i = 0; i < a.length; i++) {
        	System.out.println(a[i]);
        }
	}

}
