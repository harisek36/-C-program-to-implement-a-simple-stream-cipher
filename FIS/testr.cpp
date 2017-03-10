#include<iostream.h>
using namespace std;
int main()
{
  char string[11]="A nice cat";
  char key[11]="ABCDEFGHIJ";
  for(int x=0; x<10; x++)
  {
    string[x]=string[x]^key[x];
    cout<<string[x];
  }
  return 0;
}
