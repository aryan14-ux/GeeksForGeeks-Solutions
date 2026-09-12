class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here

  int n =arr.size();
        int low =0;
        int high=n-1;

        int ans=n;
        while(low<=high){
           int mid = low + (high - low) / 2;


     if(arr[mid]>target){
         ans=mid;
         high=mid-1;
     }
     else{
         low=mid+1;
     }}
     return ans;
    }
    int blackbox(vector<vector<int>> &mat,int n,int m,int target){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upperBound(mat[i],target);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        
        int n = mat.size();
        int m = mat[0].size();
       int low=INT_MAX;
       int high=INT_MIN;
     
       for(int i=0;i<n;i++){
           low=min(low,mat[i][0]);
           high=max(high,mat[i][m-1]);
       }
       
       int req=(n*m)/2;
       while(low<=high){
           int mid=low+(high-low)/2;
           int count=blackbox(mat,n,m,mid);
           if(count<=req)
           low=mid+1;
           else
           high=mid-1;
           
       }
       return low;
        
    }
};
