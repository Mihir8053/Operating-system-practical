#include <iostream>

using namespace std;

int main()
{
    int blockSize[10], pageSize[10], blockNumber, pageNumber, flags[10], allocation[10], i, j;

    for (i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }
    cout << "Enter no. of blocks: ";
    cin >> blockNumber;
    cout << "\nEnter size of each block: ";
    for (i = 0; i < blockNumber; i++)
        cin >> blockSize[i];

    cout << "\nEnter no. of processes: ";
    cin >> pageNumber;
    cout << "\nEnter size of each process: ";
    for (i = 0; i < pageNumber; i++)
        cin >> pageSize[i];
    for (i = 0; i < pageNumber; i++)
        for (j = 0; j < blockNumber; j++)
            if (flags[j] == 0 && blockSize[j] >= pageSize[i])
            {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }
    // display allocation details
    cout << "\nBlock no.\tsize\t\tprocess no.\t\tsize";
    for (i = 0; i < blockNumber; i++)
    {
        cout << "\n"
             << i + 1 << "\t\t" << blockSize[i] << "\t\t";
        if (flags[i] == 1)
            cout << allocation[i] + 1 << "\t\t\t" << pageSize[allocation[i]];
        else
            cout << "Not allocated";
    }
    return 0;
}