#include <stdio.h>
#include <string.h>
#include "mymemory.h"

int main()
{
  printf ( "shell> start\n");
  initialize() ;
  printsegmenttable();
  printmemory() ;

//printsegmentdescriptor();

  printf ( "shell> end\n");
  return 0;
}
