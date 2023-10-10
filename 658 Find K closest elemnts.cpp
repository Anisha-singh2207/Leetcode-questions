class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start=0;
        int end=arr.size()-k;

        int mid=start+(end-start)/2;

        while(start<end){
            if(x-arr[mid]>arr[mid+k]-x){
                //ans right side mai eist karta hai
               // because  left ka difference jada hai
               //agar difference jada hai toh right mai jao
                start=mid+1;
            }
            else{
                //mid-1 issliye nahi kiya kyuki ho sakta hai mid bhi ans ho
                //aur agar mid-1 karoge toh range se bahar chale jaoge
                end=mid;
            }
            //mid update
            mid=start+(end-start)/2;

        }
        //aur ans mai return karo
        //rane ko
        
       return vector<int>(arr.begin()+start,arr.begin()+start+k);
    }
};