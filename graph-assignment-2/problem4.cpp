
#include <iostream>
#include <vector>
using namespace std;

void getTwoLargest(vector<int> &arr)
{
    int n = arr.size();

    int largest = -1, secondLargest = -1;
    int largest_index = -1, secondLargestIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            largest_index = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
            secondLargestIndex = i;
        }
    }

    if (largest_index > secondLargestIndex)
    {
        int temp = largest_index;
        largest_index = secondLargestIndex;
        secondLargestIndex = temp;
    }

    cout << largest_index << " " << secondLargestIndex << endl;
}

int main()
{
    int test_case, N;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        vector<int> arr;
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        getTwoLargest(arr);
    }

    return 0;
}