import signal

from ModuleConnect import *
from GetOptions import *
from MessageClass import *
from InterpretClass import *

p = GetOptions()
mess = MessageClass()
ic = InterpretClass()

def signal_handler(signal, frame):
    print('You pressed Ctrl+C')
    sys.exit(0)

def send_name_to_server(s):
    var = 'TEAM ' 
    var += p.getName()
    mess.sendMessage(s, var)

def protocol(s):
    rec = mess.readMessage(s)
    ic.interpret_bienvenue(s, rec)
    rec = mess.readMessage(s)
    ic.interpret_num_client(s, rec)
    rec = mess.readMessage(s)
    ic.interpret_pos(s, rec)
    s.close

def main():
    try:
        p.parseOpt()
        if not p.getName():
            print('Exception : You need a name to start')
            sys.exit()
        mc = ModuleConnect()
        s = mc.connect(p.getHost(), p.getPort())
        protocol(s)
    except ConnectionRefusedError:
        print('Exception : The server has refused the connection')
    except getopt.GetoptError:
        print('Usage : client.py -n [NAME] -h [HOST] -p [PORT]')
    except:
        print('Exception : An error has occured')

if __name__ == "__main__":
    main()
