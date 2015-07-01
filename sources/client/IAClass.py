import time
import random
import subprocess
import string
import re
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
        self.rocksTab = ['linemate', 'deraumere', 'sibur', 'mendiane', 'phiras',
                                    'thystame']
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
        self.rows = 4
        chars = string.ascii_uppercase + string.digits
        self.uid = ''.join(random.choice(chars) for _ in range(6))
        self.targets = [] # TABLEAU DE TARGETS POUR LA PARTIE A
        self.target = ""   # FOCUS TARGET POUR LA PARTIE B
        self.hasTarget = False
        self.needState = False
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

    def whereisIaTarget(self): #S'occupe d'envoyer WHERE.
        string = 'WHERE '
        string += str(self.uid)

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
        if (senderId == self.target):
            if (case == 0):
                self.needState = True
            self.getBroadcastDirection(case)
            self.cc.broadcast_cmd(self.s, self.p, self.mess, self.buildMessageWhere())

    def parseBroadCastMessage(self):
        mess = self.cc.getMessage()
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
        else:
            print('coucou')

    def sendNeedOk(self, nbPlayer, levelPlayer, senderId):
        if (self.target == ""):
            self.target = senderId;
        if (self.getLevel() == int(levelPlayer) and self.target == senderId):
            self.cc.broadcast_cmd(self.s, self.p, self.mess, self.buildOkMessage(senderId))

    def receiveNeedOk(self, senderId):
        self.hasTarget = True
        self.targets.append(senderId)
        if (len(self.targets) >= self.getNbPlayerRequired()):
            self.hasTarget = True

    def defineWhatWeNeedMost(self):
        if (self.getLevel() == 1):
            return 1, 1, 0, 0, 0, 0, 0, [1, 1, 0, 0, 0, 0, 0]
        elif (self.getLevel() == 2):
            return 2, 1, 1, 1, 0, 0, 0, [2, 1, 1, 1, 0, 0, 0]
        elif (self.getLevel() == 3):
            return 2, 2, 0, 1, 0, 2, 0, [2, 2, 0, 1, 0, 2, 0]
        elif (self.getLevel() == 4):
            return 4, 1, 1, 2, 0, 1, 0, [4, 1, 1, 2, 0, 1, 0]
        elif(self.getLevel() == 5):
            return 4, 1, 2, 1, 3, 0, 0, [4, 1, 2, 1, 3, 0, 0]
        elif(self.getLevel() == 6):
            return 6, 1, 2, 3, 0, 1, 0, [6, 1, 2, 3, 0, 1, 0]
        elif(self.getLevel() == 7):
            return 6, 2, 2, 2, 2, 2, 1, [6, 2, 2, 2, 2, 2, 1]
        elif(self.getLevel() == 8):
            return 0, 0, 0, 0, 0, 0, 0, [0, 0, 0, 0, 0, 0, 0]

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
        for p in self.inFrontOfMe:
            for i in range(self.rows):
                myList[i][0] = p.count('joueur')
                myList[i][1] = p.count('linemate')
                myList[i][2] = p.count('deraumere')
                myList[i][3] = p.count('sibur')
                myList[i][4] = p.count('mendiane')
                myList[i][5] = p.count('phiras')
                myList[i][6] = p.count('thystame')
        return myList

    def checkBestCase(self):
        best = 0
        save = 0
        bestCase = 0
        myList = self.convertVoirToBinary()
        for i in range(self.rows):
            best = 0
            for j in range(7):
                if (myList[i][j] >= self.itemsNeeded[j]):
                    best += 1
            if (best >= save):
                save = best
                bestCase = i
        return bestCase

    # def checkLevelUp(self):
    #     for p in self.itemsNeeded

    def run(self):
        i = 1
        while (i == 1):
            print('Current Level : ', self.getLevel())
            self.cc.avance_cmd(self.s, self.p, self.mess)
#            self.inFrontOfMe = self.cc.voir_cmd(self.s, self.p, self.mess)
#            self.itemsNeeded = self.defineWhatWeNeedMost()
#            x, y = self.move.getMovements(self.checkBestCase())
#            self.moveAI(x, y)
            # self.cc.inventaire_cmd(self.s, self.p, self.mess)
            # self.linemate = self.cc.getLinemate()
            # self.deraumere = self.cc.getDeraumere()
            # self.sibur = self.cc.getSibur()
            # self.mendiane = self.cc.getMendiane()
            # self.phiras = self.cc.getPhiras()
            # self.thystame = self.cc.getThystame()
            # self.food = self.cc.getFood()
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
            # self.food = self.cc.getFood()
            # self.inFrontOfMe = self.cc.voir_cmd(self.s, self.p, self.mess)
            # self.cc.prend_cmd(self.s, self.p, self.mess, 'nourriture')
            # self.cc.prend_cmd(self.s, self.p, self.mess, 'linemate')
            # self.cc.prend_cmd(self.s, self.p, self.mess, 'phiras')
            # self.cc.prend_cmd(self.s, self.p, self.mess, 'deraumere')
            # self.cc.prend_cmd(self.s, self.p, self.mess, 'thystame')
            # self.cc.prend_cmd(self.s, self.p, self.mess, 'sibur')
            # self.cc.prend_cmd(self.s, self.p, self.mess, 'mendiane')
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
                y -= 1
        if (x > 0):
            if (self.cc.droite_cmd(self.s, self.p, self.mess) == 1):
                while (x > 0):
                    if (self.cc.avance_cmd(self.s, self.p, self.mess) == 1):
                        x -= 1
        elif (x < 0):
            if (self.cc.gauche_cmd(self.s, self.p, self.mess) == 1):
                while (x < 0):
                    if (self.cc.avance_cmd(self.s, self.p, self.mess) == 1):
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
