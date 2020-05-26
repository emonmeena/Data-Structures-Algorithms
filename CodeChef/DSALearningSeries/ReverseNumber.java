package CodeChef.DSALearningSeries;

// Reference - https://www.geeksforgeeks.org/stringbuilder-class-in-java-with-examples/

public class ReverseNumber {
    public static void reversedNum(String s, int l){
        StringBuilder sb = new StringBuilder(s);
        sb = sb.reverse();
        System.out.println(sb);
    }
}
