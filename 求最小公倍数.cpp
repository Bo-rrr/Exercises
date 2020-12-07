#include <iostream>
using namespace std;

int MinY(int a, int b)
{
   int min, max;
    max = a > b ? a : b;
    min = a < b ? a : b;
    if(max % min == 0)
        return max;
    while(max % min != 0)
    {
        int r = max % min;
        max = min;
        min = r;
    }
    return a * b / min;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << MinY(a, b) << endl;
    return 0;
}