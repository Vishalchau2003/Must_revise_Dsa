#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int i, n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements: ";

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    int sum = 0;
    int maxsum = INT_MIN;
    int start = 0;
    int anstart=-1;
    int ansend=-1;

    for (i = 0; i < n; i++)
    {   
        if(sum==0){
          start=i;
        }
        sum += arr[i];
        if (sum > maxsum)
        {
            maxsum = sum;
            anstart=start;
            ansend=i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
        if(maxsum<0){
            maxsum=0;

        }
    }
    for(int i=anstart;i<=ansend;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}