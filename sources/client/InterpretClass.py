import sys

class InterpretClass():

    """ A class that interpret messages received """

    def __init__(self):
        self.x = 0
        self.y = 0
        self.nbr_client = 0

    def interpret_bienvenue(self, s, rec, p):
        if (p.getVerbose()):
            print("bienvenue")
            print(rec)
        if ("BIENVENUE" in rec):
            return 1
        return 0

    def interpret_num_client(self, s, rec, p):
        try:
            if (p.getVerbose()):
                print("num client :")
                print(rec)
            if ('ko' in rec):
                return -1
            nbr_client = int(rec)
        except ValueError:
            print('Wrong value sent by the server')
            sys.exit(0)

    def interpret_size(self, s, rec, p):
        if (p.getVerbose()):
            print("size >>")
            print(rec)
        self.x, self.y = rec.split(' ')
        if (p.getVerbose()):
            print('X : ', self.x)
            print('Y : ', self.y)
