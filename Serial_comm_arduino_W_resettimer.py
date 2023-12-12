import serial
import time
from datetime import datetime
from time import strftime
myobj = datetime.now()
Time_value=0
if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600,timeout=1)
    ser.reset_input_buffer()
           
    # Get current time
    
    while True:
        # ser.reset_input_buffer()
       
        # ser.reset_output_buffer()
        
        
        if myobj.hour<12:
            print(myobj.hour)
            
            time.sleep(3)
            Time_value=1
            ser.write(str(Time_value).encode())
                       
        else:
            Time_value=0
            print(myobj.minute)
            time.sleep(3)
                       
                    
        if ser.in_waiting > 0:
            
          
            line = ser.readline().decode().rstrip()
            print(line)
            time.sleep(2)
            ser.reset_input_buffer()
            ser.reset_output_buffer()          
            ser.flushInput()
            ser.flushOutput()
                  
            
        
            
            
            
        
       
                