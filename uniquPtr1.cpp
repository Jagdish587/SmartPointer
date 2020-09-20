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

  auto uniqTasptr2 = move(uniqTaskPtr); // it transfers ownership

  if(uniqTaskPtr != nullptr) {
       std::cout<<"uniqTaskPtr my id = "<<uniqTaskPtr->mId<<endl;
  } else {
      std::cout<<"uniqTaskPtr is null  \n";
  }

  if(uniqTasptr2 != nullptr) {
      std::cout<<"uniqTaskPtr initially is not null  \n";
  } else {
      std::cout<<"uniqTaskPtr is null  \n";
  }

  std::cout<<"uniqTasptr2 my id = "<<uniqTasptr2.get()<<endl;
  Task *nptr = uniqTasptr2.get(); // returns a pointer
  std::cout<<"Task *nptr  = "<<nptr->mId<<endl;

  nptr->mId = 20;

  std::cout<<"uniqTasptr2 my id after change = "<<uniqTasptr2->mId<<endl;

  uniqTasptr2->mId =30;

  std::cout<<"uniqTasptr2 my id 2nd after change = "<<uniqTasptr2->mId<<endl;

  Task *ptr = uniqTasptr2.release(); // releases pointer , destuctor will not be called

  std::cout<<"uniqTasptr2 after release  \n";

  if(uniqTasptr2 != nullptr) {
      std::cout<<"uniqTasptr2 is not null  \n";
  } else {
      std::cout<<"uniqTasptr2 is null  \n";
  }

  cout<<"value of ptr after release = "<<ptr->mId<<endl;

 // cout<<"destructor not called 1.0 \n ";

  auto uniqTaskPtr3 = make_unique<Task>(45);

  uniqTaskPtr3.reset(); // destructor gets called for reset but not for release

  if(uniqTaskPtr3) {
       std::cout<<"uniqTaskPtr3 is not null  \n";
  } else {
       std::cout<<"uniqTaskPtr3 is  null  \n";
  }


  return 0;
}
