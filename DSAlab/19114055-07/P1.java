import java.util.Scanner;
class P1{
    
    static long minNodes(int h,int a,int b){
        if(h == 0){
            return 1;
        }
        else if(h == 1){
            return b;
        }
        
        return minNodes(h-1, b, a+b+1);
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int a=1,b=2;
        long nNodes = minNodes(h,a,b);
        System.out.println("Number of nodes: "+nNodes);
    }
}