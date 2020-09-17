/*
Masthead - 
Owner - Master Mayank Meena 
Enroll no. 19114055, O-3
Code Editor - VSCode 2020
Terminal - WSL Ubuntu 2020

Contact - 
Website - https://mayankmeena.netlify.app/
Email - mayank_m@cs.iitr.ac.in

Social -
GitHub - https://github.com/maayami
YouTube - https://www.youtube.com/channel/UCwcdyxP6uk5zso-L4lY4Y8g?view_as=subscriber
Twitter - https://twitter.com/Meina_Mk
*/

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void radixSort(int arr[], int n, int k)
{
    int arrCount[k]={0}; /*Count array with length k */
    int arrSorted[n] = {0};
    int radixEle = 0;
    int p=0;

    for(int j=3; j<=192; j*=4){
        /* incrementing count of each element */
        for(int m=0; m<n; m++)
        {
            int temp = arr[m];
            int radixEle = (temp&j) / pow(4, p);
            cout<<radixEle<<" ";
            arrCount[radixEle]++;
        }
        cout<<" \n";
        /* taking sum of neibhour counts in counting Array */
        for(int l=1; l<k; l++)
        {
            arrCount[l] += arrCount[l-1];
        }
        for(int i=n-1; i>=0; i--)
        {
            int temp = arr[i];
            int radixEle = (temp&j) / pow(4, p);
            arrSorted[arrCount[radixEle]-1] = arr[i]; /* Since it returns position but we need index (ele-1) */
            arrCount[radixEle]--;
        }
        /* we will rarrange the elements of our original array wrt arrSorted */
        for(int q=0; q<n; q++)
        {
            arr[q] = arrSorted[q];
        }
        /* Count Sort for one radix element ends */

        p++;
    }

    // Now we have arrSorted as our final sorted array, we print and check.
    printArray(arr, n);
}

void solve()
{
    int n=5;
    // cin>>n;
    /* number of array elements */

    int k = 4;
    /* range of each radix element is 0 to 3 in our case, so total 4 possibilities */

    int arr[n] = {50,34,3,2,1};

    // for(int i=0; i<n; i++)
    // {
    //     cin>>arr[i];
    //     if(arr[i] > 255)
    //     cout<<"Please choose a number between [0-255]";
    // }

    // we call radixSort on our array.
    radixSort(arr, n, k);
    
}

int main(int argc, char const *argv[])
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    solve();
    return 0;
}

/*
References - 
https://www.geeksforgeeks.org/data-type-ranges-and-their-macros-in-c/    
https://www.geeksforgeeks.org/5-different-methods-find-length-string-c/
https://www.geeksforgeeks.org/string-at-in-cpp/
https://www.geeksforgeeks.org/converting-strings-numbers-cc/
*/