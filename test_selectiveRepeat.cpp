#include "sender.h"
#include "reciever.h"
#include "gtest/gtest.h"


//Do not know if this is needed or not                                                                                                                                                                      
 class TestSelectiveRepeat : public testing::Test {
 protected:

   Sender *s;
   Reciever *r;


  void SetUp() override {
    s = new Sender;
    r = new Reciever;
  }

  void TearDown() override {
    delete s;
    delete r;
  }

 };


// Testing the reciever methods                                                                                                                                                                             
// Will make sure the reciever is sending the correct acknowledgements                                                                                                                                      
// Expecting to return the last inOrder Sequence                                                                                                                                                            
// Test will be in order                                                                                                                                                                                    
TEST_F(TestSelectiveRepeat, sendAckInOrder) {

   r->recieveSequenceNumbers(0);
   r->recieveSequenceNumbers(1);
   r-> recieveSequenceNumbers(2);
   r-> recieveSequenceNumbers(3);
    EXPECT_TRUE(r->sendAcknowledgment() == 3);
}

// Tesing function to deal with out of order without merging the holding array                                                                                                                              
TEST_F(TestSelectiveRepeat, sendAckOutOfOrder) {

   r->recieveSequenceNumbers(0);
   r->recieveSequenceNumbers(1);
   r->recieveSequenceNumbers(3);
   r->recieveSequenceNumbers(2);
    EXPECT_TRUE(r->sendAcknowledgment() == 2);
}

// Tesing function to deal with out of order with merging the holding array                                                                                                                                 
TEST_F(TestSelectiveRepeat, sendAckOutOfOrderAgain) {

   r->recieveSequenceNumbers(0);
   r->recieveSequenceNumbers(1);
   r->recieveSequenceNumbers(3);
   r->recieveSequenceNumbers(2);
   r->addHoldingValues();
    EXPECT_TRUE(r->sendAcknowledgment() == 3);
}
// Testing function to make sure correct holding sequence is being returned                                                                                                                                 
// The holding sequence is for out of order values which are being stored                                                                                                                                   

TEST_F(TestSelectiveRepeat, returnHoldingSequence) {
   r->recieverSequenceNumbers(0);
   r->recieveSequenceNumbers(1);
   r->recieveSequenceNumbers(2);
   r->recieveSequenceNumbers(3);
   r->recieveSequenceNumbers(2);
   testVector.push_back(3);
    EXPECT_TRUE(r->returnHoldingSequence() == testVector);
}


// Testing multiple acknowledgments being sent                                                                                                                                                              
TEST_F(TestSelectiveRepeat, returnManyAck) {

   r->recieveSequenceNumbers(0);
   r->recieveSequenceNumbers(3);
   EXPECT_EQ(r->sendAcknowledgment(), 0);
   r->recieveSequenceNumbers(2);
    EXPECT_EQ(r->sendAcknowledgment(), 0);
   r-> recieveSequenceNumbers(3);
    EXPECT_EQ(r->sendAcknowledgment(), 0);
   r->recieveSequenceNumbers(2);
   EXPECT_EQ(r->sendAcknowledgment(), 0);
}


// Testing for sender                                                                                                                                                                                       
// Testing what sequenceNumber the sender can send                                                                                                                                                          
// This one will be not empty                                                                                                                                                                               
 TEST_F(TestSelectiveRepeat, notEmpty1){
      s->recieveData(0);
      EXPECT_EQ(s->canDeliver(), -1);
 }


// Testing to make sure sender knows it can not send anything if the sliding window is empty                                                                                                                
// Sliding window is empty                                                                                                                                                                                  
TEST_F(TestSelectiveRepeat, empty){

    // Constructor to initalize the sliding window to 0                                                                                                                                                     

    EXPECT_EQ(s->canDeliver(), -1);
 }

// Testing to see what happens will the sender recievers an out of order acknowledgment                                                                                                                     
// *** what is point of this one?                                                                                                                                                                           
TEST_F(TestSelectiveRepeat, outOfOrder1){
    s->recieveData(2);
     EXPECT_EQ(s->canDeliver(), -1);
 }

 TEST_F(TestSelectiveRepeat, outOfOrder2){
    s->recieveData(2);
     EXPECT_EQ(s->canDeliver(), -1);
    s-> recieveData(0);
     EXPECT_EQ(s->canDeliver(), -1);
 }
 TEST_F(TestSelectiveRepeat, inorder){
    s->recieveData(0);
    s->recieveData(1);
    s->recieveData(2);
     EXPECT_EQ(s->canDeliver(), -1);
}

TEST_F(TestSelectiveRepeat, empty1){
    EXPECT_EQ(s->deliver(), -1);
}

TEST_F(TestSelectiveRepeat, notEmpty){
   s->recieveData(0);
   s->recieveData(1);
  EXPECT_EQ(s->deliver(), -1);
}

TEST_F(TestSelectiveRepeat, notEmptyRecieve){
   s->recieveData(0);
   s->deliver();
    EXPECT_EQ(s->seqToAck(), 0);
}

TEST_F(TestSelectiveRepeat, empty2){
    EXPECT_EQ(s->seqToAck(), 0);
}
 
TEST_F(TestSelectiveRepeat, notEmptynonRecieve){
   s->recieveData(0);
    EXPECT_EQ(s->seqToAck(), 0);
}


TEST_F(TestSelectiveRepeat, testingMove) {

}
