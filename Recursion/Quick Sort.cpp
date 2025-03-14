Class Solution{
public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low < high)
        {
            int partitionIdx = partition(arr, low, high);
            quickSort(arr, low, partitionIdx - 1);
            quickSort(arr, partitionIdx + 1, high);
        }
        return;
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int i = low - 1;
        int pivot = arr[high];
        for(int j = low; j < high; j++)
        {
            if(arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
};
