import sys

class MessageClass(object):

    """ A Simple class that send and receive messages"""

    def sendMessage(self, s, var):
        s.send(var.encode())

    def getMessage(self):
        signal.signal(signal.SIGINT, signal_handler)
        return input('$> ')

    def readMessage(self, s) -> str:
        data = ""
        while 1:
            packet = s.recv(4096)
            if not packet:
                print('Error occured')
                sys.exit(0)
            data += packet.decode("utf-8")
            if '\n' in data:
                break
            if chr(4) or chr(26):
                break
        return data

