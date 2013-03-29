#!/bin/bash
####################################################################
#Filename: run_fstest.sh
#Description: Create a file,than Formated it into a \
# specialed filesystem format,and do the operations on it such as 
# read,write.
#Author: yan.fu
#Date: 2012/09/25
#####################################################################

create_file()
{
#	avail_space=`df	| sed -n '2p' | awk '{print $4}'`
#	if [ $((avail_space/1024/1024)) \< 1 ]
#	then
#		echo "The test needs 1G available space."
#		exit 1
#	else :
#	fi

	dd if=/dev/zero of=/tmp/fstest bs=100M count=1
	if [ $? != 0 ]
	then
		echo "create file failed."
		exit 1
	else :
	fi
}




test_filesystem()
{
Type=$1
cd /
umount /mnt 1>/dev/null 2>&1
if [ $Type = "xfs" ]
then
        mkfs.xfs -f /tmp/fstest
else if [ $Type = "ntfs" ]
then
	mkfs.ntfs -F /tmp/fstest
else 
mkfs.$Type /tmp/fstest << EOF
y
EOF
fi
fi
if [ $? != 0 ]
then
	return 1
fi
sleep 5
mount -o loop /tmp/fstest /mnt
if [ $? != 0 ]
then
	return 1
fi
cd - 1>/dev/null 2>&1
mkdir /mnt/testdir
teststr="test for filesystem"
echo "$teststr" >> /mnt/testdir/testfile
cp /mnt/testdir/testfile /tmp/testfile
cd / ; umount /mnt
cd - 1>/dev/null 2>&1
getstr=`cat /tmp/testfile`
if [ "$teststr" != "$getstr" ]
then
	echo "Copy file from filesystem $Type failed."
	exit 1
else :
fi
rm -rf /tmp/testfile
rm -rf /tmp/fstest	
}

rm -rf /mnt/testdir
create_file
test_filesystem $1
