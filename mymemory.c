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
Byte  mymemory [MAXMEM] ;
//Segment_t * segmenttable = NULL;
int newmem = MAXMEM;

int segmentCounter = 0;
int sizecount = 0;

struct segmentdescriptor segmentlist[MAXSEGMENTS];


/*  struct segmentdescriptor = {
  .allocated = 0,
  .start = &mymemory,
  .size = MAXMEM,
  .next = NULL */ 






void initialize ()

{
  printf ( "initialize> start\n");
   
  for(int i=0; i<=MAXMEM; ++i)
  { 
    mymemory[i] = '\0';

  } 
  struct segmentdescriptor segmentlist[MAXSEGMENTS];
  segmentlist[0].allocated = 0,
  segmentlist[0].start = &mymemory,
  segmentlist[0].size = MAXMEM,
  segmentlist[0].next = NULL
  ;
  
  //Segment_t * segmenttable = &segment_default;
  //Segment_t ** seglist =  &segmenttable;



  printsegmentdescriptor(segmentlist);
  //segmentCounter++;
  
  
}



  /* void printsegmenttable()
  {
    char alloString [10];
    printf("here");
    for (size_t x=0; x<sizeof(segmentdescriptor); x++)
    {
      if( segmentdescriptor[x].allocated == 0)
    {
      strcpy(alloString,"False");
      }
      else
      {
        strcpy(alloString,"True");
        }
      printf("\n Segment 0 \n  allocated = %s \n  start = %p \n  size = %lu \n", alloString , segmentdescriptor[x].start, segmentdescriptor[x].size); 
      }
  } */

 
 void printmemory ()
 {
   for (int j = 0; j < MAXMEM/8; j++)
   {
     printf("Segment %d ", j * 8);

     for (int m = 0; m < 8; m++)
     {
      printf("%02x ", mymemory[m]);
    }

      printf("\n");
  }
 }


  void * mymalloc ( size_t size )
{
  int memcounter = 0;
  int i = 0;
  Segment_t *tempNode;
  //checks size and writes the memory
  if (newmem < size)
  {
    printf("\nNot enough memory left\n");
    //return 0;
  }
  else {
    while ( i < size)
  {
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
//creates written segment
Segment_t *teststart = findFree(&segmentlist[0], size);

printf("\n teststart = winning  \n"); 

   /* if (segmenttable == NULL)
  {
    struct segmentdescriptor segment_new = {
  .allocated = 1,
  .start = &size,
  .size = size,
  .next = NULL
    };
  tempNode = &segment_new;
  ;
    //struct segmentdescriptor * segmenttable = &segment_new;
    printsegmentdescriptor(&segment_new);

  }
  else
  {
    struct segmentdescriptor segment_new = {1, &size, size, tempNode}; */
  //printsegmentdescriptor(&segment_new);
  }
  segmentCounter++;
  newmem = newmem - size; 
   printnewmemory (segmentlist, newmem);

  //printf("segment counter= %d", segmentCounter);
  segmentCounter++;

  
  return &mymemory[size];
  
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

  void printnewmemory ( Segment_t * descriptor, int newsize )
{
  descriptor->size = newsize;
  printf ("Segment %d\n", segmentCounter);
  printf ( "\tallocated = %s\n" , (descriptor->allocated == FALSE ? "FALSE" : "TRUE" ) ) ;
  printf ( "\tstart     = %p\n" , descriptor->start ) ;
  printf ( "\tsize      = %lu\n", descriptor->size  ) ;
} 

//need to delete unwanted segments
/* void myfree ( Segment_t * ptr )
{
  int delsize = 0;
  int i = 0;
  size
  ptr->size = delsize;
  &ptr->start = delstart;
  while (i < delsize) 
  {
    if (&ptr->start != FALSE)
      {
        mymemory[i] = '\0';
        i++;
        } 
    }
} */




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

Segment_t * findFree ( Segment_t * list, size_t  size) 
{
  if(list[0].allocated == 0)
{
  printf("True");
  printf("%s",list[0].start);
  if(list->size<=size)
  {
    printf("True2");
    return list[0].start;
  }
}
  
else
{
  for(int i=0;i<sizeof(list);i++)
  {
    if(list->allocated == 1)
  {
    printf("False");

    list = list->next;
    if(list->allocated == 0)
    {
      if(list->size<=size)
      {
    return list->start;
    }
  
  }
  else
  {
  printf("list full");
  }
  }
}
}
return list->start;
}



int isPrintable ( int c )
{
  if ( c >= 0x20 && c <= 0x7e )
    {
      return c ;
}
return 0;
}

