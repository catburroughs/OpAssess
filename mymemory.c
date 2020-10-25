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

int segmentCounter = 0;
int sizecount = 0;

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

  } 
  segmenttable->allocated = 0;
  segmenttable->start = &mymemory;
  segmenttable->size = MAXMEM;
  printsegmentdescriptor(&segment_default);
  
 
  segmentCounter++;

}



/*   void printsegmenttable()
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
 */
 
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

 void * mymalloc ( size_t size )
{
  //printf("here");
  int memcounter = 0;
  int i = 0;
  //printf("size = %lu",size);
  while ( i < size)
  {
    //printf("\ni = %d \n", i);
    if (mymemory[memcounter] == '\0')
    {
      mymemory[memcounter] = '1';
      i++;
      memcounter++;   
      } 
      else
      {
        memcounter++;
      } 
   }


   for(int i=0; i<size; ++i)
  {
    segmenttable->allocated = 0;
    segmenttable->start = &size;
    segmenttable->size = sizeof(mymemory) - size;
  }
  printsegmentdescriptor(&segment_default);

  struct segmentdescriptor segment_new = {
  .allocated = 1,
  .start = &segmenttable,
  .size = size,
  .next = NULL
  };

  struct segmentdescriptor * segmenttable = &segment_new;
  printf("\nsegment table size = %lu\n",sizeof(segmenttable));
  segmentCounter++;
  printsegmentdescriptor(&segment_new);
  printf("segment counter= %d", segmentCounter);
  return &mymemory[size];
   // implement the mymalloc functionality
  }

void printsegmentdescriptor ( Segment_t * descriptor )
{
      printf ("Segment %d\n", segmentCounter);
      printf ( "\tallocated = %s\n" , (descriptor->allocated == FALSE ? "FALSE" : "TRUE" ) ) ;
      printf ( "\tstart     = %p\n" , descriptor->start ) ;
      printf ( "\tsize      = %lu\n", descriptor->size  ) ;
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


int myfree ( void * ptr )
{
  for(int i=0; i<=MAXMEM; ++i)
  {  
    if (mymemory[i] == '\0')
    sizecount++;
  } 
return sizecount;
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




