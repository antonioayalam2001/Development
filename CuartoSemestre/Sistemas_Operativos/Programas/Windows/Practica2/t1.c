// crt_stat.c
// This program uses the _stat function to
// report information about the file named crt_stat.c.

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

int main( void )
{
   struct _stat buf;
   struct stat attrib;
   int result;
   char timebuf[26];
   char* filename = "text1.txt";
   char* filenamee = "text2.txt";
   char* filenameee = "text2.txt";

   // Get data associated with "crt_stat.c":
   result = _stat( filename, &buf );

   // Check if statistics are valid:
   if( result != 0 )
   {
      perror( "Problem getting information" );
      switch (errno)
      {
         case ENOENT:
           printf("File %s not found.\n", filename);
           break;
         case EINVAL:
           printf("Invalid parameter to _stat.\n");
           break;
         default:
           /* Should never be reached. */
           printf("Unexpected error in _stat.\n");
      }
   }
   else
   {
      // Output some of the statistics:
      printf("archivo 1: \n");
      printf( "File size     : %ld\n", buf.st_size );
      printf( "Drive         : %c:\n", buf.st_dev + 'A' );
      stat("text1.txt", &attrib);
      char time[50];
      strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&attrib.st_mtime));
      printf ("%s\n", time);
   }

   result = _stat( filenamee, &buf );

   // Check if statistics are valid:
   if( result != 0 )
   {
      perror( "Problem getting information" );
      switch (errno)
      {
         case ENOENT:
           printf("File %s not found.\n", filenamee);
           break;
         case EINVAL:
           printf("Invalid parameter to _stat.\n");
           break;
         default:
           /* Should never be reached. */
           printf("Unexpected error in _stat.\n");
      }
   }
   else
   {
      // Output some of the statistics:
      printf("archivo 2: \n");
      printf( "File size     : %ld\n", buf.st_size );
      printf( "Drive         : %c:\n", buf.st_dev + 'A' );
      stat("text2.txt", &attrib);
      char time[50];
      strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&attrib.st_mtime));
      printf ("%s\n", time);
   }

   result = _stat( filenameee, &buf );

   // Check if statistics are valid:
   if( result != 0 )
   {
      perror( "Problem getting information" );
      switch (errno)
      {
         case ENOENT:
           printf("File %s not found.\n", filenameee);
           break;
         case EINVAL:
           printf("Invalid parameter to _stat.\n");
           break;
         default:
           /* Should never be reached. */
           printf("Unexpected error in _stat.\n");
      }
   }
   else
   {
      // Output some of the statistics:
      printf("archivo 3: \n");
      printf( "File size     : %ld\n", buf.st_size );
      printf( "Drive         : %c:\n", buf.st_dev + 'A' );
      stat("text3.txt", &attrib);
      char time[50];
      strftime(time, 50, "%Y-%m-%d %H:%M:%S", localtime(&attrib.st_mtime));
      printf ("%s\n", time);
   }
   
}