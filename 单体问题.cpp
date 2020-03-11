#include<stdio.h>
#include<math.h>


int main(){
    FILE *fp=fopen("1.dat", "w");
    if(fp!=NULL){
        int pi = 3.1415926;
        double h=0.001;
        double x, y, vx, vy;
        int i;
// set t=0
        x=0; y=2; vx=1; vy=1; double m=3; 
        for(i=0; i<100000; i++){
            fprintf(fp, "%-.8f %-.8f\n", x, y);
            x=x+vx*h;
            y=y+vy*h;
            vx=vx-h*(1*m*x/(pow(x*x+y*y,1.5)));
            vy=vy-h*(1*m*y/(pow(x*x+y*y,1.5)));
        }       
    }
    fclose(fp);

    return 0;
}