import java.util.Scanner;

public class InputSplitBySpace {
    public int[] inputSplitBySpace() {
        Scanner sc = new Scanner(System.in);
        String inputString = sc.nextLine();
        String stringArray[] = inputString.split(" ");
        int num[] = new int[stringArray.length];
        for (int i = 0; i < stringArray.length; i++) {
            num[i] = Integer.parseInt(stringArray[i]);
        }
        return num;
    }
}