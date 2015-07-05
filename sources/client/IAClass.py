import time
import random
import subprocess
import string
import re
import sys
import math
from array import *
from CommandClass import *
from MoveClass import *

class IAClass():

    """ IAClass that handle the zappy's AI """

    def __init__(self, s, p, mess):
        self.s = s
        self.p = p
        self.mess = mess
        self.cc = CommandClass()
        self.move = MoveClass()
        self.rocksTab = ['linemate', 'deraumere', 'sibur', 'mendiane', 'phiras', 'thystame']
        self.linemate = 0
        self.deraumere = 0
        self.sibur = 0
        self.mendiane = 0
        self.phiras = 0
        self.thystame = 0
        self.inFrontOfMe = []
        self.playerNeeded = 1
        self.linemateNeeded = 1
        self.deraumereNeeded = 0
        self.siburNeeded = 0
        self.mendianeNeeded = 0
        self.phirasNeeded = 0
        self.thystameNeeded = 0
        self.itemsNeeded = [1, 1, 0, 0, 0, 0, 0, 0]
        self.itemsNeededStill = [1, 1, 0, 0, 0, 0, 0, 0]
        self.rows = 4
        chars = string.ascii_uppercase + string.digits
        self.uid = ''.join(random.choice(chars) for _ in range(6))
        self.targets = [] # TABLEAU DE TARGETS POUR LA PARTIE A
        self.target = ""   # FOCUS TARGET POUR LA PARTIE B
        self.hasTarget = False
        self.needState = False
        self.whereState = False
        self.moveState = True
