#include "HT.h"

using namespace std;

int HT_CreateIndex(char *fileName, char attrType, char* attrName, int attrLength, int buckets){
    fstream HT_file (fileName);
    if (!HT_file.is_open())
        return -1;

    // I think
    HT_file << attrType << " " << attrName << " " << attrLength << " " << buckets << endl;
    for(int i=0; i<buckets; i++)
        HT_file << "{}\n";
    // mmmaybe

    HT_file.close();
    return 0;
}

HT_info* HT_OpenIndex(char *fileName){
    int fileDesc_;            
    char attrType_;             
    char attrName_[128];   
    int attrLength_;          
    long int numBuckets_;    

    ifstream ht_file(fileName);

    char c;
    ht_file.get(attrType_);
    ht_file.get(c);
    int i=0;
    while(true){        
        ht_file.get(c);
        if(c==' ') break;
        attrName_[i]=c;
        i++;
    }

    ht_file >> attrLength_ >> numBuckets_;

    //umm
    HT_info ht = {32, attrType_, attrName_, attrLength_, numBuckets_};
    cout << ht.fileDesc << " " << ht.attrType << " " << ht.attrName << " " << ht.attrLength << " " << ht.numBuckets << " " << endl;
    return &ht;
}

