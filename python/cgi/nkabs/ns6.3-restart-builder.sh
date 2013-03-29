#!/bin/bash
umount /mnt/koji
mount -t nfs -o nolock 10.1.81.90:/mnt/koji /mnt/koji
service sshd restart
service kojid restart
service kojira restart 
