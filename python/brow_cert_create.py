#!/usr/bin/python

'create CA cert '

import os
import sys
import pexpect

input=sys.argv[1]

CA_DIR     = "/home/regulus/pki/"
CA_KEY     = "/home/regulus/pki/private/koji_ca_cert.key"
CA_CRT     = "/home/regulus/pki/private/koji_ca_cert.crt"
CA_CONFIG  = "/home/regulus/pki/openssl.cnf"


child = pexpect.spawn('openssl req -new -x509 -days 3650 -key %s -out %s -extensions v3_ca -config %s '%(CA_KEY, CA_CRT, CA_CONFIG))

child.sendline ('\n')
child.sendline ('\n')
child.sendline ('\n')
child.sendline ('\n')
child.sendline ('\n')
child.sendline ('%s'%(input))
child.sendline ('\n')

print 'DONE'
