// not Optimized, only Workable...
import java.util.*;

class CheckAnagram{
public boolean isAnagram(String str1, String str2, int n){

char[] ch1 = str1.toCharArray(), ch2 = str2.toCharArray();
Arrays.sort(ch1);
Arrays.sort(ch2);
    if(Arrays.equals(ch1, ch2)){
        return true;
    }
    return false;
}
 }

public class Anagram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        CheckAnagram ObjAnagram = new CheckAnagram();
        int n = str1.length();

        if(str1.length() == str2.length()){
        System.out.println(ObjAnagram.isAnagram(str1, str2, n));
        }
        else System.out.println("Not Anagram");
    }
}