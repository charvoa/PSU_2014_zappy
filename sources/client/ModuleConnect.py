import socket

class ModuleConnect(object):

    """ Create connexion """
    def connect(self, host, port):
        s = socket.socket()
        s.connect((host, int(port)))
        return s
