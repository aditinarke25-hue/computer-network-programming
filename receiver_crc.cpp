//CRC – Receiver Side C++ Program
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
    string codeword, divisor;

    // Input
    cout << "Enter Received Code Word: ";
    cin >> codeword;

    cout << "Enter Divisor: ";
    cin >> divisor;

    // Find length of divisor
    int n = divisor.length();

    cout << "Length of Divisor: " << n << endl;

    // Perform XOR division
    string remainder = xorDivision(codeword, divisor);

    cout << "\nReceived Code Word: " << codeword;
    cout << "\nDivisor: " << divisor;

    cout << "\nRemainder after XOR operation: "
         << remainder << endl;

    // Check remainder
    bool noError = true;

    for (char bit : remainder)
    {
        if (bit == '1')
        {
            noError = false;
            break;
        }
    }

    if (noError)
    {
        cout << "No Error Detected" << endl;
    }
    else
    {
        cout << "Error Detected" << endl;
    }

    return 0;
}




/*Enter Received Code Word: 11010110111110
Enter Divisor: 10011
Length of Divisor: 5

Received Code Word: 11010110111110
Divisor: 10011
Remainder after XOR operation: 0000
No Error Detected*/

/*Enter Received Code Word: 1001
Enter Divisor: 1011
Length of Divisor: 4

Received Code Word: 1001
Divisor: 1011
Remainder after XOR operation: 010
Error Detected*/



