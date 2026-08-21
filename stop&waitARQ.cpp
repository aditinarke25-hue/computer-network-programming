#include <iostream> 
#include <thread> 
#include <chrono> 
#include <vector> 
 
using namespace std; 
 
void startTimer(int seconds) 
{ 
    for (int i = seconds; i >= 1; i--) 
    { 
        cout << "Timer: " << i << " seconds remaining..." << endl; 
        this_thread::sleep_for(chrono::seconds(1)); 
    } 
} 
 
int main() 
{ 
    int n, timeout, lostFrame; 
 
    cout << "Stop and Wait ARQ" << endl; 
    cout << endl; 
 
    cout << "Enter number of frames: "; 
    cin >> n; 
 
    vector<int> frames(n); 
 
    cout << "Enter frame numbers : "; 
    for (int i = 0; i < n; i++) 
    { 
        cin >> frames[i]; 
    } 
 
    cout << endl; 
 
    cout << "Enter timeout value (seconds): "; 
    cin >> timeout; 
 
    cout << endl; 
 
    cout << "Enter frame number to simulate as lost (0 for no loss): "; 
    cin >> lostFrame; 
 
    cout << endl; 
 
    for (int i = 0; i < n; i++) 
    { 
        int frame = frames[i]; 
 
        cout << "Sending Frame " << frame << "..." << endl; 
 
        // Simulate frame loss 
        if (frame == lostFrame) 
        { 
            cout << "Frame " << frame << " lost!" << endl; 
 
            cout << "Starting Timer..." << endl; 
            startTimer(timeout); 
 
            cout << "Timeout occurred." << endl; 
 
            cout << "Retransmitting Frame " << frame << "..." << endl; 
 
            cout << "Frame " << frame 
                 << " received successfully." << endl; 
 
            cout << "Acknowledgement " << frame << " received." << endl; 
        } 
        else 
        { 
            cout << "Starting Timer..." << endl; 
            startTimer(timeout); 
 
            cout << "Frame " << frame 
                 << " received successfully." << endl; 
 
            cout << "Acknowledgement " << frame << " received." << endl; 
        } 
 
        cout << endl; 
    } 
 
    cout << "Transmission completed successfully." << endl; 
 
    return 0; 
}

/*Output
Stop and Wait ARQ

Enter number of frames: 7
Enter frame numbers : 1 2 3 4 5 6 7

Enter timeout value (seconds): 5

Enter frame number to simulate as lost (0 for no loss): 3

Sending Frame 1...
Starting Timer...
Timer: 5 seconds remaining...
Timer: 4 seconds remaining...
Timer: 3 seconds remaining...
Timer: 2 seconds remaining...
Timer: 1 seconds remaining...
Frame 1 received successfully.
Acknowledgement 1 received.

Sending Frame 2...
Starting Timer...
Timer: 5 seconds remaining...
Timer: 4 seconds remaining...
Timer: 3 seconds remaining...
Timer: 2 seconds remaining...
Timer: 1 seconds remaining...
Frame 2 received successfully.
Acknowledgement 2 received.

Sending Frame 3...
Frame 3 lost!
Starting Timer...
Timer: 5 seconds remaining...
Timer: 4 seconds remaining...
Timer: 3 seconds remaining...
Timer: 2 seconds remaining...
Timer: 1 seconds remaining...
Timeout occurred.
Retransmitting Frame 3...
Frame 3 received successfully.
Acknowledgement 3 received.

Sending Frame 4...
Starting Timer...
Timer: 5 seconds remaining...
Timer: 4 seconds remaining...
Timer: 3 seconds remaining...
Timer: 2 seconds remaining...
Timer: 1 seconds remaining...
Frame 4 received successfully.
Acknowledgement 4 received.

Sending Frame 5...
Starting Timer...
Timer: 5 seconds remaining...
Timer: 4 seconds remaining...
Timer: 3 seconds remaining...
Timer: 2 seconds remaining...
Timer: 1 seconds remaining...
Frame 5 received successfully.
Acknowledgement 5 received.

Sending Frame 6...
Starting Timer...
Timer: 5 seconds remaining...
Timer: 4 seconds remaining...
Timer: 3 seconds remaining...
Timer: 2 seconds remaining...
Timer: 1 seconds remaining...
Frame 6 received successfully.
Acknowledgement 6 received.

Sending Frame 7...
Starting Timer...
Timer: 5 seconds remaining...
Timer: 4 seconds remaining...
Timer: 3 seconds remaining...
Timer: 2 seconds remaining...
Timer: 1 seconds remaining...
Frame 7 received successfully.
Acknowledgement 7 received.
Transmission completed successfully.*/
