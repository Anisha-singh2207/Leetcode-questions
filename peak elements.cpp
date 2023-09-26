class Solution
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       
       int s=0;
       int e=n-1;
       int mid=s+(e-s)/2;
       
       while(s<e){
           if(arr[mid]<arr[mid+1]){
               //A wali phase mai hu aur mere se aage bade value hai
               //peak element ho sakta hai mere aage ho toh 
               s=mid+1;
               
               
           }
           else{
               //ya mai B line par hu
               //ya toh mai peeak element par hu
               e=mid;
           }
           
           mid=s+(e-s)/2;
       }
       return s;
       
    }
};
