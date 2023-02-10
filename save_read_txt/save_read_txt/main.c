/*****************************************************************************
                        Microsoft Visual Studio 2022
                                           Debug x64

                        Keywords:
                           save or read data in txt
                           copy strings and arrays
                           format of read and print
                                                   By Edward Z. Wu 2023-02-10
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS // avoid error C4996

#include <stdio.h>
#include <string.h>

#define N  500 // length of signal

int main()
{
    double sig_read[N], sig_write[N];
   
    char folder[] = "E:/Cproject/save_read_txt/save_read_txt/"; // use "\\" or "/" (single "/" on "?" key) 
    //char folder[] = "E:\\Cproject\\save_read_txt\\save_read_txt\\"; // another option
    char fpath[200] = "";

    int a1 = strlen("123456"); // a1=6
    int a2 = sizeof("123456"); // a2=7 bytes, the last: "\0", end of every string
    // sizeof: return bytes. One byte for every "char".

/********************** read ***********************/
    memcpy(fpath, folder, sizeof(folder));
    //strcpy(fpath, folder); // another option to copy string
    strcat(fpath, "sig_read.txt");

    FILE* fp = NULL;
    fp = fopen(fpath, "r"); // open a file that already exists
    if (fp == NULL) // if fail to find or open the file, return -1
        return -1;
    int i = 0;
    while (fscanf(fp, "%lf", &sig_read[i]) != EOF && i < N ) // read until the end of file
        i++;
    fclose(fp);

    /* Notes 
    float sig_fread[N];
    while (fscanf(fp, "%f", &sig_fread[i]) != EOF && i < N ) 
          i++;
    * It also works, but can only read 6 accurate digits after decimal point.
    * "%f" <---> float
    * "%lf" <---> double
    * "%.20lf" won't work.
    */

/******************** read end *********************/

    int a3 = sizeof(sig_read);// when N=500, a3=500*8=4000; 8 bytes in every double number.
    memcpy(sig_write, sig_read, sizeof(sig_read));// copy array

/********************** write ***********************/
    strcpy(fpath, folder);
    strcat(fpath, "sig_write.txt");

    fp = fopen(fpath, "w");// If not exists, create a file; write(overwrite) from the beginning.
    for (int i = 0; i < N; i++)
        //fprintf(fp, "%lf\r\n", sig_write[i]); // %lf, 6 digits after decimal point
        fprintf(fp, "%.22lf\r\n", sig_write[i]); 
    // %.22lf, 22 digits after decimal point, but only 20 accurate based on data read.
    fclose(fp);
/******************** write end *********************/


    return 0;
}