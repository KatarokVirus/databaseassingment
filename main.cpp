#include <iostream>
//#include "records.h"
#include "BF.h"
#include "HT.h"
#include "SHT.h"
using namespace std;


int main(void){
    std::cout<<"Program Start"<<std::endl;
    // hi yo
    // hello there 
    // General Kenobi
    Record test{15,"Giorgos","Dimopoulos","Ioannina"};
    cout<<"Test's id: "<<test.id<<", Test's name: "<<test.name<<", Test's surname:"<<test.surname<<", Test's address:"<<test.address<<endl;
    //HT_info ht;
    return 0;
}
