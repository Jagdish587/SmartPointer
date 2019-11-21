#include <iostream>
#include <memory>

using namespace std;

struct Task
{
  int mId;
  Task(int id ) :mId(id)
  {
    std::cout<<"Task::Constructor"<<std::endl;
  }
  ~Task()
  {
    std::cout<<"Task::Destructor"<<std::endl;
  }
};

int main()
{
  // Create a unique_ptr object through raw pointer
  std::unique_ptr<Task> taskPtr(new Task(23));

  //Access the element through unique_ptr
  int id = taskPtr->mId;

  std::cout<<id<<std::endl;


  auto uniqTaskPtr = make_unique<Task>(45);

  auto uniqTasptr2 = move(uniqTaskPtr);

  std::cout<<"my id = "<<uniqTasptr2->mId<<endl;

  Task *ptr = uniqTasptr2.release(); // destuctor will not be called

  cout<<"value of ptr = "<<ptr->mId<<endl;

  cout<<"destructor not called 1.0 \n ";

  auto uniqTaskPtr3 = make_unique<Task>(45);

  uniqTaskPtr3.reset(); // destructor gets called for reset but bot for release


  return 0;
}

