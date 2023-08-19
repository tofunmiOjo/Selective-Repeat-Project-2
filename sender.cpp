#include "sender.h"

    Sender::Sender() {
    curSeqNum.clear();
    totalFrames.clear();
    curWindow.clear();
    sendingWindow.clear();
    int windowSz = 0;
    int seqNrDel = 0;
    int seqNrAck = 0;
    }

int Sender::canDeliver(){


      if(curWindow.empty()){
            return -1;
        }

      else {

        for(int i = 0; i <curWindow.size(); i++){

          seqNrDel =curWindow[i];

        }
        return seqNrDel;
    }
    }

    int Sender::deliver(){


        if(curWindow.empty()){
            return -1;
        }

        else{
            return curWindow.back();
            curWindow.pop_back();
        }
    }

     int Sender::seqToAck(){
        return seqNrAck;
    }



    void Sender::recieveData(int randomData) {

  for (int i = 0; i < curWindow.size(); i++)
    {
        if(curWindow.size() == 0 && randomData == 0)
        {
            curWindow.push_back(randomData);
        } else if (randomData == curWindow.back() + 1)
        {
            curWindow.push_back(randomData);
        }
    }
}

void  Sender::moveWindow(int s){


for(int i = 0; i < curWindow.size(); i++){
if(curWindow[i] == s){
    for(int j = i; j= 0; j--){
      curWindow.erase(curWindow.begin() + i);;
    }
}


   }
}
