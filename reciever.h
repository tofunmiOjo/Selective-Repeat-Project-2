#include <vector>
#include <algorithm>

#ifndef RECIEVER_H
#define RECIEVER_H
using namespace std;


class Reciever {

    public:

    vector<int> inOrder;
    vector<int> holdingValues;
    int lastHoldingValue = holdingValues.size() - 1;

    // Constructor for initalizing both vectors to 0
    Reciever();

    // Will recieve the frames sent by the sender
    // Adds the ones which are in order to inOrder
    // Discards ones that are smaller than the the greatest value in inOrder
    // If such values are greater than in inOrder they are stored in holdingValues
    void recieveSequenceNumbers(int seqNum);


    // Used to send acknowledgements back to the sender so that the slding window can move forward
    int sendAcknowledgment();
    
    // Function to add the other holdingValues in the inOrder if possible
    void addHoldingValues();

    // Returns the holding sequence for the acknowlegdment
    vector<int> returnHoldingSequence();

    // Returns the last in order sequence number for acknowledgment 
    int returnLastAcknowledged();

};

#endif 