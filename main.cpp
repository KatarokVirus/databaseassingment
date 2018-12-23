#include <iostream>
#include "records.h"
#include "BF.h"


int main(void)
{
  std::cout<<"Program Start"<<std::endl;
  // hi yo
  // hello there 
  // General Kenobi
  Record test{15,"Giorgos","Dimopoulos","Ioannina"};
  std::cout<<"Test's id: "<<test.id<<", Test's name: "<<test.name<<", Test's surname:"<<test.surname<<", Test's address:"<<test.address<<std::endl;
  return 0;
}
