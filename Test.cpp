/* Kenneth Bradburn
*  Nov 22 2019
*  Test.cpp
*/

#include "Test.h"
#include "Queue.h"
#include "Node.h"
#include "QueueInterface.h"
#include <iostream>

using namespace std;

void Test::run()
{
  Queue* a = new Queue;

  //adding try catch to top after I was told it was here.
  cout << "Try catch Test #1: Peekfront throws error if the queue is already empty: ";
  try
  {
    a -> peekFront();
  }
  catch(...) //https://en.cppreference.com/w/cpp/language/try_catch use ... in case of anything
  {
    cout << " Yes\n\n";
  }

  cout << "Try Catch Test #2: Trying to Dequeue and empty queue throws an error: ";
  try
  {
    a -> dequeue();
  }
  catch(...)
  {
    cout << " Yes\n\n";
  }

  //test 1 A new queue is empty
  cout << "Test #3: Is the newly created queue empty?:";
  if(a -> isEmpty()) //interface
  {
    cout << " Yes\n\n";
  }
  else
  {
    cout << " No\n\n";
  }
  a -> enqueue(5);
  cout << "The number 5 should now be in queue\nTest #4: Is the first value in the Queue 5: ";
  if(a -> peekFront() == 5)
  {
    cout << " Yes\n\n";
  }
  else
  {
    cout << " No\n\n";
  }
  cout << "Test #5: Preforming a dequeue:";
  try
  {
    a -> dequeue();
  }
  catch(...)
  {
    cout << " failed\n\n";
  }
  cout << " Passed\n\n";
  cout << "Test #6: Queueing in two numbers 2 & 3, 2 goes in first then 3 follows it. Peeking the front of the queue, is it 2?: ";
  a -> enqueue(2);
  a -> enqueue(3);
  if(a -> peekFront() == 2)
  {
    cout << "Yes\n\n";
  }
  else
  {
    cout << " Failed actually saw " << a -> peekFront() << "\n\n";
  }
  cout << "Test #7: Dequeueing one value, should be 2, now when using Peekfront Method it should return 3: ";
  a -> dequeue();
  if(a -> peekFront() == 3)
  {
    cout << " Passed\n\n";
  }
  else
  {
    cout << " Failed actually saw " << a -> peekFront() << "\n\n";
  }
  cout << "Test #8: Enqueueing 8 to the Queue and peeking front, should be 3: ";
  a -> enqueue(8);
  if(a -> peekFront() == 3)
  {
    cout << " Passed\n\n";
  }
  else
  {
    cout << " Failed actually saw " << a -> peekFront() << "\n\n";
  }
a -> enqueue(3);
delete a;
cout << "Test #9: Valgrid Test: There are memory leaks when using the deconstructor so the Deconstructor is not working. \n\n";
}
