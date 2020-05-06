package GFG.ArrayRotaion;

public class Function {
   public void function(int arr[], int n, int d){
       StringBuffer sb = new StringBuffer();
       for(int i=d; i<n; i++){
           sb.append(arr[i]+" ");
       }
       for(int i=0; i<d; i++){
           sb.append(arr[i]+" ");
       }
    System.out.println(sb);
   } 
}