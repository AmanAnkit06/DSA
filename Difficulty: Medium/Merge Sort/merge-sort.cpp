class Solution
{
public:
    void merge(vector<int> &arr, int low, int mid, int high)
    {

        int n1 = mid - low + 1;
        int n2 = high - mid;

        
        vector<int> L(n1), R(n2);

        
        for (int i = 0; i < n1; i++)
            L[i] = arr[low + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0;
        int k = low;

        
        
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int> &arr, int l, int r)
    {
        
        if(l>=r){
            return ;
        }
        int mid = l+(r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
};