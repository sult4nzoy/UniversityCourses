
#MITTUNIVERSITETET
#Författare: Omar Sultanzoy 
#Kurs: Operativsystem - L4 Trådar
#Examinator: Jimmy Åhlander
#Readers Writers problem 2 från wikipedia

import threading
from datetime import datetime
import time
txt="start string"
read_count = 0
write_count = 0
rmutex = threading.Lock()
wmutex = threading.Lock()
readTry = threading.Lock()
resource = threading.Lock()


def reader(reader_id):
    global read_count, txt
    for _ in range(5):
    
        #entry section
        readTry.acquire()
        rmutex.acquire()
        read_count+=1
        if(read_count==1):
            resource.acquire()
        rmutex.release()
        readTry.release()

        #critical section
        print("Läsare:", reader_id, " läser just nu")
        print("Läsare:", reader_id, " läste:", txt)
        print("Läsare:", reader_id, " har nu lämnat")

        #end section
        rmutex.acquire()
        read_count-=1
        if(read_count == 0):
            resource.release()
        rmutex.release()
        time.sleep(0.5)

def writer(writer_id):
    global write_count, txt
    for _ in range(5):
        #entry section
        wmutex.acquire()
        write_count+=1
        if write_count==1:
            readTry.acquire()
        wmutex.release()

        #critical section
        resource.acquire()
        print(writer_id, "skriver just nu")
        time_now = datetime.now()
        if(writer_id == "Skrivare A"):
            new_txt = "Datum: " + time_now.strftime('%Y-%m-%d %H:%M:%S')
            txt = new_txt 
        else:
            new_txt = "Datum: " + time_now.strftime('%Y-%m-%d %S:%M:%H')
            txt = new_txt
        print(writer_id, "har nu lämnat")
        resource.release()
        
        #exit section
        wmutex.acquire()
        write_count-=1
        if (write_count==0):
            readTry.release()
        wmutex.release()
        time.sleep(0.5)


def main():
    reader_1 = threading.Thread(target=reader, args=(1,))
    reader_2 = threading.Thread(target=reader, args=(2,))
    reader_3 = threading.Thread(target=reader, args=(3,))
    writer_1 = threading.Thread(target=writer, args=("Skrivare A",))
    writer_2 = threading.Thread(target=writer, args=("Skrivare B",))

    reader_1.start()
    reader_2.start()
    reader_3.start()
    writer_1.start()
    writer_2.start()
#-----------------------
    reader_1.join()
    reader_2.join()
    reader_3.join()
    writer_1.join()
    writer_2.join()

main()