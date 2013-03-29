#!/bin/bash

unalias mv
unalias cp

export RPMS-NV = "/root/neokylin-core-daylay-build/core.list"
export RPMS-LIST = "/root/neokylin-core-daylay-build/core-full.list"

cd /home/kojiadmin/TASK/RPMS-BUILD/RPMS

while read file; do ls | grep "^$file" >> ${RPMS-LIST}; done < ${RPMS-NV}

cp -v `cat ${RPMS-LIST} ` /root/neokylin-core-daylay-build/Packages/

cd /root/neokylin-core-daylay-build/

createrepo -g 
