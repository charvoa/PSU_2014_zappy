class MessageClass(object):

    """ A Simple class that send and receive messages"""

    def sendMessage(self, s, var):
        var += '\r\n'
        s.send(var.encode())

    def getMessage(self):
        signal.signal(signal.SIGINT, signal_handler)
        return input('$> ')

    def readMessage(self, s) -> str:
        received = s.recv(1024)
        received = received.decode("utf-8")
        return received

