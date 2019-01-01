#include <iostream>
#include <fstream>
#include "BF.h"
using namespace std;

/* H metavlhth opou kataxwreitai o kwdikos tou teleftaiou sfalmatos */
int BF_Errno;

void BF_Init(){} // ¯\_(ツ)_/¯

int BF_CreateFile(const char* filename){
    ofstream file;
    file.open(filename, ofstream::out | ofstream::trunc); // empty the file
    file.close();
    return 0;
}

int BF_OpenFile(const char* filename){
    
}

int BF_CloseFile(const int fileDesc){

}

