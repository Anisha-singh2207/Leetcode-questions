//1394. Find Lucky Integer in an Array
class Solution {
public:
    int findLucky(vector<int>& arr) {
   int i;
int luckyNumber=-1;
   sort(arr.begin(),arr.end());

   for(i=arr.size()-1;i>=0;i--){
       if(arr[i]==count(arr.begin(),arr.end(),arr[i])){
           luckyNumber=arr[i];
           return luckyNumber;
       }
   }
  return luckyNumber;


        
        
    }
};