#include "HT.h"
using namespace std;

int HT_CreateIndex(char *fileName, char attrType, char* attrName, int attrLength, int buckets){
    ofstream HT_file (fileName);
    if (!HT_file.is_open())
        return -1;

    // I think
    HT_file << "{" << attrType << " " << attrName << " " << attrLength << " " << buckets << "}\n";
    for(int i=0; i<buckets; i++)
        HT_file << "{}\n";
    // mmmaybe

    HT_file.close();
    return 0;
}

HT_info* HT_OpenIndex(char *fileName){

}
