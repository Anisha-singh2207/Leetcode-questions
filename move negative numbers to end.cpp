class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        
        int temp[n];
        int count=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                
                temp[count]=arr[i];
                count++;
            }
             
        }
        
            for(int i=0;i<n;i++){
            if(arr[i]<0){
                
                temp[count]=arr[i];
                count++;
            }
             
        }
        
        
        for(int i=0;i<n;i++){
            arr[i]=temp[i];
        }
  
        
      
    }
};
