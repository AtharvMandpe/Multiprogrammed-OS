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
    vector<int> requests(n);
    vector<int> seq(n);
    vector<int> st(n);

    //take DISK SIZE
    cout << "\nEnter disk size : ";
    int diskSize;
    cin >> diskSize;

    cout << endl;

    //take requests array as input
    for(int i=0;i<n;i++){
        cout << "Enter request " << i+1 << " : ";
        cin >> requests[i];
        cout << endl;
    }

    sort(requests.begin(), requests.end());

    //take initial head ip
    cout << "Enter initial head position : ";
    int initialhead;
    cin>>initialhead;

    cout << endl;

    //scan algo ( considering direct left. )
    int seqptr = 0;
    int sptr = 0;

    for(int i=0;i<n;i++){
        if(requests[i] >= initialhead){
            seq[seqptr++] = requests[i];
            st[sptr++] = requests[i] - initialhead;
        }
    }

    int newptr = 0;

    while(requests[newptr] < initialhead) newptr++;

    for(int i = newptr-1; i >= 0; i--){

        seq[seqptr++] = requests[i];
        st[sptr++] = 2*(diskSize - initialhead) + (initialhead - requests[i]);

    }

    cout << "seq : ";
    for(int i=0;i<n;i++){
        cout << seq[i] << " ";
    }
    cout << endl;

    cout << "st : ";
    for(int i=0;i<n;i++){
        cout << st[i] << " ";
    }
    cout << endl;
    return 0;
}
