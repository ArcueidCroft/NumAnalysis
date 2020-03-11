#include<stdio.h>
#include<math.h>


int main(){
    FILE *fp=fopen("1.dat", "w");
    if(fp!=NULL){
        int pi = 3.1415926;
        double h=0.01;
        double x, v;
        int i;
// set t=0
        x=pi/2.0; v=0; double t=0; 
        for(i=0; i<1000; i++){
            fprintf(fp, "%-.8f %-.8f\n", t, x);
            v=v+(-9.8*sin(x))*h;
            x=x+h*(v);
            t=t+h;
        }       
    }
    fclose(fp);

    return 0;
}