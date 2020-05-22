public class TwoPointer {
    public static void main(String[] args) {
        
        int[] arr = {1, -2, 1, 0, 5};
        int n = arr.length;
        int end=n, start=0;
        int sum=0;
        
        // boolean b= false;
        for(int i=start; i<end; i++){
            for(int j=start; j<end; j++){
                if(i>=j){continue;}
                for(int k=start; k<end; k++){
                    if(j>=k || i>=k){continue;}
                   else  if(arr[i]+arr[j]+arr[k] == 0){
                   
                   if(i+j+k == sum){
                    continue;
                   }
        System.out.println(arr[i]+" "+arr[j]+" "+arr[k]);
                   sum =i+j+k;
                   }
                }

            }

        }
    }
}