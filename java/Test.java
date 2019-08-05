package exercise;

public class Test {

	public static void main(String[] args) {
		/*
		 * ReadTxt readtxt = new ReadTxt();
		readtxt.read_one_string();
		*/
		
		Sort mergesort = new Sort();
		int a[] = {1, 2, 3, 4};
		int temp[] = {1, 2};
		mergesort.mergeSort(a, 0, 3, temp);
	}
}
