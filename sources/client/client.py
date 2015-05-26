#!/usr/bin/env python3.4

import signal

from ModuleConnect import *
from GetOptions import *
from MessageClass import *
from InterpretClass import *
from CommandClass import *

__author__ = "Nicolas Charvoz"
__copyright__ = "Copyright 2015, La Pintade"
__credits__ = ["Nicolas Charvoz", "Louis Audibert", "Serge Heitzler",
               "Antoine Garcia", "Florian Peru"]
__license__ = "GPL"
__versione__ = "1.1.1"
__email__ = "nicolas.charvoz@epitech.eu"
__status__ = "Dev"

p = GetOptions()
mess = MessageClass()
ic = InterpretClass()
s = None

def signal_handler(signal, frame):
    print('You pressed Ctrl+C')
    sys.exit(0)

def send_name_to_server(s):
    var = 'TEAM '
    var += p.getName()
    #var += '\n'
    mess.sendMessage(s, var)

def protocol(s):
    rec = mess.readMessage(s)
    if (ic.interpret_bienvenue(s, rec, p) == 1):
        send_name_to_server(s)
    rec = mess.readMessage(s)
    ic.interpret_num_client(s, rec, p)
    rec = mess.readMessage(s)
    ic.interpret_size(s, rec, p)
    var = 'OK'
    mess.sendMessage(s, var)

def act_command(s):
    avance_cmd(s, p, mess)

def main():
    try:
        p.parseOpt()
        if not p.getName():
            print('Exception : You need a name to start')
            sys.exit()
        mc = ModuleConnect()
        s = mc.connect(p.getHost(), p.getPort())
        protocol(s)
        act_command(s)
        s.close()
    except ConnectionRefusedError:
        print('Exception : The server has refused the connection')
    except getopt.GetoptError:
        print('Usage : client.py -n [NAME] -h [HOST] -p [PORT]')
    except:
        print('Exception : An error has occured')

if __name__ == "__main__":
    main()
