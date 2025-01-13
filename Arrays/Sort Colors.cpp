// Approach - 1 sort using the sort funcion. Approach - 2 : sort using counting the zeroes, ones and two, 
//Approach 3 : Dutch National flag method
class Solution {
public:
    void sortColors(vector<int>& arr) {
       int low = 0, mid = 0, high = arr.size() - 1;

      while(mid <= high)
      {
          if(arr[mid] == 1)
            mid++;
          else if(arr[mid] == 2)
          {
            swap(arr[mid], arr[high--]);
          }
          else
          {
            swap(arr[low], arr[mid]);
            low++; mid++;
          }
      }
    }
}; 
