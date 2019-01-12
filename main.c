#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HT.h"

main(){
    BF_Init();

    int oh_no = HT_CreateIndex("HT_test", 'i', "flamingos", 10, 20);
    printf("umm %d\n", oh_no); 

    HT_info* HT = HT_OpenIndex("HT_test");
    
    printf("HT: \nfileDesc = %d\nattrType = %c\nattrName = %s\nattrLength = %d\nnumBuckets = %d\n", 
           HT->fileDesc, HT->attrType, HT->attrName, HT->attrLength, HT->numBuckets);
}
