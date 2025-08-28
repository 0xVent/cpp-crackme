#include <iostream>
using namespace std;

int main()
{
    string inputKey = "";

    cout << "Enter your license key: ";
    cin >> inputKey;

    if (inputKey == "7B9K-Z3MP-QT2V-W8N5")
    {
        cout << "Valid license key! Welcome user :)";
    }

    else
    {
        cout << "Invalid license key!";
    }

    cout << "\n\n";
    system("pause");
    return 0;
}