import java.util.Scanner;

public class SplitbyWord {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println();
     System.out.println("Type Anything:");
        String str  = sc.nextLine();
        int length = str.length();
        int n=1;
       while(length > 0){
           if(str.charAt(length-1) == ' ')
                n++;
           length--;
       }
        
        String strArray[] = str.split(" ");   

for(int i=0; i<n; i++)
    System.out.print(strArray[n-i-1]+" ");

    }
}