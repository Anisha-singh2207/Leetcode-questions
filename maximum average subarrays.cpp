//643. Maximum Average Subarray I

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

   //sliding window algorithm
   //VIMP

   //Get sum for starting window
   int sum=0;
   for(int i=0;i<k;i++){
       sum+=nums[i];
       //assume that this sum is max
    
   }
      int maxSum=sum;

   //start sliding window

   int startIndex=0;
   int endIndex=k;
// jab tak last index last index tak na jaye 
   while(endIndex<nums.size()){
       sum-=nums[startIndex]; // remove previous element
       startIndex++;

       sum+=nums[endIndex]; //add previous element
       endIndex++;

       maxSum=max(maxSum,sum); //update the maxSum
   }

//return the average
return (double)maxSum/k;

      



        
    }
};