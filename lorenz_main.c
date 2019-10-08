#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "math.h"

int main(int argc, char *argv[]) {
 
 int i,tmax;
 double f_i[2]; //f_in
 double f_o[2]; //f_out

 double a,b,c,h;
 
 char s_f[80],s_file[80];
 char *s;
 FILE *f;

 a = 10.0; 
 b = 27.34;
 c = 8.0/3.0;
 
 h = 0.01;
 
 //Compiling: atoi converts value to integer, so when code is compiled and executed, 
 //tmax must be specified in integer form, i.e:
 // icc lorenz_main.c
 // ./a.out 6500
 tmax = atoi(argv[1]);

 //Condiciones iniciales
 f_i[0] = -10.0;
 f_i[1] = -10.0;
 f_i[2] = -5.0;

 //Data output: b parameter is also known as the Rayleigh number, and according to theory,
 // a series of values change when this value changes, so, for this case I've included the 
 // while routine that takes the value of b (in this case 27.34) and prints out a file
 // changing the dot for a p. So, if you were to compile this code as is, you should get an 
 // output like: lorenz_Ra27p34.dat
 sprintf(s_f,"lorenz_Ra%1.2f",b);
 while((s=index(s_f,'.')) != NULL) { *s='p'; }
  strcat(s_f,".dat");
  printf("%s\n",s_f);
  sprintf(s_file,"./");
  strcat(s_file,s_f);
 printf("%s\n",s_file);
 f = fopen(s_file,"w");
 
 for(i=0;i<tmax;i++){
  
   f_o[0] = f_i[0] + h*a*(f_i[1]-f_i[0]);
   f_o[1] = f_i[1] + h*(f_i[0]*(b - f_i[2]) - f_i[1]);
   f_o[2] = f_i[2] + h*(f_i[0]*f_i[1] - c*f_i[2]);

    f_i[0] = f_o[0];
    f_i[1] = f_o[1];
    f_i[2] = f_o[2]; 
   fprintf(f,"%d\t%f\t%f\t%f\n",i,f_i[0],f_i[1],f_i[2]);
 }


}
