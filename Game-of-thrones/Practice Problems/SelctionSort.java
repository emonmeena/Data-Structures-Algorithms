class Selection{
    int[] sort(int arr[]){
        int temp;
        int minIndex = 0;
        int l = arr.length;
        for(int j=0; j<l-1; j++){
            for(int i=j; i<l; i++){
                if(arr[i] < arr[minIndex]){
                    minIndex = i;
                }
            }
                temp = arr[j];
                arr[j] = arr[minIndex];
                 arr[minIndex] = temp; 
            
        }
        return arr;
    }
}

public class SelctionSort {
    public static void main(String[] args) {
        int arr[] = {5,4,3,2,1};
        Selection obj = new Selection();
        obj.sort(arr);
        for(int x : arr)
            System.out.print(arr[x-1]+" ");
    }
}