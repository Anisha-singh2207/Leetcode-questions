//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    //step 1
	 int j=0;
	   
	  for(int i=0;i<n;i++){
	      
	      if(arr[i]!=0){
	          
	          swap(arr[j],arr[i]);
	          
	          j++;
	      }
	  }
	}
};

