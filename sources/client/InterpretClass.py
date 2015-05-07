class InterpretClass():

    """ A class that interpret messages received """

    def interpret_bienvenue(self, s, rec):
        if (rec == b'BENVENUE\r\n'):
            if (p.getVerbose):
                print(rec)
            send_name_to_server(s)
    
    def interpret_num_client(self, s, rec):
        print('CLIENT')

    def interpret_pos(self, s, rec):
        print('POS')
