//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    
	    vector<int>pos,neg;
	    //separate positive and neative numbers
	    
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0){
	            pos.push_back(arr[i]);
	        }
	        else{
	            neg.push_back(arr[i]);
	        }
	    }
	    int i=0,j=0,k=0;
	    //neg=-1,-2,-3
	    //pos=1
	    while(i<pos.size() && j<neg.size()){
	        arr[k++]=pos[i++];
	        arr[k++]=neg[j++];
	    }
	    
	    //if there is any positive and neative elements left in the array
	    
	    
	    while(i<pos.size()){
	        arr[k++]=pos[i++];
	    }
	    
	    
	    while(j<neg.size()){
	        
	        arr[k++]=neg[j++];
	    }
	}
};
