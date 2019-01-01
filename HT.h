#include <iostream>
#include <fstream>
#include "BF.h"
#include "records.h"
using namespace std;

typedef struct HT_info{
    int fileDesc;           // the file, sorta
    char attrType;          // type of key
    char* attrName;         // name of key
    int attrLength;         // length of key
    long int numBuckets;    // number of buckets
}HT_info;


// Create file for hashing. return: 0 is success, -1 is fail.
int HT_CreateIndex(char *fileName, char attrType, char* attrName, int attrLength, int buckets);


// Get the hash table's info. return NULL in case of fire
HT_info* HT_OpenIndex(char *fileName);


// Close pointed file & release allocated memory. return: 0 is success, -1 is fail.
int HT_CloseIndex(HT_info* header_info);


// Insert record. return: 0 is success, -1 is fail.
int HT_InsertEntry(HT_info header_info, Record record);


// Delete record with attrName == value. return: 0 is success, -1 is fail.
int HT_DeleteEntry(HT_info header_info, void *value);


// Print all entries with attrName == value. return the number of entries printed.
int HT_GetAllEntries(HT_info header_info, void *value);
