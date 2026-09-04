#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string ip;
    string part;

    int byte[4];
    int count = 0;
    int dots = 0;

    bool valid = true;
    string reason;

    cout << "Enter IPv4 address: ";
    cin >> ip;

    stringstream ss(ip);

    while (getline(ss, part, '.'))
    {
        dots++;

        // CASE 1: Check empty byte
        if (part.empty())
        {
            valid = false;
            reason = "Empty byte found in the address.";
            break;
        }

        // CASE 4: Check fully dotted decimal
        for (char c : part)
        {
            if (c < '0' || c > '9')
            {
                valid = false;
                reason = "Address is not fully dotted decimal.";
                break;
            }
        }

        if (!valid)
            break;

        // CASE 5: Check leading zero
        if (part.length() > 1 && part[0] == '0')
        {
            valid = false;
            reason = "Byte " + part + " contains a leading zero.";
            break;
        }

        int value = stoi(part);

        // CASE 3: Check byte range
        if (value < 0 || value > 255)
        {
            valid = false;
            reason = "Byte " + part +
                     " is not between 0 and 255.";
            break;
        }

        if (count < 4)
            byte[count] = value;

        count++;
    }

    // CASE 1: Check four bytes
    if (valid && count != 4)
    {
        valid = false;
        reason = "Address must contain exactly 4 bytes.";
    }

    // CASE 2: Check three dots
    if (valid && dots != 4)
    {
        valid = false;
        reason = "Address must contain exactly 3 dots.";
    }

    cout << endl;

    // Display validity
    if (!valid)
    {
        cout << "Address : " << ip << endl;
        cout << "Status  : INVALID" << endl;
        cout << "Reason  : " << reason << endl;

        return 0;
    }

    cout << "Address : " << ip << endl;
    cout << "Status  : VALID" << endl;

    // Store only first byte
    int firstByte = byte[0];

    char ipClass;
    string defaultMask;

    int networkBytes;
    int hostBytes;

    // Determine class
    if (firstByte >= 1 && firstByte <= 126)
    {
        ipClass = 'A';
        defaultMask = "255.0.0.0";
        networkBytes = 1;
        hostBytes = 3;
    }
    else if (firstByte >= 128 && firstByte <= 191)
    {
        ipClass = 'B';
        defaultMask = "255.255.0.0";
        networkBytes = 2;
        hostBytes = 2;
    }
    else if (firstByte >= 192 && firstByte <= 223)
    {
        ipClass = 'C';
        defaultMask = "255.255.255.0";
        networkBytes = 3;
        hostBytes = 1;
    }
    else if (firstByte >= 224 && firstByte <= 239)
    {
        ipClass = 'D';
        defaultMask = "Not Applicable";
        networkBytes = 0;
        hostBytes = 0;
    }
    else
    {
        ipClass = 'E';
        defaultMask = "Not Applicable";
        networkBytes = 0;
        hostBytes = 0;
    }

    cout << endl;

    // Class information
    cout << "First Byte   : " << firstByte << endl;
    cout << "Class        : " << ipClass << endl;
    cout << "Default Mask : " << defaultMask << endl;

    cout << endl;

    // Network ID and Host ID
    if (ipClass == 'A' ||
        ipClass == 'B' ||
        ipClass == 'C')
    {
        cout << "Network ID Bytes : "
             << networkBytes << endl;

        cout << "Network ID       : ";

        for (int i = 0; i < 4; i++)
        {
            if (i < networkBytes)
                cout << byte[i];
            else
                cout << "0";

            if (i < 3)
                cout << ".";
        }

        cout << endl;

        cout << endl;

        cout << "Host ID Bytes    : "
             << hostBytes << endl;

        cout << "Host ID          : ";

        for (int i = 0; i < 4; i++)
        {
            if (i < networkBytes)
                cout << "0";
            else
                cout << byte[i];

            if (i < 3)
                cout << ".";
        }

        cout << endl;
    }
    else
    {
        cout << "Network ID Bytes : Not Applicable" << endl;
        cout << "Network ID       : Not Applicable" << endl;

        cout << endl;

        cout << "Host ID Bytes    : Not Applicable" << endl;
        cout << "Host ID          : Not Applicable" << endl;
    }

    return 0;
}
/*OUTPUT


Enter IPv4 address: 192.168.3.11

Address : 192.168.3.11
Status  : VALID

First Byte   : 192
Class        : C
Default Mask : 255.255.255.0

Network ID Bytes : 3
Network ID       : 192.168.3.0

Host ID Bytes    : 1
Host ID          : 0.0.0.11

"Checking validity"
1.wrong no of bytes
Enter IPv4 address: 192.168.10

Address : 192.168.10
Status  : INVALID
Reason  : Address must contain exactly 4 bytes.

2.wrong no of dots
Enter IPv4 address: 192.168.10.25.5


Address : 192.168.10.25.5
Status  : INVALID
Reason  : Address must contain exactly 4 bytes.

3.Byte greater than 255
 
Enter IPv4 address: 192.168.300.25

Address : 192.168.300.25
Status  : INVALID
Reason  : Byte 300 is not between 0 and 255.

4.Binary/mixed representation
Enter IPv4 address: 192.168.10.101010


Address : 192.168.10.101010
Status  : INVALID
Reason  : Byte 101010 is not between 0 and 255.

5. Leading zero
Enter IPv4 address: 192.168.010.25

Address : 192.168.010.25
Status  : INVALID
Reason  : Byte 010 contains a leading zero.

*/