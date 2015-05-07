import signal

from ModuleConnect import *
from GetOptions import *
from MessageClass import *

p = GetOptions()
mess = MessageClass()

def signal_handler(signal, frame):
    print('You pressed Ctrl+C')
    sys.exit(0)

def send_name_to_server(s):
    var = p.getName()
    mess.send_message(s, var)

def interpret_bienvenue(s, rec):
    if (rec == b'BIENVENUE\r\n'):
        if (p.getVerbose() == True):
            print('OK')
        send_name_to_server(s)

def protocol(s):
    rec = mess.read_message(s)
    interpret_bienvenue(s, rec)
    # while True:
    #     var = get_message()
    #     send_message(s, var)
    #     print(s.recv(1024))
    #     if var == "exit":
    #         print("Goodbye")
    #         break
    #     s.close

def main():
    try:
        #p = GetOptions()
        p.parse_opt()
        mc = ModuleConnect()
        s = mc.connect(p.getHost(), p.getPort())
        protocol(s)
    except:
        print('An Error as happened')

if __name__ == "__main__":
    main()
