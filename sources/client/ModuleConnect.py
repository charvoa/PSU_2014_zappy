import socket

class ModuleConnect():

    """ Create connexion """

    def connect(self, port):
        s = socket.socket()
        host = socket.gethostname()
        port = port
        s.connect((host, port))
        return s
