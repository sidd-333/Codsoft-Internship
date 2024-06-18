#include <iostream>
using namespace std;
int main()
{
    int n, n1;

    cout << "Enter the value of n:" << endl;
    cin >> n;
    cout << "The Random no. is in between " << 1 << " to " << n - 1 << endl;

    int a = rand() % n;
    while (n1 != a)
    {
        cout << "Enter your guessed no.:" << endl;
        cin >> n1;
        
        if (n1 < a)
        {
            cout << "Too low! Try again." << endl;
        }
        else if (n1 > a)
        {
            cout << "Too high! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the correct number." << endl;
        }
    }
    return 0;
}