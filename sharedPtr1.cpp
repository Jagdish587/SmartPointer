#include <iostream>
#include <memory>

using namespace std;

struct MyInt {
  MyInt(int v):val(v){
    std::cout << "  Hello: " << val << std::endl;
  }
  ~MyInt(){
    std::cout << "  Good Bye: " << val << std::endl;
  }
  int val;
};


int main()
{

  auto sharedPtr = make_shared<MyInt>(45);

  cout<<"stored pointer = "<<sharedPtr.get()<<endl;

  cout<<"no of objects = "<<sharedPtr.use_count()<<endl;

  shared_ptr<MyInt> shrres = sharedPtr;

  cout<<"stored pointer = "<<shrres.get()<<endl;

  cout<<"no of objects = "<<shrres.use_count()<<endl;

  auto sharres2 = sharedPtr ;

  cout<<"stored pointer = "<<sharres2.get()<<endl;

  cout<<"no of objects = "<<sharres2.use_count()<<endl;

  // Now Let's reset the data

  sharres2.reset();
  sharedPtr.reset();

  cout<<"no of objects last = "<<shrres.use_count()<<endl;

  shrres.reset();



  return 0;
}

