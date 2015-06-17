import socket

class ModuleConnect(object):

    """ Create connexion """
    def connect(self, host, port):
            self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.s.connect((host, int(port)))
            return self.s
