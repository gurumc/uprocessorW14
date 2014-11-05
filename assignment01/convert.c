#include<stdio.h>

int convert(char *str)
{


char *ptr;

__asm__ __volatile__ ( "movl %1,%%ebx;"
		       "subl $1,%%ebx;"
  		"REPEAT: addl $1,%%ebx;"
			"movl 0(%%ebx),%%edx;"
		   	"movzbl  %%dl,%%ecx;"
		 	"testl %%ecx,%%ecx;"
		  	"je END;"
		         "cmpl $97,%%ecx;"
		   	"jb REPEAT;"
			"cmpl $122,%%ecx; "
		        "ja REPEAT;"
		 	"subl $32,(%%ebx);"
		 	"jmp REPEAT;"
		"END:mov %%ebx,%0;"
			:"=r" (ptr)
			:"r"  (str)
 		     );

printf("d = %s\n",str);
return 1;
}


int main()
{
int no = 100, val ;
        
char str[] ="sIMPle";

char tpr[20];

val = convert(str);
return 0;
}
