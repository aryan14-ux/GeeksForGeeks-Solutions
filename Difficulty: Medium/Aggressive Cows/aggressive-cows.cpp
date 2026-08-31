class Solution {
  public:
  bool canWePlace(vector<int>&arr,int dist,int cows){
       int cnt=1,last = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last>=dist){
                cnt++;
                last=arr[i];
            }
            if(cnt>=cows) return true;
            
        }
        return false;
  }
    int aggressiveCows(vector<int> &arr, int k) {
      sort(arr.begin(),arr.end());
      int n=arr.size();
      int low=1,high=arr[n-1]-arr[0];
      while(low<=high){
          int mid=low+(high-low)/2;
          if(canWePlace(arr,mid,k)==true){
              low=mid+1;
          }
          else{
              high=mid-1;
          }
      }
      return high;
        
    }
};