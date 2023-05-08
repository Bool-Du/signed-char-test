#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef int32_t cell;
typedef uint32_t ucell;

#define UNPACKEDMAX   (((cell)1 << (sizeof(cell)-1)*8) - 1)

int main( int argc, char*argv[] )
{
   printf("hello world!\n");
   printf("size of wchat_t: %d\n", sizeof(wchar_t));

   //const char* char_source = "aaa";
   const char* char_source = "测试";
   char char_dest[256] = {0};
   cell cell_dest[256];
 
   int len = strlen( char_source );
   printf("raw string: %s\n", char_source);
   printf("UNPACKEDMAX:%d\n", UNPACKEDMAX);

   // amx_SetString()
   for( int i=0; i < len; i++ )
   {
      printf("raw string encode char_source[%d]:%d ~ (cell)char_source[%d]:%u\n", i, char_source[i], i, (cell)char_source[i]);

      cell_dest[i] = (cell)char_source[i];
   }
   cell_dest[len] = 0;

   // amx_GetString()
   printf("*cell_dest:%d - (ucell)*cell_dest: %u\n", *cell_dest, (ucell)*cell_dest );
   if( (ucell)*cell_dest > UNPACKEDMAX )
   {
      printf("unexpected path!\n");
   }
   else
   {
      int i = 0;

      while( cell_dest[i] != 0 )
      {
         char_dest[ i ] = (char)(cell_dest[ i ]);
	 i++;
      }
      printf("after convert: %s\n", char_dest);
   }

   return 0;
}
