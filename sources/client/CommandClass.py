import sys
import subprocess

class CommandClass():

    """ A class that send command to the server """

    def __init__(self):
        self.food = 10
        self.linemate = 0
        self.deraumere = 0
        self.sibur = 0
        self.mendiane = 0
        self.phiras = 0
        self.thystame = 0

    def getMessage(self, rec):
        firstPart, lastPart = rec.split(',')
        self.case = ''.join(i for i in firstPart if i.isdigit()).strip()
        print(self.case)
        if ('NEED OK' in lastPart):
            print('Someone accepted my request')
            need, ok, whoNeed, senderId = lastPart.rec(' ')
        else:
            need, nbPlayer, levelPlayer, senderId = lastPart.split(' ')


    def check_message(self, s, p, mess):
        rec = mess.readMessage(s)
        while ('message' in rec):
            self.getMessage(rec)
            rec = mess.readMessage(s)
        return rec

    def avance_cmd(self, s, p, mess):
        self.prend_cmd(s, p, mess, 'nourriture')
        if (p.getVerbose()):
            print('avance >>')
        var = 'avance'
        var += '\r\n'
        mess.sendMessage(s, var)
        #rec = mess.readMessage(s)
        rec = self.check_message(s, p, mess)
        if (rec == 'ok\n'):
            return 1
        elif (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            return 0

    def droite_cmd(self, s, p, mess):
        self.prend_cmd(s, p, mess, 'nourriture')
        if (p.getVerbose()):
            print('droite >> ')
        var = 'droite'
        var += '\r\n'
        mess.sendMessage(s, var)
        #rec = mess.readMessage(s)
        rec = self.check_message(s, p, mess)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'ok\n'):
            return 1
        elif (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            return 0

    def gauche_cmd(self, s, p, mess):
        self.prend_cmd(s, p, mess, 'nourriture')
        if (p.getVerbose()):
            print('gauche >>')
        var = 'gauche'
        var += '\r\n'
        mess.sendMessage(s, var)
        rec = self.check_message(s, p, mess)
#        rec = mess.readMessage(s)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'ok\n'):
            return 1
        elif (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            return 0

    def voir_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('voir >>')
        var = 'voir'
        var += '\r\n'
        mess.sendMessage(s, var)
        #rec = mess.readMessage(s)
        rec = self.check_message(s, p, mess)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'ko\n'):
            return 0
        elif (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            rec = rec[1:-2]
            voir_list = []
            voir_list = [str(x) for x in rec.split(',')]
            return voir_list

    def inventaire_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('inventaire >>')
        var = 'inventaire\r\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'ko\n'):
            return 0
        elif (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            rec = rec[1:-2]
            inventaire_list = []
            inventaire_list = [str(x) for x in rec.split(',')]
            i = 0
            for p in inventaire_list:
                if (i == 0):
                    self.food = p
                elif (i == 1):
                    self.linemate = p
                elif (i == 2):
                    self.deraumere = p
                elif (i == 3):
                    self.sibur = p
                elif (i == 4):
                    self.mendiane = p
                elif (i == 5):
                    self.phiras = p
                elif (i == 6):
                    self.thystame = p
                i+=1

#############Getters for food and Rocks ###################################

    def getLinemate(self) -> int:
        s = self.linemate
        s =''.join(i for i in s if i.isdigit())
        if (s):
            return int(s)
        return 0

    def getDeraumere(self) -> int:
        s = self.deraumere
        s =''.join(i for i in s if i.isdigit())
        if (s):
            return int(s)
        return 0

    def getSibur(self) -> int:
        s = self.sibur
        s =''.join(i for i in s if i.isdigit())
        if (s):
            return int(s)
        return 0

    def getMendiane(self) -> int:
        s = self.mendiane
        s =''.join(i for i in s if i.isdigit())
        if (s):
            return int(s)
        return 0

    def getPhiras(self) -> int:
        s = self.phiras
        s =''.join(i for i in s if i.isdigit())
        if (s):
            return int(s)
        return 0

    def getThystame(self) -> int:
        s = self.thystame
        s =''.join(i for i in s if i.isdigit())
        if (s):
            return int(s)
        return 0

    def getFood(self) -> int:
        s = self.food
        s =''.join(i for i in s if i.isdigit())
        if (s):
            return int(s)
        return 0
################################################################

    def prend_cmd(self, s, p, mess, obj):
        if (p.getVerbose()):
            print('prend >>')
        var = 'prend '
        var += obj
        var += '\r\n'
        mess.sendMessage(s, var)
        rec = self.check_message(s, p, mess)
#        rec = mess.readMessage(s)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'ok\n'):
            return 1
        elif (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            return 0

    def pose_cmd(self, s, p, mess, obj):
        if (p.getVerbose()):
            print('pose >>')
        var = 'pose '
        var += obj
        var += '\r\n'
        mess.sendMessage(s, var)
        rec = self.check_message(s, p, mess)
#        rec = mess.readMessage(s)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'ok\n'):
            return 1
        elif (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            return 0

    def expulse_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('expulse >>')
        var = 'expulse'
        var += '\r\n'
        mess.sendMessage(s, var)
        rec = self.check_message(s, p, mess)
 #       rec = mess.readMessage(s)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'ok\n'):
            return 1
        elif (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            return 0

    def broadcast_cmd(self, s, p, mess, obj):
        if (p.getVerbose()):
            print('broadcast >>')
        var = 'broadcast '
        var += obj
        var += '\n'
        mess.sendMessage(s, var)
        rec = self.check_message(s, p, mess)
#        rec = mess.readMessage(s)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'ok\n'):
            return 1
        elif (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            return 0

    def incantation_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('incantation >>')
        var = 'incantation'
        var += '\r\n'
        mess.sendMessage(s, var)
        rec = self.check_message(s, p, mess)
#        rec = mess.readMessage(s)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        elif (rec == 'elevation en cours\n'):
            rec = mess.readMessage(s)
            if (p.getVerbose()):
                print('During Elevation', rec)
            if (rec == 'mort\n'):
                print('You died\n')
                sys.exit(0)
            return 1
        else:
            return 0

    def fork_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('fork >>')
        var = 'fork'
        var += '\r\n'
        mess.sendMessage(s, var)
        rec = self.check_message(s, p, mess)
#        rec = mess.readMessage(s)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'ok\n'):
            return 1
        elif (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            return 0

    def connect_nbr_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('connect_nbr >>')
        var = 'connect_nbr'
        var += '\r\n'
        mess.sendMessage(s, var)
        rec = self.check_message(s, p, mess)
#        rec = mess.readMessage(s)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            return int(rec)

    def mort_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('mort >>')
        var = '-'
        var += '\r\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (p.getVerbose()):
            print(rec)
        if (rec == 'ok\n'):
            return 1
        elif (rec == 'mort\n'):
            print('You died\n')
            sys.exit(0)
        else:
            return 0
