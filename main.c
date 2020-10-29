#include <stdio.h>
#include <string.h>
#include "mymemory.h"

int main()
{
  printf ( "shell> start\n");
  initialize() ;
  //printsegmenttable();
  //printmemory() ;

//printsegmentdescriptor();
  char * ptr1 = (char *) mymalloc (10) ;
  strcpy (ptr1, "this test");
  printf( "\nshell> content of allocated memory: %s\n", ptr1 ) ; 
  printf("%p\n", &ptr1);
  //int x = myfree(mymemory);

  char * ptr2 = (char *) mymalloc (15) ;
  strcpy (ptr2, "this test");
  printf( "\nshell> content of allocated memory: %s\n", ptr2 ) ; 

  printmemory() ;
  //printsegmenttable();

  printf ( "\nshell> end\n");
  return 0;
}
