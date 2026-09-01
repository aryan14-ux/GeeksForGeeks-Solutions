class Solution {
  public:
  bool isPossible(vector<int>& arr, int k, long long maxPages) {
      int students = 1;
      long long pages = 0;

      for (int i = 0; i < arr.size(); i++) {

          if (pages + arr[i] <= maxPages) {
              pages += arr[i];
          }
          else {
              students++;
              pages = arr[i];

              if (students > k)
                  return false;
          }
      }

      return true;
  }
    int minTime(vector<int>& arr, int k) {
       int n = arr.size();

       if (k > n)
           return -1;

       long long low = *max_element(arr.begin(), arr.end());

       long long high = 0;
       for (int x : arr)
           high += x;

       long long ans = high;

       while (low <= high) {

           long long mid = low + (high - low) / 2;

           if (isPossible(arr, k, mid)) {
               ans = mid;
               high = mid - 1;
           }
           else {
               low = mid + 1;
           }
       }

       return (int)ans;
        
    }
};