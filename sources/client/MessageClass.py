class MessageClass(object):

    """ A Simple class that send and receive messages"""

    def sendMessage(self, s, var):
        s.send(var.encode())

    def getMessage(self):
        signal.signal(signal.SIGINT, signal_handler)
        return input('$> ')

    def readMessage(self, s) -> str:
        received = s.recv(1024)
        return received

