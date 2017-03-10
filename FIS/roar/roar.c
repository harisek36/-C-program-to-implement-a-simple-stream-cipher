
#include<stdio.h>
#include<stdlib.h>

void encryption(const char *,int);
void decryption(const char *,int);


int main(int argc,char *argv[])
{
        char *fileName = argv[1];


        int seedvalue = atoi(argv[2]);

       	encryption(fileName,seedvalue);
       
        return(0);

}


void encryption(const char *text, int seed)         
{
        
	FILE *plaintext = fopen(text,"r");
        FILE *ciphertext = fopen("cipher.txt","w+");

	
        //FILE *ciphertext = fopen("cipher.txt","r");               
        FILE *plaintextR  = fopen("plain.txt","w+");


        char c,randomC,c_Char,randomChar,r_char;
        
	srand(seed);                                         
        printf("Cipher Text :\n");

        if(plaintext != NULL)
        {
                while(!feof(plaintext))

                {
                        c = fgetc(plaintext);                

                        randomC = (rand()%128);                  

                        c_Char = c^randomC;                  

                        fprintf(ciphertext,"%c",c_Char); 
                        printf("%c",c_Char);

                }
                
        }
	fclose(ciphertext);

	FILE *cipher1text = fopen("cipher.txt","r");
	srand(seed);
        printf("Retrived PLain text: \n");
	if(cipher1text != NULL)
        {
                while(!feof(cipher1text))
                {
                        c  = fgetc(ciphertext);
                        randomChar = (rand()%128);
                        r_char = c^randomChar;             

                        
                        printf("%c",r_char);
                }
                printf("\n\n\n");
        }
}


