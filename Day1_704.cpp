#include<bits/stdc++.h>
using namespace std;
bool binaryS(int arr[], int n, int target)
{
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(arr[mid]==target)
        {
            return true;
        }
        if(arr[mid]>target)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return false;
}
int main()
{
    int arr[7] = {2, 4, 6, 8, 9, 11, 23};
    if(binaryS(arr,7,12))
    {
        cout<<"Element Found!";
    }
    else{
        cout<<"Element Not Found!";
    }
    // With Header File we use binarysearch
    cout<<binary_search(arr, arr+7, 25);
}
