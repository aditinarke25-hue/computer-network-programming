//sender Side C++ Program
#include <iostream>
#include <string>
using namespace std;

string xorDivision(string data, string divisor)
{
    int n = divisor.length();

    for (int i = 0; i <= data.length() - n; i++)
    {
        if (data[i] == '1')
        {
            for (int j = 0; j < n; j++)
            {
                data[i + j] =
                    (data[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    return data.substr(data.length() - (n - 1));
}

int main()
{
    string data, divisor;

    // Input
    cout << "Enter Data Word: ";
    cin >> data;

    cout << "Enter Divisor: ";
    cin >> divisor;

    // Find length of divisor
    int n = divisor.length();

    cout << "Length of Divisor: " << n << endl;

    // Number of zeros = divisor length - 1
    int zeros = n - 1;

    // Add zeros to data word
    string modifiedData = data + string(zeros, '0');

    cout << "\nData Word: " << data;
    cout << "\nDivisor: " << divisor;

    cout << "\nCode Word after adding "
         << zeros << " zeros: "
         << modifiedData << endl;

    // XOR division
    string remainder = xorDivision(modifiedData, divisor);

    cout << "\nRemainder after XOR operation: "
         << remainder << endl;

    // Replace extra zeros with remainder
    string codeword = data + remainder;

    cout << "Final Code Word: "
         << codeword << endl;

    return 0;
}
/*Enter Data Word: 1001
Enter Divisor: 1011
Length of Divisor: 4

Data Word: 1001
Divisor: 1011
Code Word after adding 3 zeros: 1001000

Remainder after XOR operation: 110
Final Code Word: 1001110*/
