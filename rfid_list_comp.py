import serial
import time
import pandas as pd
from datetime import date,datetime
name=list()
roll=list()
time=list()
time_left=dict()
try:
   ser=serial.Serial('COM3',9600)
except:
    print("Processing")
column_names=['Name','Roll_No','Time','Time_left']
df=pd.DataFrame(columns=column_names)
i=0

while True:
    b = ser.readline()
    string_n = b.decode()  
    string = string_n.rstrip()
    flt =string
    if flt=="ANNAMALAI":
          today=date.today()
          now=datetime.now()
          name.append("Annamalai")
          roll.append(1816106)
          time.append(now.strftime('%H:%M:%S'))
          time_left["annamalai"]=None
          print("\nPerson 1 Entered Class")
          i+=1

    elif flt=="AJAI":
           today=date.today()
           now=datetime.now()
           name.append("Ajay")
           roll.append(1816117)
           time.append(now.strftime('%H:%M:%S'))
           time_left["ajay"]=None
           print("\nPerson 2 Entered Class")
           i+=1

    elif flt=="SANJAY":
          today=date.today()
          now=datetime.now()
          name.append("Sanjay")
          roll.append(1816139)
          time.append(now.strftime('%H:%M:%S'))
          time_left["sanjay"]=None
          print("\nPerson 3 Entered Class")
          i+=1

    elif flt=="anna":
         now=datetime.now()
         time_left["annamalai"]=now.strftime('%H:%M:%S')
         print("\nPerson 1 left the class")
         i+=1

    elif flt=="a1":
         now=datetime.now()
         time_left["ajay"]=now.strftime('%H:%M:%S')
         print("\nPerson 2 left the class")
         i+=1

    elif flt=="sanjay":
         now=datetime.now()
         time_left["sanjay"]=now.strftime('%H:%M:%S')
         print("\nPerson 3 left the class")
         i+=1
    else:
          pass

    if i>5:
        print("break")
        break
    else:
        pass
df['Name']=name
df['Roll_No']=roll
df['Time']=time
df['Time_left']=time_left.values()
df.to_csv(r'C:\Users\Annamalai\Desktop\rfid_tag\attendence'+now.strftime('%d_%m_%Y')+'.csv')

        
