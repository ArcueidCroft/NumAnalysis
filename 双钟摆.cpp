#include<stdio.h>
#include<math.h>


int main(){
    FILE *fp=fopen("1.dat", "w");
    if(fp!=NULL){
        double pi = 3.1415926;
        double h=0.01;
        double g=9.81;
        double y[4];
        int i;
        double d=0;
// set t=0
        double t=0; 
        y[0]=pi/6.0;y[1]=0;y[2]=pi/3.0;y[3]=0;d=0.1;
        for(i=0; i<1000; i++){
            fprintf(fp, "%-.8f  %-.8f  %-.8f\n", t, y[0], y[2]);
            y[1]=y[1]+h*(-3*g*sin(y[0])-g*sin(y[0]-2*y[2])-2*sin(y[0]-y[2])*(y[3]*y[3]-y[1]*y[1]*cos(y[0]-y[2])))/(3-cos(2*y[0]-2*y[2]))-d*y[1];
            y[3]=y[3]+h*(2*sin(y[0]-y[2])*(2*y[1]*y[1]+2*g*cos(y[0])+y[3]*y[3]*cos(y[0]-y[2]))/(3-cos(2*y[0]-2*y[2])));
            y[0]=y[0]+h*y[1];
            y[2]=y[2]+h*y[3];
            t=t+h;
        }       
    }
    fclose(fp);

    return 0;
}