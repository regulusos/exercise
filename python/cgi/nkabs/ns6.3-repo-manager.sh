#!/bin/bash

unalias mv
unalias cp

cp -v `find /mnt/koji/work/tasks |grep "\.rpm$" | grep "\.ns6\.3" | grep -v nk6.3-rawhide | grep -v nk6.0` /home/kojiadmin/TASK/NS6.3-BUILDED/
cd /home/kojiadmin/TASK/NS6.3-BUILDED/
mv -v `ls | grep "src\.rpm$"` /home/kojiadmin/TASK/NS6.3-BUILDED/SRPMS  
mv -v `ls | grep "\.rpm$"` /home/kojiadmin/TASK/NS6.3-BUILDED/RPMS

cd /home/kojiadmin/TASK/NS6.3-BUILDED/SRPMS 
rpm -qpa *.rpm --queryformat "%{NAME}-%{VERSION}\n" > /home/kojiadmin/TASK/list

cd /home/kojiadmin/TASK/NS6.3-SRPMS/
while read file; do ls | grep "^$file" >> /home/kojiadmin/TASK/list-builded; done < /home/kojiadmin/TASK/list
mv -v `cat /home/kojiadmin/TASK/list-builded` /home/kojiadmin/TASK/NS6.3-RHEL-PATHED
