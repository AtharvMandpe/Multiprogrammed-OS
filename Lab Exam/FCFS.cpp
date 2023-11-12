#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){

    //take no of requests
    cout << "No of requests : ";
    int n;
    cin>>n;
    int requests[50];

    cout << endl;

    //take requests array as input
    for(int i=0;i<n;i++){
        cout << "Enter request " << i+1 << " : ";
        cin >> requests[i];
        cout << endl;
    }


    //take initial head ip
    cout << "Enter initial head position : ";
    int initialhead;
    cin>>initialhead;

    cout << endl;

    //FCFS algo
    int totalMovement = 0;
    int currTrack = initialhead;

    for(int i=0;i<n;i++){

        totalMovement += abs(currTrack - requests[i]);

        currTrack = requests[i];
    }

    cout << "Total Head Movement : " << totalMovement << endl;

    return 0;
}
