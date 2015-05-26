class CommandClass():

    """ A class that send command to the server """

    def avance_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('avance')
        var = 'avance'
        var += '\n'
        mess.sendMessage(s, var)

    def droite_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('droite')
        var = 'droite'
        var += '\n'
        mess.sendMessage(s, var)

    def gauche_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('gauche')
        var = 'gauche'
        var += '\n'
        mess.sendMessage(s, var)

    def voir_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('voir')
        var = 'voir'
        var += '\n'
        mess.sendMessage(s, var)

    def inventaire_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('inventaire')
        var = 'inventaire'
        var += '\n'
        mess.sendMessage(s, var)

    def mort_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print('mort')
        var = '-'
        var += '\n'
        mess.sendMessage(s, var)
