#include<stdio.h>
#include<time.h>
#include<sys/time.h>

static inline
double gettime(void) {
  // to be implemented: implemented gmc
  // modified by vinod
 /*The  use of the timezone structure is obsolete; the tz argument should normally be specified as NULL.*/

        struct timeval tv;
        struct timezone tz;
        double i;
        gettimeofday(&tv,NULL);
        i = tv.tv_usec;
        return i;

}


int convert_method1(char *str)
{


//char *ptr;


__asm__ __volatile__ ( //"movl %1,%%ebx;"
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
		"END:;"
			:
			:"b"  (str)
 		     );

printf("first = %s\n",str);

return 1;
}

int convert_method2(char *str)
{

__asm__ __volatile__ ( //"movl %1,%%ebx;"
		      //"subl $1,%%ebx;"
  		 "REP:  movl 0(%%ebx),%%edx;"
		   	"movzbl  %%dl,%%ecx;"
		 	"testl %%ecx,%%ecx;"
		  	"je END1;"
		         "cmpl $97,%%ecx;"
		   	"jb BEL;"
			"cmpl $122,%%ecx; "
		        "ja BEL;"
		 	"subl $32,(%%ebx);"
			"BEL:addl $1,%%ebx;"
			"jmp REP;"
		"END1:;"::"b"  (str)
 		     );


printf("d = %s\n",str);
return 1;
}


int main()
{
int no = 100, val ;

//clock_t  s1,e1,s2,e2;
double  s1,e1,s2,e2;

double t1=0.0,t2=0.0;
        
char str[] ="convert this i'm going to ttatatataataa ich leibe";

char tpr[20];

/*
s1 = clock();
val = convert_method1(str);
e1 = clock();

s2 = clock();
val = convert_method2(str);
e2 = clock();
*/
/*
s1 = gettime();
val = convert_method1(str);
e1 = gettime();
*/
s2 = gettime();
val = convert_method2(str);
e2 = gettime();

//t1 = (double) e1-s1;
t2 = (double) e2-s2;

printf("first = %.3f\n second = %.3f\n",t1,t2);

return 0;
}
