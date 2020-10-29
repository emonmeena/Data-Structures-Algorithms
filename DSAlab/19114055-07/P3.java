import java.util.Scanner;

class Map{
    int data;
    int index;
}

class P3{
    static int insideIndex = 0;
    static void in_order(int binarTree[],int nNodes,int index,int inOrder[]){
        if(index >= nNodes)return;
        in_order(binarTree,nNodes,2*index + 1,inOrder);
        inOrder[insideIndex] = binarTree[index];
        insideIndex++;
        in_order(binarTree,nNodes,2*index + 2,inOrder);
    }
    static int partition(Map arr[],int low,int high){
        int comp = arr[high].data;
        int pivot = low-1;
        for(int i = low;i<high;i++){
            if(arr[i].data <= comp ){
                pivot++;
                int d1 = arr[i].data;
                int i1 = arr[i].index;
                int data2 = arr[pivot].data;
                int index2 = arr[pivot].index;
                arr[i].data = data2;
                arr[i].index = index2;
                arr[pivot].data = d1;
                arr[pivot].index = i1; 
            }
        }
                int d1 = arr[high].data;
                int i1 = arr[high].index;
                int d2 = arr[pivot+1].data;
                int i2 = arr[pivot+1].index;
                arr[high].data = d2;
                arr[high].index = i2;
                arr[pivot+1].data = d1;
                arr[pivot+1].index = i1; 

        return pivot+1;

    }
    static void quick_sort(Map arr[],int low,int high){
        if(low < high){
            int partIndex = partition(arr,low,high);
            quick_sort(arr,low,partIndex-1);
            quick_sort(arr,partIndex+1,high);

        }
    }
    static int min_swaps_required(int inOrder[],int nNodes){
        Map arr[] = new Map[nNodes];
        int sol = 0;
        for(int i = 0;i<nNodes;i++){
            arr[i] = new Map();
            arr[i].data = inOrder[i];
            arr[i].index = i;
        }
        quick_sort(arr,0,nNodes-1);
        for(int i = 0;i < nNodes;i++){
            if(i == arr[i].index)continue;
            else{
                sol++;
                int temp = arr[i].data;
                arr[i].data = arr[arr[i].index].data;
                arr[arr[i].index].data = temp;

                temp = arr[i].index;
                arr[i].index = arr[temp].index;
                arr[temp].index = temp;

                if(i != arr[i].index)i--;
            }

        }
        return sol;

    }
    public static void main(String args[]){
         Scanner sc = new Scanner(System.in); 
         int no_of_nodes = sc.nextInt();
         int binary_tree[] = new int[no_of_nodes];
         for(int i = 0;i<no_of_nodes;i++)binary_tree[i] = sc.nextInt();
         int inorder[] = new int[no_of_nodes];
         in_order(binary_tree,no_of_nodes,0,inorder);
         int ans = min_swaps_required(inorder,no_of_nodes);
         System.out.println(ans);
        
    }
}

//9 5 7 9 2 10 6 3 1 8