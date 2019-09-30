public class Test {

    public static void main(String[] args) {
        int a[] = {0, 1, 2, 3};
        int j = 0;
        a[j++] += 1;
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }

    }
}
