class InterpretClass():

    """ A class that interpret messages received """

    def interpret_bienvenue(self, s, rec, p):
        if (rec == b'BIENVENUE\r\n'):
            if (p.getVerbose):
                print(rec)
            return 1

    def interpret_num_client(self, s, rec, p):
        print('NUMBER OF CLIENT')

    def interpret_size(self, s, rec, p):
        print('SIZE')
