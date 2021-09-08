#include <math.h>
#include <stdio.h>

int main(){
    float init;
    float final;
    int duration;
    float acceleration;
    char *c;
    do
    {
        scanf("%f",&init);
        scanf("%f",&final);
        scanf("%d",&duration);
        float finit = init*1000/3600;
        float ffinal = final*1000/3600;
        printf("initial velocity: %f m/s\n",finit);
        printf("final velocity: %f m/s\n",ffinal);
        acceleration =(ffinal-finit)/duration;
        printf("%f\n",acceleration);
    } while (1);

}