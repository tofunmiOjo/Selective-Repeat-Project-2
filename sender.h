// Some functions and variables have not been used, we have declared the used ones in the documentation                                                                                                     
// There are also no comments because they are stated in the documentation                                                                                                                                  

#include<vector>
#include<math.h>
#include <algorithm>

#ifndef SENDER_H_
#define SENDER_H_
using namespace std;

class Sender{

public:
    vector <int> curSeqNum;
    vector <int> totalFrames;
    vector <int> sendingWindow;
    int windowSz;
    int lastElement = windowSz -1;
    int seqNrAck = 0;

  vector<int> curWindow;
  int seqNrDel = -1;


    Sender();

    void setWindowSize(int size);

    void setTotalWindows(int numFrames);

    void retransmitFrames(int seqNum);

    vector<int> getTotalWindow();

    vector<int> getcurWindow();

    vector<int> getCurSeqNum();

    vector<int> sendFrames();

    void moveWindow(int s);

    int canDeliver();

    int deliver();

    void recieveData(int randomData);

    int seqToAck();
};

#endif

