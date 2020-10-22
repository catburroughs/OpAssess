/* mymemory.c
 * 
 * provides interface to memory management
 * 
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "mymemory.h"


// our memory
Byte        mymemory [MAXMEM] ;
struct segmentdescriptor segment_default = {
  .allocated = 0,
  .start = &mymemory,
  .size = MAXMEM,
  .next = NULL
};

struct segmentdescriptor * segmenttable = &segment_default;

void initialize ()

{
  printf ( "initialize> start\n");
   
  for(int i=0; i<=MAXMEM; ++i)
  { 
    mymemory[i] = '\0';
    //printf("%02x ", mymemory[i]);

  } 
  segmenttable->allocated = 0;
  segmenttable->start = &mymemory;
  segmenttable->size = MAXMEM;

  printsegmenttable();

}



  void printsegmenttable()
  {
    char alloString [10];
    if( segmenttable->allocated == 0)
    {
      strcpy(alloString,"False");
      }
      else
      {
        strcpy(alloString,"True");
        }
        printf("\n Segment 0 \n  allocated = %s \n  start = %p \n  size = %lu \n", alloString , segmenttable -> start, segmenttable -> size);
  }

 
 void printmemory ()
 {
   for (int i = 0; i < MAXSEGMENTS; i++)
  {
    printf("\n Segment %d ] ",i * 10);
    for (int j = 0; j< MAXMEM/MAXSEGMENTS; j++)
    {
      printf("%02x ", mymemory[i]);
    }
      printf("\n");
  }
 }







/*   int i;
  for(struct segmentdescriptor[i]; i<=MAXMEM/MAXSEGMENTS; ++i)
  {
    struct segmentdescriptor[i] = { 0, &i , MAXMEM/MAXSEGMENTS} ;
    
  } */
 
   // set memory to 0

   // create segment table
   // contains one segment description that declares the whole memory
   // as one free segment
   //
   // create a single segment descriptor
   
   // initialise the segment

  // printf ( "initialize> end\n");


void myfree ( void * ptr )
{

}

void * mymalloc ( size_t size )
{
   printf ( "mymalloc> start\n");
   int memcounter = 0;

   for (int i = 0; i < size; i++)
   {
     for (int j; j < sizeof(mymemory); j++)
     { 
       if (mymemory[j] == '\0'
       )
       mymemory[j] = 1;
       memcounter ++;
     }
     printf("%d", memcounter);
   }
   
return 0;
   // implement the mymalloc functionality
}

/* void myfree ( void * ptr )
{
   printf ( "myfree> start\n");

}  */

void mydefrag ( void ** ptrlist)
{
   printf ( "mydefrag> start\n");

}


// helper functions for management segmentation table
/* Segment_t * findFree ( Segment_t * list, size_t size )
{
   printf ( "findFree> start\n");


} */

void insertAfter ( Segment_t * oldSegment, Segment_t * newSegment )
{
}

/* Segment_t * findSegment ( Segment_t * list, void * ptr )
{
} */

int isPrintable ( int c )
{
   if ( c >= 0x20 && c <= 0x7e ) return c ;

   return 0 ;
}




void printsegmentdescriptor ( Segment_t * descriptor )
{
      printf ( "\tallocated = %s\n" , (descriptor->allocated == FALSE ? "FALSE" : "TRUE" ) ) ;
      printf ( "\tstart     = %p\n" , descriptor->start ) ;
      printf ( "\tsize      = %lu\n", descriptor->size  ) ;
}