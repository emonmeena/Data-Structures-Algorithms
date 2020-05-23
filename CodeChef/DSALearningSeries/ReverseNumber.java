package CodeChef.DSALearningSeries;

public class ReverseNumber {
    public static void reversedNum(String s, int l){
        String ans="";
        for(int i=l-1; i>=0; i--){
            ans += s.charAt(i);
        }
        System.out.println(ans);
    }
}