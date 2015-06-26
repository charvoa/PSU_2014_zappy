import random
import getopt
import sys
import re

class GetOptions(object):

    """ Get the arguments and get the value of the arguments """

    def __init__(self):
        self.verbose = False
        self.name = 'Team'
        self.name += str(random.randint(1,10))
        self.port = '4242'
        self.host = 'localhost'
        self.dbg = False

    def parseOpt(self):
        #print('ARGV :', sys.argv[1:])
        options, remainder = getopt.getopt(sys.argv[1:], 'n:p:h:v:d', ['name=',
                                                                       'port=',
                                                                       'host=',
                                                                       'verbose',
                                                                       'dbg'
                                                                   ])
        #print('OPTIONS :', options)
        for opt, arg in options:
            if opt in ('-n', '--name'):
                self.name = arg
            elif opt in ('-p', '--port'):
                self.port = arg
            elif opt in ('-h', '--host'):
                self.host = arg
            elif opt in ('-v', '--verbose'):
                self.verbose = True
            elif opt in ('-d', '--dbg'):
                self.dbg = True
        print('NAME :', self.name)
        print('PORT :', self.port)
        print('HOST :', self.host)
        print('VERBOSE :', self.verbose)
        print('DBG :', self.dbg)

    def getDbg(self) -> bool:
        return bool(self.dbg)
    def getName(self):
        return self.name
    def getPort(self):
        return self.port
    def getHost(self):
        return self.host
    def getVerbose(self):
        return self.verbose
