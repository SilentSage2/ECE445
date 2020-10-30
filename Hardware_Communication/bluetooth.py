import time
import serial

serial_port = serial.Serial(
    port="/dev/cu.SLAB_USBtoUART",
    baudrate=9600,
    bytesize=serial.EIGHTBITS,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
)
# Wait a second to let the port initialize
time.sleep(1)
buffer = ""
try:
    serial_port.write("AT\r\n".encode('ascii'))
    serial_port.write("AT+INQ\r\n".encode('ascii'))
    time.sleep(5)
    serial_port.write("AT+CONN1\r\n".encode('ascii'))
    # serial_port.write(" slave 2 begin".encode('ascii'))
#     while serial_port.isOpen():
#         if serial_port.inWaiting() > 0:
#             data = serial_port.read()
#             buffer += data.decode()
#             if data.decode()=="\r" or data.decode()=="\n":
#                 print(str(time.time())+" "+buffer)
#     #                 print("here")
#                 buffer = ""
#         elif serial_port.inWaiting()<=0:
#             time.sleep(1)
#             serial_port.write(data)
            # if we get a carriage return, add a line feed too
            # \r is a carriage return; \n is a line feed
            # This is to help the tty program on the other end 
            # Windows is \r\n for carriage return, line feed
            # Macintosh and Linux use \n
#             if data == "\r".encode('ascii'):
#                 # For Windows boxen on the other end
#                 serial_port.write("\n".encode('ascii'))
except KeyboardInterrupt:
    print("Exiting Program")

except Exception as exception_error:
    print("Error occurred. Exiting Program")
    print("Error: " + str(exception_error))

finally:
    serial_port.close()
    pass