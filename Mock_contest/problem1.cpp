#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> book_list;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int book_id;
        cin >> book_id;
        book_list.push_back(book_id);
    }

    int target;
    cin >> target;
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        if (book_list[i] == target)
        {
            result = i;
            break;
        }
    }
    cout << result << endl;
    return 0;
}