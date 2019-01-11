#include "HT.h"
using namespace std;

int HT_CreateIndex(char *fileName, char attrType, char* attrName, int attrLength, int buckets){
    //fstream HT_file (fileName);
    //if (!HT_file.is_open())
    //    return -1;
    
    if (BF_CreateFile(filename) < 0) {
		BF_PrintError("Error creating hash file");
		exit(EXIT_FAILURE);
	}

    int HT_fileDesc;
    if ((HT_fileDesc = BF_OpenFile(filename)) < 0) {
		BF_PrintError("Error opening file");
		return -1;
	}

    //umm    
    
    

    return 0;
}
