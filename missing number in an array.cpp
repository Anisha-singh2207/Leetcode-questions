// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        
        
        int sum=0;
        
        for(int i=0;i<array.size();i++){
            
            sum=sum+array[i];
        }
        
        int totalSum=((n)*(n+1))/2;
        
        int ans=totalSum-sum;
        
        return ans;
    }
};

