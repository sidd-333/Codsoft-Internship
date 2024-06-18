#include <iostream>
using namespace std;
int main()
{
    float n1, n2;
    char operation;

    cout << "Enter the values for two numbers:" << endl;
    cin >> n1 >> n2;

    cout << "Enter the opeartion you want to perform:";
    cin >> operation;

    switch (operation)
    {
    case '+':
        cout << "Sum of " << n1 << " and " << n2 << " is:" << n1 + n2 << endl;
        break;
    case '-':
        cout << "Subtraction of " << n2 << " from " << n1 << " is:" << n1 - n2 << endl;
        break;
    case '*':
        cout << "Multiplication of " << n1 << " and " << n2 << " is:" << n1 * n2 << endl;
        break;
    case '/':
        cout << "Division of " << n1 << " by " << n2 << " is:" << n1 / n2 << endl;
        break;
    default:
        cout << "Error! Enter the correct operation" << endl;
    }

    return 0;
}