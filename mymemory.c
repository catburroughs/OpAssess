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
struct segmentdescriptor segmentlist[MAXSEGMENTS];
Segment_t * segmentpointer;
Segment_t * segmenttable;

int newmem = MAXMEM;

int segmentCounter = 0;
int sizecount = 0;




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
  //struct segmentdescriptor segmentlist[MAXSEGMENTS];
  segmentlist->allocated = 0,
  segmentlist->start = &mymemory,
  segmentlist->size = MAXMEM,
  segmentlist->next = NULL;
  printf("\ninitialize memory ---- %p\n",&mymemory);
  segmentpointer = segmentlist;
  segmenttable = (Segment_t *)segmentlist;

  printf("\ninitialize pointer ---- %p, %p\n", &segmenttable, segmenttable);

 /*  struct segmentdescriptor segmentlist[MAXSEGMENTS];
  segmentlist[0].allocated = 0,
  segmentlist[0].start = &mymemory,
  segmentlist[0].size = MAXMEM,
  segmentlist[0].next = NULL */
  ;
  
  //Segment_t * segmentpointer = &segment_default;
  //Segment_t ** seglist =    segmentpointer;

  //printsegmentdescriptor(0);
  //segmentCounter++;
  
  
}



  /* void prin  segmentpointer()
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
   int x;
   for (int j = 0; j < MAXMEM/8; j++)
   {
     printf("| %d |", j * 8);

     for (int m = 0; m < 8; m++)
     {
      x = isPrintable(mymemory[j]);
      printf("%02x ", x);
    }

      printf("\n");
  }
 }

 void * segmentinsert(size_t size, int x, Segment_t * starter)
 {
   segmentlist[x].allocated = 1,
  segmentlist[x].start = &starter,
  segmentlist[x].size = size,
  segmentlist[x].next = NULL;
  segmentpointer = &segmentlist[x];
  printf("\n 116 insert pointer ---- %p\n",&starter);
  printf("\n 117 segmentable pointer ---- %p\n", segmentpointer);


  return 0;
 }



  void * mymalloc ( size_t size )
{
  int memcounter = 0;
  printf("\n128 %d\n",segmentCounter);
  //int i = 0;
  //size_t *tempNode;
  //checks size and writes the memory
  if (newmem < size)
  {
    printf("\nNot enough memory left\n");
    //return 0;
  }
  else {
    //printf("\nsize = %lu\n",size);
    int c = 0;
    while (memcounter <= size)
  {
    if (mymemory[c] == '\0')
    {
      //teststart = 1; //place value at pointer
      memcpy(mymemory, &size, sizeof(mymemory));
      //mymemory[memcounter] = 1;
      memcounter++; 
      c++;
      //printf("\nteststart = null\n");  
      }
      else
      c++;
     // {
        //memcounter++;
     // }
     
   } 
//creates written segment
//char * newerpointer = malloc(size);
//printf("newer pointer = %p",newerpointer); 
//printf("\n %p \n", segmentlist[0].start);

//working new section
size_t tempNode = (size_t)malloc(size);
  if(segmentCounter >= 1)
  {
    printf("\n-170 segment counter is %d 170 -\n",segmentCounter);
    Segment_t *teststart = findFree(&segmentlist[segmentCounter], size);
    insertAfter(&segmentlist[segmentCounter-1], &segmentlist[segmentCounter]);
    segmentinsert(tempNode, segmentCounter, teststart);


  }
  else 
  {
    printf("179 %lu",size);
    segmenttable = &segmentlist[segmentCounter];
    size_t tempNode = (size_t)malloc(size);
    segmentinsert(tempNode, segmentCounter, segmentpointer);
  }
  
  /* segmentlist[0].allocated = 1,
  segmentlist[0].start = &mymemory[size],
  segmentlist[0].size = size,
  segmentlist[0].next = NULL; */

  //tempNode = &segment_new;
    //struct segmentdescriptor *  segmentpointer = &segment_new;
  //printsegmentdescriptor(0);

  /* else
  {
    struct segmentdescriptor segment_new = {1, &size, size, tempNode}; 
  //printsegmentdescriptor(&segment_new); 
  } */
  //segmentCounter++;
  newmem = newmem - size; 

  //printf("segment counter= %d", segmentCounter);
  segmentCounter++;
  printf("204 segment counter = %d", segmentCounter);


   // printf("\nsegmentlist ---- %zu \n",segmentlist[0].size);
  
  } 
  //prin  segmentpointer();
  return  segmentpointer;
  
} 

