class InterpretClass():

    """ A class that interpret messages received """

    x = 0
    y = 0
    nbr_client = 0

    def interpret_bienvenue(self, s, rec, p):
        if (rec == b'BIENVENUE\r\n'):
            if (p.getVerbose()):
                print(rec)
            return 1
        return 0

    def interpret_num_client(self, s, rec, p):
        if (p.getVerbose()):
            print(rec)
        nbr_client = int(rec)

    def interpret_size(self, s, rec, p):
        if (p.getVerbose()):
            print(rec)
        self.x, self.y = rec.split(' - ')

