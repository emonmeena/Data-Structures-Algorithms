import java.util.*;

class Digits{

boolean digits(int i, int l){
    boolean isPalindrom = false;
    int[] arr = new int[l];
    int[] arr2 = new int[l];
    for(int j=0; j<l; j++){
        arr[j] =  i % 10;
        i /= 10;
    }
    for(int j=0; j<l; j++){
        arr2[j] =  arr[l-j-1];
    }

if(Arrays.equals(arr, arr2)){ isPalindrom = true;}

return isPalindrom;
    }
}

public class palindrom {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       int n = sc.nextInt();
        int l = (int)(Math.log(n)/Math.log(10)) + 1;
        Digits obj = new Digits();
        boolean isPalindrom = obj.digits(n, l);
        System.out.println(isPalindrom);
    }
}