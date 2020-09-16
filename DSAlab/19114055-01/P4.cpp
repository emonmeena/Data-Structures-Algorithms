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
    int arrK[k]={0}; /*Count array with length k */
    int arrSorted[n];
    int radixEle;
    int p=0;

    for(int j=3; j<=192;){

        for(int i=0; i<n; i++)
        {
            radixEle = (arr[i]&j) / pow(4, p);
            arrK[radixEle]++;
        }
        for(int i=1; i<k; i++)
        {
            arrK[i] += arrK[i-1];
        }
        for(int i=n-1; i>=0; i--)
        {
            int radixEle;
            int kIndex;
            radixEle = (arr[i]&j) / pow(4, p);
            kIndex = arrK[radixEle];
            arrSorted[kIndex-1] = arr[i]; /* Since it returns position but we need index (ele-1) */
            arrK[radixEle]--;

        }
        /* we will rarrange the elements of our original array wrt arrSorted */
        for(int i=0; i<n; i++)
        {
            arr[i] = arrSorted[i];
        }
        /* Count Sort for one radix element ends */

        j *=4;
        p++;
    }

    // Now we have arrSorted as our final sorted array, we print and check.
    printArray(arrSorted, n);
}

void solve()
{
    int n;
    cin>>n;
    /* number of array elements */

    int k = 4;
    /* range of each radix element is 0 to 3 in our case, so total 4 possibilities */

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i] > 255)
        cout<<"Please choose a number between [0-255]";
    }

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