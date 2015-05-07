import signal

from ModuleConnect import *
from GetOptions import *

p = GetOptions()

def signal_handler(signal, frame):
    print('You pressed Ctrl+C')
    sys.exit(0)

def send_message(s, var):
    s.send(var.encode())

def get_message():
    signal.signal(signal.SIGINT, signal_handler)
    return input('$> ')

def read_message(s) -> str:
    received = s.recv(1024)
    return received
    
def send_name_to_server(s):
    var = p.getName()
    send_message(s, var)

def interpret_bienvenue(s, rec):
    if (rec == b'BIENVENUE\r\n'):
        if (p.getVerbose() == True):
            print('OK')
        send_name_to_server(s)

def protocol(s):
    rec = read_message(s)
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