#        self.distMax = math.sqrt(((x/2)*(x/2) + (y/2)*(y/2)))
        print('Here is my id : ', self.uid)

    def getMessage(self, rec):
        firstPart, lastPart = rec.split(',')
        case = ''.join(i for i in firstPart if i.isdigit()).strip()
        if ('NEED OK' in lastPart):
            print('Someone accepted my request')
            need, ok, whoNeed, senderId = lastPart.split(' ')
            return (1, need, ok, whoNeed, senderId)
        elif ('NEED CANCEL' in lastPart):
            need, cancel, senderId = lastPart.split(' ')
            return (-1, need, cancel, 0)
        elif ('WHERE' in lastPart):
            need, senderId = lastPart.split(' ')
            return (-2, senderId, case, 0, 0)
        else:
            need, nbPlayer, levelPlayer, senderId = lastPart.split(' ')
            return (0, need, nbPlayer, levelPlayer, senderId)

    def buildMessageForBroadcast(self):
        string = 'NEED '
        string += str(self.itemsNeeded[0] - 1)
        string += ' '
        string += str(self.getLevel())
        string += ' '
        string += self.uid
        self.needState = True
        print('jenvoie : ', string)
        return string

    def buildMessageWhere(self):
        string = 'WHERE '
        string += self.uid
        return string

    def buildOkMessage(self, senderId):
        string = 'NEED OK '
        string += senderId
        string = re.sub('\n|\r', '', string)
        string += ' '
        string += self.uid
        print('I send : ', string)
        return string

    def sendNeedOk(self, nbPlayer, levelPlayer, senderId):
        if (self.hasTarget == False):
            if (self.getLevel() == int(levelPlayer)):
                if (self.target == ""):
                    self.target = senderId;
                    self.cc.broadcast_cmd(self.s, self.p, self.mess, \
                                          self.buildOkMessage(senderId))
                    print('ma target est : ', self.target)
                    self.hasTarget = True

    def whereisIaTarget(self): #S'occupe d'envoyer WHERE.
        string = 'WHERE '
        string += str(self.uid)
        self.whereState = True
        return string

    def cancelNeed(self): # S'occupe de reset les targets si pas assez de targets dans le tableau.
        string = 'NEED CANCEL '
        string += str(self.uid)
        del self.targets[:]
        self.hasTarget = False

    def receiveCancelNeed(self, senderId):
        if (self.target):
            self.target = 0
            self.hasTarget = False

    def receiveWhere(self, senderId, case):
        print('Case ou on doit aller : ', case)
        if (case == 0):
            print('ON est ensemble')
            self.dropRocks()
            if (self.cc.broadcast_cmd(self.s, self.p, self.mess) != -1):
                self.moveState = True
            sys.exit(0)
        self.whereState = True
        if (senderId == self.target):
            if (case == 0):
                self.needState = True
            self.getBroadcastDirection(case)
            self.cc.broadcast_cmd(self.s, self.p, self.mess, self.buildMessageWhere())

    def receiveNeedOk(self, senderId):
        self.hasTarget = True
        self.targets.append(senderId)
        if (len(self.targets) >= self.getNbPlayerRequired()):
            self.cc.broadcast_cmd(self.s, self.p, self.mess, self.whereisIaTarget())
            self.moveState = False
    def parseBroadCastMessage(self):
        mess = self.cc.getMessage()
        print('mess >>', mess)
        check = 4
        var1 = 0
        var2 = 0
        var3 = 0
        if (mess):
            check, need, var1, var2, var3 = self.getMessage(mess)
        if (check == 0):
            self.sendNeedOk(var1, var2, var3)
        elif (check == -1):
            self.receiveCancelNeed(var3)
        elif (check == 1):
            self.receiveNeedOk(var3)
        elif (check == -2):
            self.receiveWhere(need, var1)

    def defineWhatWeNeedMost(self):
        if (self.getLevel() == 1):
            return [1, 1, 0, 0, 0, 0, 0]
        elif (self.getLevel() == 2):
            return [2, 1, 1, 1, 0, 0, 0]
        elif (self.getLevel() == 3):
            return [2, 2, 0, 1, 0, 2, 0]
        elif (self.getLevel() == 4):
            return [4, 1, 1, 2, 0, 1, 0]
        elif(self.getLevel() == 5):
            return [4, 1, 2, 1, 3, 0, 0]
        elif(self.getLevel() == 6):
            return [6, 1, 2, 3, 0, 1, 0]
        elif(self.getLevel() == 7):
            return [6, 2, 2, 2, 2, 2, 1]
        elif(self.getLevel() == 8):
            return [0, 0, 0, 0, 0, 0, 0]

    def getNbRows(self):
        level = self.getLevel()
        nb = 1
        while (level >= 1):
            nb += ((level * 2) + 1)
            level -= 1
        return nb

    def convertVoirToBinary(self):
        self.rows = self.getNbRows()
        col = 7
        myList = [[0 for x in range(col)] for x in range(self.rows)]
        i = 0
        try:
            for p in self.inFrontOfMe:
                if ('joueur' in p):
                    myList[i][0] = p.count('joueur')
                else:
                    myList[i][0] = 0
                if ('linemate' in p):
                    myList[i][1] = p.count('linemate')
                else:
                    myList[i][1] = 0
                if ('deraumere' in p):
                    myList[i][2] = p.count('deraumere')
                else:
                    myList[i][2] = 0
                if ('sibur' in p):
                    myList[i][3] = p.count('sibur')
                else:
                    myList[i][3] = 0
                if ('mendiane' in p):
                    myList[i][4] = p.count('mendiane')
                else:
                    myList[i][4] = 0
                if ('phiras' in p):
                    myList[i][5] = p.count('phiras')
                else:
                    myList[i][6] = 0
                if ('thystame' in p):
                    myList[i][6] = p.count('thystame')
                else:
                    myList[i][6] = 0
                i += 1
                return myList
        except:
            return [1, 0, 0, 0, 0, 0, 0]


    def buildXor(self):
        return [0, 0, 0, 0, 0, 0]

    def checkBestCase(self):
        tmp = list(self.itemsNeeded)
        del tmp[0]
        myList = list(self.convertVoirToBinary())
        xor = list(self.buildXor())
        save = 0
        case = 1
        tmpSave = 0
        h = 0
        for p in myList:
            del p[0]
        for i in myList:
            j = 0
            for k in i: # k is myList[i]
                if (tmp[j] > 0):
                    if (k > 0):
                        xor[j] = 1
                    else:
                        xor[j] = 0
                else:
                    xor[j] = 0
                j += 1
            h+=1
            tmpSave = xor.count(1)
            if (tmpSave > save):
                save = tmpSave
                case = h
        return case

    def checkSurvival(self):
        try:
            save = 0
            survivalBool = False
            if (self.food < 3):
                survivalBool = True
                print('I\'m in survival mode')
                i = 0
                for p in self.inFrontOfMe:
                    if ('nourriture' in p):
                        save = i
                i+=1
            if ((save == 0 and survivalBool == False) or self.whereState == False):
                save = random.randint(1, 81)
            x, y = self.move.getMovements(save)
            self.moveAI(x, y)
            self.cc.prend_cmd(self.s, self.p, self.mess, 'nourriture')
        except:
            if ((save == 0 and survivalBool == False) or self.whereState == False):
                save = random.randint(1, 81)
            x, y = self.move.getMovements(save)
            self.moveAI(x, y)
            self.cc.prend_cmd(self.s, self.p, self.mess, 'nourriture')

    def checkNeedMode(self):
        if (self.linemate >= self.itemsNeeded[1]):
            if (self.deraumere >= self.itemsNeeded[2]):
                if (self.sibur >= self.itemsNeeded[3]):
                    if (self.mendiane >= self.itemsNeeded[4]):
                        if (self.phiras >= self.itemsNeeded[5]):
                            if (self.thystame >= self.itemsNeeded[6]):
                                if (self.getLevel() > 1):
                                    if (self.hasTarget == False):
                                        self.cc.broadcast_cmd(self.s, self.p, self.mess, \
                                                              self.buildMessageForBroadcast())
                                else:
                                    print('je peux incanter')
                                    self.dropRocks()
                                    if (self.cc.incantation_cmd(self.s, self.p, self.mess) != 1):
                                        self.takeEvery()


    def takeEvery(self):
        while 1:
            voir = self.cc.voir_cmd(self.s, self.p, self.mess)
            if (voir != -1):
                tmp = voir[0]
                break
        tmp.strip()
        tab = tmp.split(' ')
        for i in tab:
            if (i != 'joueur' and i != '' and i != 'nourriture'):
                while (1):
                    if (self.cc.prend_cmd(self.s, self.p, self.mess, i) == 0):
                        break

    def dropRocks(self):
        self.takeEvery()
        tmp = list(self.itemsNeededStill)
        del tmp[0]
        while (tmp[0] > 0):
            if (self.cc.pose_cmd(self.s, self.p, self.mess, 'linemate') == 1):
                tmp[0] -= 1
        while (tmp[1] > 0):
            if (self.cc.pose_cmd(self.s, self.p, self.mess, 'deraumere') == 1):
                tmp[1] -= 1
        while (tmp[2] > 0):
            if (self.cc.pose_cmd(self.s, self.p, self.mess, 'sibur') == 1):
                tmp[2] -= 1
        while (tmp[3] > 0):
            if (self.cc.pose_cmd(self.s, self.p, self.mess, 'mendiane') == 1):
                tmp[3] -= 1
        while (tmp[4] > 0):
            if (self.cc.pose_cmd(self.s, self.p, self.mess, 'phiras') == 1):
                tmp[4] -= 1
        while (tmp[5] > 0):
            if (self.cc.pose_cmd(self.s, self.p, self.mess, 'thystame') == 1):
                tmp[5] -= 1

    def changeItemsNeed(self):
        self.itemsNeeded[1] -= self.linemate
        self.itemsNeeded[2] -= self.deraumere
        self.itemsNeeded[3] -= self.sibur
        self.itemsNeeded[4] -= self.mendiane
        self.itemsNeeded[5] -= self.phiras
        self.itemsNeeded[6] -= self.thystame

    def takeRocks(self):
        tmp = list(self.itemsNeeded)
        del tmp[0]
        j = 0
        for i in tmp:
            while i > 0:
                self.cc.prend_cmd(self.s, self.p, self.mess, self.rocksTab[j])
                i -= 1
            j += 1

    def run(self):
        i = 1
        while (i == 1):
            while 1:
                if (self.cc.inventaire_cmd(self.s, self.p, self.mess) != -1):
                    break
            self.linemate = self.cc.getLinemate()
            self.deraumere = self.cc.getDeraumere()
            self.sibur = self.cc.getSibur()
            self.mendiane = self.cc.getMendiane()
            self.phiras = self.cc.getPhiras()
            self.thystame = self.cc.getThystame()
            self.food = self.cc.getFood()
            print('i got : ', self.linemate, ' linemate ', self.deraumere, 'deraumere', \
                  self.sibur, ' sibur ', self.mendiane, ' mendiane ', self.phiras, ' phiras', \
                  self.thystame, ' thystame ', self.food, ' food')
            while 1:
                self.inFrontOfMe = self.cc.voir_cmd(self.s, self.p, self.mess)
                if (self.inFrontOfMe != -1):
                    break
            self.itemsNeeded = self.defineWhatWeNeedMost()
            self.itemsNeededStill = self.defineWhatWeNeedMost()
            self.checkSurvival()
            self.changeItemsNeed()
            self.checkNeedMode()
            if (self.whereState == False and self.moveState == False):
                x, y = self.move.getMovements(self.checkBestCase())
            self.takeRocks()
            if (self.getLevel() > 1):
                self.parseBroadCastMessage()
            print('Current Level : ', self.getLevel())
            # if (self.needState):
            #     while (1):
            #         self.cc.incantation_cmd(self.s, self.p, self.mess)
            # self.cc.inventaire_cmd(self.s, self.p, self.mess)
            # self.linemate = self.cc.getLinemate()
            # self.deraumere = self.cc.getDeraumere()
            # self.sibur = self.cc.getSibur()
            # self.mendiane = self.cc.getMendiane()
            # self.phiras = self.cc.getPhiras()
            # self.thystame = self.cc.getThystame()
            # self.inFrontOfMe = self.cc.voir_cmd(self.s, self.p, self.mess)
            # self.playerNeeded, self.linemateNeeded, self.deraumereNeeded, self.siburNeeded, \
            #     self.mendianeNeeded, self.phirasNeeded, self.thystameNeeded, \
            #     self.itemsNeeded = self.defineWhatWeNeedMost()
            # self.cc.inventaire_cmd(self.s, self.p, self.mess)
            # self.food = self.cc.getFood()
            # if (self.food > 5):
            #     self.cc.pose_cmd(self.s, self.p, self.mess, 'linemate')
            #     self.cc.pose_cmd(self.s, self.p, self.mess, 'phiras')
            #     self.cc.pose_cmd(self.s, self.p, self.mess, 'deraumere')
            #     self.cc.pose_cmd(self.s, self.p, self.mess, 'thystame')
            #     self.cc.pose_cmd(self.s, self.p, self.mess, 'sibur')
            #     self.cc.pose_cmd(self.s, self.p, self.mess, 'mendiane')
            #     incant = self.cc.incantation_cmd(self.s, self.p, self.mess)
            #     if (incant == 1):
            #         continue
            #     else:
            #         self.cc.prend_cmd(self.s, self.p, self.mess, 'nourriture')
            #         self.cc.prend_cmd(self.s, self.p, self.mess, 'linemate')
            #         self.cc.prend_cmd(self.s, self.p, self.mess, 'phiras')
            #         self.cc.prend_cmd(self.s, self.p, self.mess, 'deraumere')
            #         self.cc.prend_cmd(self.s, self.p, self.mess, 'thystame')
            #         self.cc.prend_cmd(self.s, self.p, self.mess, 'sibur')
            #         self.cc.prend_cmd(self.s, self.p, self.mess, 'mendiane')
            # self.cc.avance_cmd(self.s, self.p, self.mess)
            # self.parseBroadCastMessage()
            # self.cc.broadcast_cmd(self.s, self.p, self.mess, self.buildMessageForBroadcast())
            # self.cc.broadcast_cmd(self.s, self.p, self.mess, self.buildMessageWhere())

    def getNbPlayerRequired(self):
        nbPlayer = 1
        if (self.getLevel() <= 2):
            nbPlayer = 1
        elif (self.getLevel() > 2 and self.getLevel() < 4):
            nbPlayer = 2
        elif (self.getLevel() > 4 and self.getLevel() < 6):
            nbPlayer = 4
        elif (self.getLevel() > 6):
            nbPlayer = 6
        case0 = self.inFrontOfMe[0]
        if (case0.count('joueur') >= nbPlayer):
            return 1
        else:
            return 0

    def moveAI(self, x, y):
        while (y > 0):
            if (self.cc.avance_cmd(self.s, self.p, self.mess) == 1):
                self.takeRocks()
                y -= 1
        if (x > 0):
            if (self.cc.droite_cmd(self.s, self.p, self.mess) == 1):
                while (x > 0):
                    if (self.cc.avance_cmd(self.s, self.p, self.mess) == 1):
                        self.takeRocks()
                        x -= 1
        elif (x < 0):
            if (self.cc.gauche_cmd(self.s, self.p, self.mess) == 1):
                self.takeRocks()
                while (x < 0):
                    if (self.cc.avance_cmd(self.s, self.p, self.mess) == 1):
                        self.takeRocks()
                        x += 1

    def getLevel(self) -> int:
        return int(self.cc.getLevel())

    def getBroadcastDirection(self, nb):
        if (nb == 1):
            self.cc.avance_cmd(self.s, self.p, self.mess);
        elif (nb == 2):
            self.cc.avance_cmd(self.s, self.p, self.mess)
            self.cc.gauche_cmd(self.s, self.p, self.mess)
            self.cc.avance_cmd(self.s, self.p, self.mess)
        elif (nb == 3):
            self.cc.gauche_cmd(self.s, self.p, self.mess)
            self.cc.avance_cmd(self.s, self.p, self.mess)
        elif (nb == 4):
            self.cc.gauche_cmd(self.s, self.p, self.mess)
            self.cc.avance_cmd(self.s, self.p, self.mess)
            self.cc.gauche_cmd(self.s, self.p, self.mess)
            self.cc.avance_cmd(self.s, self.p, self.mess)
        elif(nb == 5):
            self.cc.droite_cmd(self.s, self.p, self.mess)
            self.cc.droite_cmd(self.s, self.p, self.mess)
            self.cc.avance_cmd(self.s, self.p, self.mess)
        elif (nb == 6):
            self.cc.droite_cmd(self.s, self.p, self.mess)
            self.cc.droite_cmd(self.s, self.p, self.mess)
            self.cc.avance_cmd(self.s, self.p, self.mess)
            self.cc.gauche_cmd(self.s, self.p, self.mess)
            self.cc.avance_cmd(self.s, self.p, self.mess)
        elif(nb == 7):
            self.cc.droite_cmd(self.s, self.p, self.mess)
            self.cc.avance_cmd(self.s, self.p, self.mess)
        elif (nb == 8):
            self.cc.avance_cmd(self.s, self.p, self.mess)
            self.cc.droite_cmd(self.s, self.p, self.mess)
            self.cc.avance_cmd(self.s, self.p, self.mess)
