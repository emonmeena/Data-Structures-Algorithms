import java.util.*;

class LeftRotate{
 int[] rotate(int arr[], int eleD){
    int l = arr.length;
    int A[] = new int[l];
    for(int i=0; i<l-1; i++){
        A[i] = arr[i+1];
        A[l-1] = arr[0];
    }
    if(A[0] == eleD){return A;}
    return rotate(A, eleD);
 }
}

public class DynamicArray {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0; i<n; i++){
            arr[i] =sc.nextInt();
        }
       
        if(d==n){
            for(int x=0; x<n; x++)
                System.out.print(arr[x]+" ");
        }
        else{int eleD = arr[d];
            LeftRotate objLeftRotate  = new LeftRotate();
            int A[] = objLeftRotate.rotate(arr, eleD);
            for(int x=0; x<n; x++)
                System.out.print(A[x]+" ");}
    }
}
