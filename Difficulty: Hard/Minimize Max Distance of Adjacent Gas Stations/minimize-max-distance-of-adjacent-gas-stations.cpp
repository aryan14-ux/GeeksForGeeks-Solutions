class Solution {
  public:
  int numberofGasStationRequired(double dist,vector<int>&arr){
      int cnt=0;
      for(int i=1;i<arr.size();i++){
          int numberInbetween =(arr[i]-arr[i-1])/dist;
          if((arr[i]-arr[i-1])==numberInbetween*dist){
            numberInbetween--;  
          }
          cnt+=numberInbetween;
      }
      return cnt;
  }
  
    double minMaxDist(vector<int> &arr, int k) {
        int n=arr.size();
        double low=0;
        double high=0;
        for(int i=0;i<n-1;i++){
            high=max(high,(double)(arr[i+1]-arr[i]));
        }
        double diff=1e-6;
        while(high-low>diff){
            double mid=low+(high-low)/2;
            int cnt=numberofGasStationRequired(mid,arr);
            if(cnt>k){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        return high;
        
    }
};