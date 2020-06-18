package GFG;

public class Function {
    public void function(int arr[], int n){
        int a, b;
        StringBuffer sb = new StringBuffer();
        for(int i=0; i<n-1; i++){
         a=arr[i];
         b=arr[i+1];
         
         if(a>b){
             sb.append(a+" "); 
             if(i == n-2){
                 sb.append(arr[n-1]);
             }
         }
        }
    } 
}