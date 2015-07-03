#!/usr/bin/env python3.4

import signal
import select
import sys

from ModuleConnect import *
from GetOptions import *
from MessageClass import *
from InterpretClass import *
from CommandClass import *
from IAClass import *
from threading import Thread

__author__ = "Nicolas Charvoz"
__copyright__ = "Copyright 2015, La Pintade"
__credits__ = ["Nicolas Charvoz", "Louis Audibert", "Serge Heitzler",
               "Antoine Garcia"]
__license__ = "GPL"
__versione__ = "1.1.1"
__email__ = "nicolas.charvoz@epitech.eu"
__status__ = "Dev"

p = GetOptions()
mess = MessageClass()
ic = InterpretClass()
cc = CommandClass()
s = None

def send_name_to_server(s):
    if (p.getName()):
        var = p.getName()
    else:
        self.team = 'Team'
        self.team += str(random.randint(1,10))
    var += '\r\n'
    mess.sendMessage(s, var)

def protocol(s):
    rec = mess.readMessage(s)
    if (ic.interpret_bienvenue(s, rec, p) == 1):
        send_name_to_server(s)
    else:
        print('The server has not send the Bienvenue message')
        sys.exit(0)
    rec = mess.readMessage(s)
    if (ic.interpret_num_client(s, rec, p) == -1):
        print('Cannot connect to the server, too many teamate already connected')
        s.close()
        sys.exit(0)
    rec = mess.readMessage(s)
    ic.interpret_size(s, rec, p)
    var = 'OK'
    var += '\r\n'
    #mess.sendMessage(s, var)

def listenToServer(s):
    flag = False
    while not flag:
        data = mess.readMessage(s)
        if not data:
            print('Shutting down.')
            flag = True
            sys.exit(0)
        elif data == 'mort\n':
            print('You died')
            flag = True
            sys.exit(0)
        else:
            sys.stdout.write('SERVER: ' + data + '\n')
            sys.stdout.flush()

def main():
    try:
        p.parseOpt()
        if not p.getName():
            print('Exception : You need a name to start')
            sys.exit()
        mc = ModuleConnect()
        s = mc.connect(p.getHost(), p.getPort())
        protocol(s)
        flag = False
        while not flag:
            try:
                if not p.getDbg():
                    ia = IAClass(s, p, mess)
                    threadIA = ia.run()
                    threadServer = listenToServer(s)
                    threadIA.start()
                    threadServer.start()
                    threadIA.join()
                    threadServer.join()
                else:
                    sys.stdout.write('$> ')
                    sys.stdout.flush()
                    inputready, outputready, execptready = select.select([0, s], [], [])
                    for i in inputready:
                        if i == 0:
                            data = sys.stdin.readline().strip()
                            if data:
                                data += '\r\n'
                                mess.sendMessage(s, data)
                        elif i == s:
                            data = mess.readMessage(s)
                            if not data:
                                print('Shutting down.')
                                flag = True
                                break
                            elif data == 'mort\n':
                                print('You died')
                                flag = True
                                break
                            else:
                                sys.stdout.write('SERVER: ' + data + '\n')
                                sys.stdout.flush()
            except KeyboardInterrupt:
                print('Interrupted.')
                s.close()
                break

    except ConnectionRefusedError:
        print('Exception : The server has refused the connection')
    #except getopt.GetoptError:
        print('Usage : client.py [-n [NAME]] [-h [HOST]] [-p [PORT]] [--dbg]')
    except ConnectionResetError:
        print('The server has shutdown')
    except BrokenPipeError:
        print('The server has hung up')
#    except TypeError:
 #       print('Parsing error, cannot handle too much things ..')
    #except:
     #   print('Exception : An error has occured')

if __name__ == "__main__":
    main()




            #     sys.stdout.write('$> ')
            #     sys.stdout.flush()
            #     inputready, outputready, execptready = select.select([0, s], [], [])
            #     for i in inputready:
            #         if i == 0:
            #             data = sys.stdin.readline().strip()
            #             if data:
            #                 act_command(s)
            #                 data += '\r\n'
            #                 #mess.sendMessage(s, data)
            #         elif i == s:
            #             data = mess.readMessage(s)
            #             if not data:
            #                 print('Shutting down.')
            #                 flag = True
            #                 break
            #             elif data == 'mort':
            #                 print('You died')
            #                 flag = True
            #                 break
            #             else:
            #                 sys.stdout.write('SERVER: ' + data + '\n')
            #                 sys.stdout.flush()
