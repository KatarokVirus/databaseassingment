//#include "records.h"
//#include "BF.h"
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

    HT_info *ht;
    int HT_test = HT_CreateIndex("HT_test.txt", 'i', "boopity_doo", 2, 21);
    cout << HT_test << endl; //yay
    if(HT_test==-1){
        cout << "oh no" << endl;
        return 1;
    }
    ht = HT_OpenIndex("HT_test.txt");
    //cout << ht->fileDesc << ht->attrType << ht->attrName << ht->attrLength << ht->numBuckets << endl;

    BF_CreateFile("BF_test.txt");
    return 0;
}
