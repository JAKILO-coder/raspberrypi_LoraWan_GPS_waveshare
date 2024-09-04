#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>

 #include <stdio.h>
 #include <string.h>

#include "DEV_Config.h"
#include "L76X.h"

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Program stop\r\n"); 

    DEV_ModuleExit();

    exit(0);
}

int main(int argc, char **argv)
{
    GNRMC GPS;
    Coordinates Baidu;
    
	if (DEV_ModuleInit()==1)return 1;
    // Exception handling:ctrl + c
    
    signal(SIGINT, Handler);

    DEV_Delay_ms(100); 
    DEV_Set_Baudrate(9600);
    DEV_Delay_ms(100);


    while(1){
        GPS = L76X_Gat_GNRMC();
        printf("\r\n");
        printf("Time: %d:%d:%d \r\n", GPS.Time_H, GPS.Time_M, GPS.Time_S);
        printf("Latitude and longitude: %lf  %c  %lf  %c\r\n", GPS.Lat, GPS.Lat_area, GPS.Lon, GPS.Lon_area);
        Baidu = L76X_Baidu_Coordinates();
        printf("Baudu Coordinates   %lf,%lf    \r\n", Baidu.Lat, Baidu.Lon);
    }
	DEV_ModuleExit();
    return 0; 
}
