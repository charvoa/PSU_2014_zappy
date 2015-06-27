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
        self.inFrontOfMe = 0
        self.cc = CommandClass()
        self.level = 1

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

    def getLevel(self) -> int:
        return int(self.level)
