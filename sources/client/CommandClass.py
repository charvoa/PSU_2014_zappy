class CommandClass():

    """ A class that send command to the server """

    def avance_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('avance >>')
        var = 'avance'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == 'OK'):
            return 1
        else:
            return 0

    def droite_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('droite >> ')
        var = 'droite'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == 'OK'):
            return 1
        else:
            return 0

    def gauche_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('gauche >>')
        var = 'gauche'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == 'OK'):
            return 1
        else:
            return 0

    def voir_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('voir >>')
        var = 'voir'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        voir_list = []
        voir_list = [string(x) for x in rec.split(', ')]
        for p in voir_list:
            print(p)

    def inventaire_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('inventaire >>')
        var = 'inventaire'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        inventaire_list = []
        inventaire_list = [string(x) for x in rec.split(', ')]
        for p in inventaire_list:
            print(p)

    def prend_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('prend >>')
        var = 'pose'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == 'OK'):
            return 1
        else:
            return 0

    def pose_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('pose >>')
        var = 'pose'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == 'OK'):
            return 1
        else:
            return 0

    def expulse_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('expulse >>')
        var = 'expulse'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == 'OK'):
            return 1
        else:
            return 0

    def broadcast_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('broadcast >>')
        var = 'broadcast'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == 'OK'):
            return 1
        else:
            return 0

    def incantation_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('incantation >>')
        var = 'incantation'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == 'OK'):
            return 1
        else:
            return 0

    def fork_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('fork >>')
        var = 'fork'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == 'OK'):
            return 1
        else:
            return 0

    def connect_nbr_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('connect_nbr >>')
        var = 'connect_nbr'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == 'OK'):
            return 1
        else:
            return 0

    def mort_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('mort >>')
        var = '-'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == 'OK'):
            return 1
        else:
            return 0
