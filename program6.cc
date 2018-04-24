/*
 *   PROGRAM 6 THE FINALE
 * Author: Samuel Hasan (srh160130@utdallas.edu)
 * Class: CS 3377.502
 */ 
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "cdk.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
//set the size for the matrix
#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Content;"

using namespace std;

const int maxRecordStringLength = 25;

class BinaryFileHeader
{
public:
  uint32_t magicNumber;
  uint32_t version;
  uint64_t records;

};

class binaryRecord
{
public:
  uint8_t strLength;
  char stringBugger[maxRecordStringLength];
};

int main()
{
  BinaryFileHeader *myRecord = new BinaryFileHeader();
  binaryRecord *myOtherRecord = new binaryRecord();
  ifstream binInfile("cs3377.bin", ios::in | ios::binary);
  
    //sees if file was successfully poened or no
  if(binInfile.fail())
  {
    cout <<".bin wasn't opened"<<endl;
    exit(0);
  }
    
    //reads 3 numbers from .bin
  binInfile.read((char *) myRecord, sizeof(BinaryFileHeader));
  //reads 4 numbers from .bin
  binInfile.read((char *) myOtherRecord,sizeof(binaryRecord));
  
  ostringstream convert;
  
  //convert magicNumber to a string with the hex value
  convert<<"0x"<<hex<<uppercase<<myRecord->magicNumber;
    //because it's a pointer can just refer the myRecord to magicNumber
  string magicNumber = "Magic: " +  convert.str();
    convert.str("");

    //verion turns to a string
    convert <<dec<<myRecord->version;
    string version = "Version: " + convert.str();
    convert.str("");

    //convert records to a string representation
    convert <<myRecord->records;
    string records = "records: " + convert.str();
    convert.str("");

    //get first string and its length
    convert <<myOtherRecord->stringBugger;
    string first = convert.str();
    convert.str("");
    convert<<strlen(first.c_str());
    string firstLen = "strlen: " + convert.str();
    convert.str("");

    //get second string and its length
    binInfile.read((char *) myOtherRecord,sizeof(binaryRecord));
    convert <<myOtherRecord->stringBugger;
    string second = convert.str();
    convert.str("");
    convert<<strlen(second.c_str());
    string secondLen = "strlen: " + convert.str();
    convert.str("");

    //get third string and its length
    binInfile.read((char *) myOtherRecord,sizeof(binaryRecord));
    convert <<myOtherRecord->stringBugger;
    string third = convert.str();
    convert.str("");
    convert<<strlen(third.c_str());
    string thirdLen = "strlen: " + convert.str();
    convert.str("");

    //get fourth string and its length
    binInfile.read((char *) myOtherRecord,sizeof(binaryRecord));
    convert <<myOtherRecord->stringBugger;
    string fourth = convert.str();
    convert.str("");
    convert<<strlen(fourth.c_str());
    string fourthLen = "strlen: " + convert.str();
    convert.str("");



  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"0", "a", "b", "c", "d", "e"};//gets th matrix height
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"0", "a", "b", "c"};//matrix width
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  //the cdk gets initialiezed to the string
  window = initscr();
  cdkscreen = initCDKScreen(window);

 //makes the cdk colorsz
  initCDKColor();

  
    //create the matrix along with setting the oconst to regular pointers
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("matrix wasn't made, there was a error\n");
      _exit(1);
    }

  //draws the matrix
  drawCDKMatrix(myMatrix, true);

  setCDKMatrixCell(myMatrix, 1, 1,magicNumber.c_str());
  setCDKMatrixCell(myMatrix, 1, 2,version.c_str());
  setCDKMatrixCell(myMatrix, 1, 3,records.c_str());
  setCDKMatrixCell(myMatrix, 2, 1,firstLen.c_str());
  setCDKMatrixCell(myMatrix, 2, 2,first.c_str());
  setCDKMatrixCell(myMatrix, 3, 1,secondLen.c_str());
  setCDKMatrixCell(myMatrix, 3, 2,second.c_str());
  setCDKMatrixCell(myMatrix, 4, 1,thirdLen.c_str());
  setCDKMatrixCell(myMatrix, 4, 2,third.c_str());
  setCDKMatrixCell(myMatrix, 5, 1,fourthLen.c_str());
  setCDKMatrixCell(myMatrix, 5, 2,fourth.c_str());

  drawCDKMatrix(myMatrix, true);    /* required  */

  //sleeps so it gives time to show the results on console
  sleep (10);


  // ends the CDK and closes the binary infile
  endCDK();
  binInfile.close();
}
