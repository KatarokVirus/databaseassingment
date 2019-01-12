#include "HT.h"

//Create file for hashing. return: 0 is success, -1 is fail.
int HT_CreateIndex(char *fileName, char attrType, char* attrName, int attrLength, int buckets){
    
    //HT files needs blocks -> make a block file
    if (BF_CreateFile(fileName) < 0) {
		BF_PrintError("Error creating hash file");
		return -1;
	}

    //Use this int to manage the file 
    int HT_fileDesc;
    if ((HT_fileDesc = BF_OpenFile(fileName)) < 0) {
		BF_PrintError("Error opening file");
		return -1;
	}

    //Allocate bock for information
    if (BF_AllocateBlock(HT_fileDesc) < 0) {
		BF_PrintError("Error allocating block");
		return -1;
	}

    int blkCnt = BF_GetBlockCounter(HT_fileDesc);
	//printf("Test: HT file %s has %d blocks\n", fileName, blkCnt);

    
    //Block 0 has ze informazion
    char* s_attrLength = malloc((floor(log10(abs(attrLength)))+1)*sizeof(char));
    sprintf(s_attrLength, "%d", attrLength); 
    char* s_buckets = malloc((floor(log10(abs(buckets)))+1)*sizeof(char));
    sprintf(s_buckets, "%d", buckets); 

    char* block = malloc((strlen(attrName)+strlen(s_attrLength)+strlen(s_buckets)+5)*sizeof(char));

    if (BF_ReadBlock(HT_fileDesc, 0, &block) < 0) {
	    BF_PrintError("Error getting block");
	    return -1;
    }

    strcpy(block,&attrType);
    strcat(block," ");
    strcat(block,attrName);
    strcat(block," ");
    strcat(block, s_attrLength);
    strcat(block," ");
    strcat(block, s_buckets);
    //printf("Test block = %s\n", block);
    
    if (BF_WriteBlock(HT_fileDesc, 0) < 0){
	    BF_PrintError("Error writing block back");
	    return -1;
    }

    return 0;
}


//Get the hash table's info. return NULL in case of fire
HT_info* HT_OpenIndex(char *fileName){
    int HT_fileDesc;
    if ((HT_fileDesc = BF_OpenFile(fileName)) < 0) {
		BF_PrintError("Error opening file");
		return NULL;
	}

    //Read block 0 for ze informazion
    char* block;
    if (BF_ReadBlock(HT_fileDesc, 0, &block) < 0) {
	    BF_PrintError("Error getting block");
	    return NULL;
    }
    //printf("testio: block = %s\n", block);

    HT_info* HT = malloc(sizeof(HT_info));

    HT->fileDesc = HT_fileDesc;
    HT->attrType = block[0];
    
    HT->attrName = malloc(64*sizeof(char));
    int i=2;
    int j=0;
    do{
        HT->attrName[j] = block[i];
        i+=1;
        j+=1;
    }while(block[i]!=' ');

    char s_attrLength[16];   
    i+=1;
    j=0;
    do{
        s_attrLength[j] = block[i];;
        i+=1;
        j+=1;
    }while(block[i]!=' ');
    HT->attrLength = atoi(s_attrLength);
    
    char s_buckets[16];   
    i+=1;
    j=0;
    do{
        s_buckets[j] = block[i];
        i+=1;
        j+=1;
    }while(block[i]!=NULL);
    HT->numBuckets = atoi(s_buckets);

    return HT;
}






























