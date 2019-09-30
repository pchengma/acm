import java.util.Scanner;

public class ReadText {

    private Scanner input;

    void read_one_string() {
        input = new Scanner(System.in);

        String s = input.nextLine();

        String[] s1 = s.split("\\s+");

        for (int i = 0; i < s1.length; i++) {
            System.out.println(s1[i]);
        }
    }

}  