#include "reciever.h"
#include <vector>
using namespace std;


// Clears the vectors                                                                                                                                                                                       
Reciever::Reciever() {
    inOrder.clear();
    holdingValues.clear();
}

// Checks if the vector is empty and if the sequence is 0, if so it adds it                                                                                                                                 
// If it is inorder sequence, it is also added                                                                                                                                                              
// If it is too early of a seqeunce number then it is discarded                                                                                                                                             
// If it is a later sequence number then the value is stored                                                                                                                                                

    void Reciever::recieveSequenceNumbers(int seqNum)
    {
        if (inOrder.size() == 0 && seqNum == 0)
        {
            inOrder.push_back(seqNum);
        } else if (seqNum == inOrder.back() + 1)
        {
            inOrder.push_back(seqNum);
        } else if (seqNum < inOrder.back())
        {
            // Do nothing, discarding because it is earlier in sequence                                                                                                                                     
        } else {
            // Will catch the out of order sequence numbers and sort them in another array                                                                                                                  
            holdingValues.push_back(seqNum);
            sort(holdingValues.begin(), holdingValues.end());
    }
    }


    // This will return an interger of the last sequence recieved by the sender                                                                                                                             
    int Reciever::sendAcknowledgment() {

       int tempValue = inOrder.back();
       return tempValue;
    }


    // This will add the holding values into the inorder, if they are indeed inorder                                                                                                                        
    // Will delete the value from holding values after it is completed                                                                                                                                      
    void Reciever::addHoldingValues() {
        for (int i = 1; i < holdingValues.size() + 1; i++)
        {
            if(holdingValues.size() == 0)
            {

            }
            else if(inOrder.back() + i == holdingValues[i - i])
            {
                inOrder.push_back(holdingValues[i - 1]);
                holdingValues.erase(holdingValues.begin());
            }
        }
    }
  vector<int> Reciever::returnHoldingSequence() {
        return holdingValues;
    }