void printsegmenttable()
{
  printf("217");
  while(segmenttable != NULL)
  {
    for(int j = 0; j <= segmentCounter; j++)
    {
    printf("current pointer %p \n",segmenttable);
    printf ("Segment %d \n",j);
    printf ( "\tallocated = %s\n" , (segmenttable->allocated == FALSE ? "FALSE" : "TRUE" ) ) ;
    printf ( "\tstart     = %p\n" , segmenttable->start ) ;
    printf ( "\tsize      = %lu\n", segmenttable->size) ;
    printf ("\tnext      =%p\n", segmenttable->next);
    //printf("\nprint  segmentpointerfunctionabove\n");
    segmenttable = segmenttable->next;
    }

  }

  //return 0;
}

/*   if (segmenttable->next != NULL)
  {
    printf("next");
    segmenttable = segmenttable->next;
    }
    else
    {
      printf("\nno next\n"); 
    }
  printnewmemory (segmentlist, newmem);

  
} */

 
/* void printsegmentdescriptor (int index )
{
      printf ("Segment %d\n", segmentCounter);
      printf ( "\tallocated = %s\n" , (segmentlist[index].allocated == FALSE ? "FALSE" : "TRUE" ) ) ;
      printf ( "\tstart     = %p\n" , segmentlist[index].start ) ;
      printf ( "\tsize      = %lu\n", segmentlist[index].size  ) ;
} */
 

/*   int i;
  for(struct segmentdescriptor[i]; i<=MAXMEM/MAXSEGMENTS; ++i)
  {
    struct segmentdescriptor[i] = { 0, &i , MAXMEM/MAXSEGMENTS} ;
    
  } */
   // set memory to 0
   // create segment table
   // contains one segment description that declares the whole memory
   // as one free segment
   // create a single segment descriptor
   // initialise the segment
  // printf ( "initialize> end\n");

  void printnewmemory ( Segment_t * descriptor, int newsize )
{
  descriptor->size = newsize;
  Segment_t *newmempointer = findFree(descriptor, newsize);
  segmentlist->allocated = 0,
  segmentlist->start = &newmempointer,
  segmentlist->size = newmem,
  segmentlist->next = NULL;
  printf ("\nFree Memory\n");
  printf ( "\tallocated = %s\n" , (descriptor->allocated == FALSE ? "FALSE" : "TRUE" ) );
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

/* void mydefrag ( void ** ptrlist)
{
   printf ( "mydefrag> start\n");

} */


// helper functions for management segmentation table
/* Segment_t * findFree ( Segment_t * list, size_t size )
{
   printf ( "findFree> start\n");


} */

void insertAfter ( Segment_t * oldSegment, Segment_t * newSegment )
{
  void * hing = &newSegment;
  oldSegment->next = hing;
  printf("\n330 old next is %p and new start is %p\n", oldSegment->next, &newSegment);
}

Segment_t * findFree ( Segment_t * descriptor, size_t  size){
  printf("334 here");
  if(descriptor->allocated == 0)
{
  printf("True");
  printf("%p", &descriptor->start);
  if(newmem >= size)
  {
    printf("\nTrue2\n");
  }
  printf("\n344 free pointer %p", &descriptor);
  //return descriptor;
} 
else
{
  if(descriptor->allocated == 1)
  printf("whilehere"); //PROBLEMMMMMMMM
  {
  descriptor = descriptor->next;
  printf("here");
  if(descriptor->allocated == 0)
  {
  printf("355 this is the insert pointer %p", &segmentlist[size]);
  //return descriptor->start;
  }
  }
}
printf("\n361 free pointer %p", &descriptor);
return descriptor;
}
    /* descriptor = descriptor->next;
    if(descriptor->allocated == 0)
    {
      if(descriptor->size<=size)
      {
    return descriptor->start;
    }
  
  }
  else
  {
  printf("list full");
  }
  }
  }
} */
//return descriptor->start;




int isPrintable ( int c )
{
  if ( c >= 0x20 && c <= 0x7e )
    {
      return c ;
}
return 0;
}

