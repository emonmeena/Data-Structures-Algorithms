/*
Masthead - 
Owner - Master Mayank Meena 
Enroll no. 19114055, O-3
Code Editor - VSCode 2020
Terminal - WSL Ubuntu 2020
Shell - git bash

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

void countSort(int arr[], int n, int k, int p, int ran)
{
    int arrCount[k]={0}; /*Count array with length k */
    int arrSorted[n] = {0};
    int radixEle = 0;

        /* incrementing count of each element */
        for(int m=0; m<n; m++)
        {
            int temp = arr[m];
            int radixEle = (temp&ran) / pow(4, p);
            arrCount[radixEle]++;
        }
        /* taking sum of neibhour counts in counting Array */
        for(int l=1; l<k; l++)
        {
            arrCount[l] += arrCount[l-1];
        }
        for(int i=n-1; i>=0; i--)
        {
            int temp = arr[i];
            int radixEle = (temp&ran) / pow(4, p);
            arrSorted[arrCount[radixEle]-1] = arr[i]; /* Since it returns position but we need index (ele-1) */
            arrCount[radixEle]--;
        }
        /* we will rearrange the elements of our original array wrt arrSorted */
        for(int q=0; q<n; q++)
        {
            arr[q] = arrSorted[q];
        }
        /* Count Sort for one radix element ends */
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

    /*
    Radix Sort begins - 
    we call countSort on our array for all radix elements. */
    for(int i=0; i<4; i++)
    countSort(arr, n, k, i, 3*pow(4, i));
    /* Radix Sort ends */

    printArray(arr, n);
    
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