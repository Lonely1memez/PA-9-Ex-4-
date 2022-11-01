#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void selection_sort(int arr[], int size)
{


    for(int i=0;i<size-1;i++)
    {

        int min_index = i;

        for(int j=i+1;j<size;j++)
        {

            if (arr[j] < arr[min_index])
                min_index = j;

        }


        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

    }
}

int main()
{


    int arr_10k[10000],arr_20k[20000],arr_50k[50000];

    for(int i=0;i<10000;i++)
    {
        arr_10k[i] = rand()%10000;
    }


    for(int i=0;i<20000;i++)
    {
        arr_20k[i] = rand()%10000;
    }


    for(int i=0;i<50000;i++)
    {
        arr_50k[i] = rand()%10000;
    }


    auto start = high_resolution_clock::now();

    selection_sort(arr_10k,10000);

    auto end = high_resolution_clock::now();


    auto arr_10k_time = duration_cast<microseconds>(end-start);


    start = high_resolution_clock::now();
    selection_sort(arr_20k,20000);
    end = high_resolution_clock::now();

    auto arr_20k_time = duration_cast<microseconds>(end-start);

    start = high_resolution_clock::now();
    selection_sort(arr_50k,50000);
    end = high_resolution_clock::now();

    auto arr_50k_time = duration_cast<microseconds>(end-start);
    
    cout<<"Time taken to sort array of size 10000: "<<arr_10k_time.count()<<" microseconds"<<endl<<endl;
    
    cout<<"Time taken to sort array of size 20000: "<<arr_20k_time.count()<<" microseconds"<<endl<<endl;

    cout<<"Time taken to sort array of size 50000: "<<arr_50k_time.count()<<" microseconds"<<endl<<endl;

    return 0;
}