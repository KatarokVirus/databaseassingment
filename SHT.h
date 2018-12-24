typedef struct SHT_info{
int fileDesc;           // 
char* attrName;         // 
int attrLength;         // 
long int numBuckets;    // 
char* fileName          // primary id file
}SHT_info;


// Create file for hashing. return: 0 is success, -1 is fail.
int SHT_CreateIndex(char *fileName, char attrType, char* attrName, int attrLength, int buckets);


// Get the secondary hash table's info. return NULL in case of fire
SHT_info* SHT_OpenSecondaryIndex(char *sfileName);


// Close pointed file & release allocated memory.. return: 0 is success, -1 is fail.
int SHT_CloseSecondaryIndex(SHT_info* header_info);


// return: 0 is success, -1 is fail.
//int SHT_SecondaryInsertEntry(HT_info header_info, Record record);


// Delete entry with attrName == value. return: 0 is success, -1 is fail.
//int SHT_SecondaryDeleteEntry(SHT_info header_info, void *value);
// why not?


// Print all entries with attrName == value. return the number of entries printed.
int SHT_SecondaryGetAllEntries(SHT_info header_info, void *value);
