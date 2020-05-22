public class palindromReal {
    public static void main(String[] args) {
        boolean isPalindrom = false;
        int n = 545, var = n;
        int r=0;
        int l = (int)(Math.log(n)/Math.log(10));
        for(int i=l; i>=0; i--){
            int temp = n%10;
            r += temp*(Math.pow(10,i));
            n /= 10;
        }
        if(r == var){
            isPalindrom = true;
        }
        System.out.print(isPalindrom);

    }
}