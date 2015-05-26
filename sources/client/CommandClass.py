class CommandClass():

    """ A class that send command to the server """

    def avance_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('avance')
        var = 'avance'
        var += '\n'
        mess.sendMessage(s, var)
        rec = mess.readMessage(s)
        if (rec == b'OK'):
            return 1
        else:
            return 0

    def droite_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('droite')
        var = 'droite'
        var += '\n'
        mess.sendMessage(s, var)
        if (rec == b'OK'):
            return 1
        else:
            return 0

    def gauche_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('gauche')
        var = 'gauche'
        var += '\n'
        mess.sendMessage(s, var)
        if (rec == b'OK'):
            return 1
        else:
            return 0

    def voir_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('voir')
        var = 'voir'
        var += '\n'
        mess.sendMessage(s, var)
        if (rec == b'OK'):
            return 1
        else:
            return 0

    def inventaire_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('inventaire')
        var = 'inventaire'
        var += '\n'
        mess.sendMessage(s, var)
        if (rec == b'OK'):
            return 1
        else:
            return 0

    def mort_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('mort')
        var = '-'
        var += '\n'
        mess.sendMessage(s, var)
