class CommandClass():

    """ A class that send command to the server """

    def avance_cmd(self, s, p, mess):
        if (p.getVerbose()):
            print(rec)
        var = 'avance'
        var += '\n'
        mess.sendMessage(s, var)
