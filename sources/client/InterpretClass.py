class InterpretClass():

    """ A class that interpret messages received """

    x = 0
    y = 0
    nbr_client = 0

    def interpret_bienvenue(self, s, rec, p):
        if (p.getVerbose()):
            print('bienvenue: ', rec)
        if (rec == 'BIENVENUE\n'):
            return 1
        return 0

    def interpret_num_client(self, s, rec, p):
        try:
            if (p.getVerbose()):
                print('num_client : ', rec)
            if (rec == 'ko\n'):
                return -1
            nbr_client = int(rec)
        except ValueError:
            print('Wrong value sent by the server')
            sys.exit(0)

    def interpret_size(self, s, rec, p):
        if (p.getVerbose()):
            print('size:', rec)
        self.x, self.y = rec.split(' ')
        if (p.getVerbose()):
            print('X : ', self.x)
            print('Y : ', self.y)
