import time
import random
from CommandClass import *
import subprocess
from array import *

class IAClass():

    """ IAClass that handle the zappy's AI """

    def __init__(self):
        self.rocksTab = ['linemate', 'deraumere', 'sibur', 'mendiane', 'phiras',
                                    'thystame']
        self.linemate = 0
        self.deraumere = 0
        self.sibur = 0
        self.mendiane = 0
        self.phiras = 0
        self.thystame = 0
        self.inFrontOfMe = None
        self.cc = CommandClass()
        self.level = 1

    def defineWhatWeNeedMost(self):
        if (self.getLevel() == 1):
            print('Level 1 | Need : 1 Player, 1 Linemate, 0 Deraumere, 0 Sibur, 0 Mendiane, 0 Phiras, 0 Thystame')
        elif (self.getLevel() == 2):
            print('Level 2 | Need : 2 Player, 1 Linemate, 1 Deraumere, 1 Sibur, 0 Mendiane, 0 Phiras, 0 Thystame')
        elif (self.getLevel() == 3):
            print('Level 3 | Need : 2 Player, 2 Linemate, 0 Deraumere, 1 Sibur, 0 Mendiane, 2 Phiras, 0 Thystame')
        elif (self.getLevel() == 4):
            print('Level 4 | Need : 4 Player, 1 Linemate, 1 Deraumere, 2 Sibur, 0 Mendiane, 1 Phiras, 0 Thystame')
        elif(self.getLevel() == 5):
            print('Level 5 | Need : 4 Player, 1 Linemate, 2 Deraumere, 1 Sibur, 3 Mendiane, 0 Phiras, 0 Thystame')
        elif(self.getLevel() == 6):
            print('Level 6 | Need : 6 Player, 1 Linemate, 2 Deraumere, 3 Sibur, 0 Mendiane, 1 Phiras, 0 Thystame')
        elif(self.getLevel() == 7):
            print('Level 7 | Need : 6 Player, 2 Linemate, 2 Deraumere, 2 Sibur, 2 Mendiane, 2 Phiras, 1 Thystame')
        elif(self.getLevel() == 8):
            print('Level 8 | Max')

    def checkBestCase(self):
        if (self.inFrontOfMe):
            for p in self.inFrontOfMe:
                if 'nourriture' in p:
                    print('I see food ! ')
                for i in self.rocksTab:
                    if i in p:
                        print('I see ', i)

    def run(self, s, p, mess):
        while 1:
            self.cc.voir_cmd(s, p, mess)
            self.cc.inventaire_cmd(s, p, mess)
            self.linemate = self.cc.getLinemate()
            self.deraumere = self.cc.getDeraumere()
            self.sibur = self.cc.getSibur()
            self.mendiane = self.cc.getMendiane()
            self.phiras = self.cc.getPhiras()
            self.thystame = self.cc.getThystame()
            self.food = self.cc.getFood()
            self.inFrontOfMe = self.cc.voir_cmd(s, p, mess)
            rand = random.randint(1, 7)
            randTab = random.randint(0, 5)
            if (rand == 1):
                self.cc.gauche_cmd(s, p, mess)
            elif (rand == 2):
                self.cc.droite_cmd(s, p, mess)
            elif (rand == 3):
                self.cc.prend_cmd(s, p, mess, 'nourriture')
            elif (rand == 5):
                if (self.cc.incantation_cmd(s, p, mess) == 1):
                    self.level += 1
            else:
                self.cc.prend_cmd(s, p, mess, self.rocksTab[randTab])
                self.cc.avance_cmd(s, p, mess)
            print('Current Level : ', self.getLevel())
            self.defineWhatWeNeedMost()

    def getLevel(self) -> int:
        return int(self.level)
