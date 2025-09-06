#include<stdio.h>
int main()
{
 int f,i=0;
 int h[9]={0}, x[3]={0}, y[3]={0};
 FILE *input = fopen("../input/3.txt","r");
 for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
 for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
 for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
 fclose(input);
 int *p_x = &x[0] ;
 int *p_h = &h[0] ;
 int *p_y = &y[0] ;

 for (i = 0 ; i < 3; i++)
 {

 p_x = &x[0] ;
 for (f = 0 ; f < 3; f++)
  asm volatile(/*(*p_y = *p_y + *p_h++ * *p_x++;*/
 		"lw a0, (%0)\n\t"    
  		"lw a1, (%1)\n\t"    
  		"lw a2, (%2)\n\t"
  		"mul a3, a0, a1\n\t" //*p_h*p_x
  		"add a4, a2, a3\n\t"//*p_x**p_h+py
  		"sw a4, (%2)\n\t"     //store to %2
  		"addi %0, %0, 4\n\t"//*p_x++ 
  		"addi %1, %1, 4\n\t" //*p_h++
  		"li a5, 2\n\t"
  		"bne %3, a5, 1f\n\t"  // If i == 2, jump to label 3
  		"addi %2, %2, 4\n\t" //*p_y++
  		"1:\n\t"
  		
  		:"+r"(p_h), "+r"(p_x), "+r"(p_y), "+r"(f)
  		: 
  		: "a0", "a1", "a2", "a3", "a4", "a5", "memory"
		
 				
 		);

 }
 p_y = &y[0];
 for(i = 0; i<3; i++)
 printf("%d \n", *p_y++);
 return(0) ;

}
