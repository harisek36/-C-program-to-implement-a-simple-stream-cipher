#include<stdio.h>
#include<stdlib.h>

void encryption(const char *text, int seed)
{

        FILE *plaintext = fopen(text,"r");
        FILE *ciphertext = fopen("cipher.txt","w+");
	//FILE *plaintextR  = fopen("plain.txt","w+");
   
   char c,randomC,c_Char,randomChar,r_char;

   srand(seed);
   printf("cipher text :\n");
if(plaintext != NULL){
while(!feof(plaintext)){  
   c = fgetc(plaintext);
   randomC = (rand()%127);
   c_Char = randomC^c;
   fprintf(ciphertext,"%c",c_Char);
   printf("%c",c_Char);
   }
   }
   fclose(ciphertext);
   FILE *cipher1text = fopen("cipher.txt","r");

   srand(seed);
   printf("\nRetrived text: \n");
if(cipher1text != NULL){
while(!feof(cipher1text)){
   c  = fgetc(ciphertext);
   randomChar = (rand()%127);
   r_char = randomChar^c;
   printf("%c",r_char);
   }
   
}
}

int main(int argc,char *argv[])
{
   char *fileName = argv[1];
   int seed = atoi(argv[2]);
   encryption(fileName,seed);
   return(0);

}




