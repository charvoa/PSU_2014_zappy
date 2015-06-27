import random
import getopt
import sys
import re

class GetOptions(object):

    """ Get the arguments and get the value of the arguments """

    def __init__(self):
        self.name = 'Team'
        self.name += str(random.randint(1,10))
        self.port = '4242'
        self.host = 'localhost'
        self.verbose = False
        self.dbg = False


    def usage(self):
        print(sys.argv[0], '[-n [TEAM NAME]] [-h [HOST]] [-p [PORT]] [[-v, --verbose], [-d, --dbg]]')

    def parseOpt(self):
        #print('ARGV :', sys.argv[1:])
        try:
            opts, args = getopt.getopt(sys.argv[1:], "n:p:h:vd", ["name=", "port=", "host="
                                                                , "verbose", "dbg"])
        except getopt.GetoptError as err:
            # print help information and exit:
            print(str(err)) # will print something like "option -a not recognized"
            self.usage()
            sys.exit(2)
        for o, a in opts:
            if o in ("-v", "--verbose"):
                self.verbose = True
            elif o in ("-n", "--name"):
                self.name = a
            elif o in ("-p", "--port"):
                self.port = a
            elif o in ("-h", "--host"):
                self.host = a
            elif o in ("-d", "--dbg"):
                self.dbg = True
            else:
                assert False, "unhandled option"
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
