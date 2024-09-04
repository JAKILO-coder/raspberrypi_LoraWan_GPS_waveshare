import L76X
import time
import math

try:
    x=L76X.L76X()
    x.L76X_Set_Baudrate(9600)
    while(1):
        x.L76X_Gat_GNRMC()
        if(x.Status == 1):
            print 'Already positioned'
        else:
            print 'No positioning'
        print 'Time %d:'%x.Time_H,
        print '%d:'%x.Time_M,
        print '%d'%x.Time_S

        print 'Lon = %f'%x.Lon,
        print ' Lat = %f'%x.Lat
        x.L76X_Baidu_Coordinates(x.Lat, x.Lon)
        print 'Baidu coordinate %f'%x.Lat_Baidu,
        print ',%f'%x.Lon_Baidu
except:
    #GPIO.cleanup()
    print "\nProgram end"
    exit()