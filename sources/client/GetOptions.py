import getopt
import sys

class GetOptions(object):
    
    verbose = False
    name = ''
    port = '4242'
    host = 'localhost'

    def parse_opt(self):
        
        #print('ARGV :', sys.argv[1:])
        options, remainder = getopt.getopt(sys.argv[1:], 'n:p:h:v', ['name=',
                                                                     'port=',
                                                                     'host=',
                                                                     'verbose'
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
        print('NAME :', self.name)
        print('PORT :', self.port)
        print('HOST :', self.host)
        print('VERBOSE :', self.verbose)
        
    def getName(self):
        return self.name
    def getHost(self):
        return self.host
    def getVerbose(self):
        return self.verbose
