import time
from CommandClass import *

class IAClass():

    """ IAClass that handle the zappy's AI """

    def __init__(self):
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
