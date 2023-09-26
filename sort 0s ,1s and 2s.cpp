class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        
             int l = 0, e = n - 1, i = 0;
        while(i <= e) {
            if(a[i] == 0) {
                swap(a[i++], a[l++]);
            } else if(a[i] == 2) {
                swap(a[i], a[e--]);
            } else {
                i++;
            }
        }
    }
    
};
