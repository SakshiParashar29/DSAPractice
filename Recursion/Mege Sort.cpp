// TC : O(n log n) && SC : O(n)
class Solution {
  public:
    void merge(vector<int>& arr, int l, int mid, int r)
    {
        int left = l;
        int right = mid + 1;
        int idx = l;
        vector<int> temp;
        while(left <= mid && right <= r)
        {
            if(arr[left] <= arr[right])
              temp.push_back(arr[left++]);
            if(arr[right] < arr[left])
              temp.push_back(arr[right++]);
        }
        while(left <= mid)
        {
            temp.push_back(arr[left++]);
        }
        while(right <= r)
        {
            temp.push_back(arr[right++]);
        }
        for(int i = l; i <= r; i++)
        {
            arr[i] = temp[i - l];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l == r)
        {
            return;
        }
           int mid = l + (r - l)/2;
           mergeSort(arr, l, mid);
           mergeSort(arr, mid + 1, r);
           merge(arr, l, mid, r);
    }
};
