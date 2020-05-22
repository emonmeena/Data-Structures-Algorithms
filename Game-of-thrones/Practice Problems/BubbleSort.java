
class Bubble{
    boolean isSorted =true;
    int[] sort(int[] arr){
        for(int i=0; i<arr.length - 1; i++){
               
            for(int j=1; j<arr.length - i; j++){
                int temp;
                if(arr[j-1]>arr[j]){
                    temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;  
                    isSorted = false;
                }
                if(isSorted){break; }
            }
        }
return arr;
    }
}

public class BubbleSort {
    public static void main(String[] args) {
        int[] Arr = {5,4,3,2,1};
        Bubble obj = new Bubble();
       obj.sort(Arr);
        for(int x: Arr ){
        System.out.print(Arr[x-1] + " ");
        }         
    }    
}