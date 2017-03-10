// File Name: HomeWork2.c
// Author: HARISH SEKAR
// Student ID: D398U589
// Homework : 2
// Description: C program to implement a simple stream cipher
// Last Changed: 2/26/2017


#include<stdio.h>
#include<stdlib.h>

void encryption(const char *,int);
void decryption(const char *,int);


int main(int argc,char *argv[])
{
        const char *plaintextName = argv[1];
	const char *ciphertextName = "ciphertext.txt";
	
	int seedValue = atoi(argv[2]);

	if(argc != 3)
        {
                printf("\n Use the below Format: \n  \t ./a.out <plain text file name> <seed value>\n\n");
		return 0;
        }
	
	
	printf("\n\n \t Seed Value: %d ",seedValue);
	
	encryption(plaintextName,seedValue);
        printf("\n\n \t CiperText File Name : %s",ciphertextName);


	decryption(ciphertextName,seedValue);
        return(0);

}


void encryption(const char *plaintextFile, int seedValue)    	  // Encryption function 
{
        FILE *openPlaintext = fopen(plaintextFile,"r");
        //const char *ciphertextFile = "ciphertext.txt";
        FILE *writeCiphertext = fopen("ciphertext.txt","w+");

        //int i;
        char c,randomC,cipherChar;
        
	srand(seedValue);                                         // setting the SEED value

        printf("\n\n \t Cipher Text :");

	if(openPlaintext != NULL)
        {
		while(!feof(openPlaintext))

                {
                        c = fgetc(openPlaintext);                // reading the plain text file char by char.

                        randomC = (rand()%128);                  // generating the random Characters within the ASCII range 0 - 127
                        
			cipherChar = c^randomC;			 // XOR operation between the plain text character and random character

                        fprintf(writeCiphertext,"%c",cipherChar); // generating the cipher text file
                        printf("%c",cipherChar);

		}
                fclose(openPlaintext);
                fclose(writeCiphertext);
        }
        else
                printf("\n Unable to open the file  ");
                
}

void decryption(const char *ciphertextFile,int seedValue)
{
        char c,same_randomC,retrivedPlainchar;
        FILE *openCiphertext = fopen(ciphertextFile,"r");		// Opening and Reading the cipher text
        FILE *retrivePlaintext  = fopen("retrivePlaintext.txt","w+");		// Opening and Writing the retrived plain text into a new file

        srand(seedValue);						// Resetting the seed value 

        printf("\n\n \t Retrived Plain Text :\n");
        if(openCiphertext != NULL)
        {
                while(!feof(openCiphertext))
                {
                        c = fgetc(openCiphertext);
                        same_randomC = (rand()%128);
                        retrivedPlainchar = c^same_randomC;		// XOR Operation between cipher text and random character

                        fprintf(retrivePlaintext,"%c",retrivedPlainchar); // Writing the retrived plain text into a new file
                        printf("%c",retrivedPlainchar);
                }
        	printf("\n\n\n");
	}
        else
                printf("\n Unable to open the Cipher Text File \n");
}

