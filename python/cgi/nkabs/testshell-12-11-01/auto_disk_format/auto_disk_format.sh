#! /bin/sh 
F=""               
FILE=""   
MOUNTFILE="df.temp.txt"                
TESTFILE=test
CURRENTDIR=""
function testFdisk_format()
{
	#F=`fdisk -l | tail -1 | cut -d/ -f3 | awk '{print $1}'`
	FILE=/mnt/$2
	#echo "$2"
	#umount /dev/$F
	case "$1" in
	ext2 | ext3 | ext4 | vfat | ntfs | ext4dev | msdos | btrfs)
		diskstatus=$( mkfs -t $1 /dev/$2 )
		if [[ "$diskstatus" = "" ]]
		then
			return 1
		fi
		;;
	xfs)
			
		diskstatus=$( mkfs -t $1 -f /dev/$2 )
		if [[ "$diskstatus" = "" ]]
		then
			return 1
		fi
		;;
	cramfs)
		diskstatus=$( mkfs -t $1 /tmp /dev/$2 )
		if [ $? != 0 ]
		then
			return 1
		fi
		;;
	jfs | reiserfs)
diskstatus=$( mkfs -t $1 /dev/$2 << end
y 
end )
		if [[ "$diskstatus" = "" ]]
		then
			return 1
		fi
		;;
	gfs2)
diskstatus=$( mkfs.gfs2 -t mycluster:data1 -j 5 -p lock_nolock /dev/$2 << end
y 
end )

		if [[ "$diskstatus" = "" ]]
		then
			return 1
		fi
		;;
	bbb)
		;;
	esac	
	mkdir $FILE
	mount /dev/$F $FILE
	CURRENTDIR=`pwd`
	cd $FILE
	touch $TESTFILE
	#echo "test read and write in new create filesystem" >> $TESTFILE
	cat $TESTFILE
	rm -rf $TESTFILE
	cd $CURRENTDIR
	umount $FILE
	rm -rf $FILE
	#echo "/dev/$2              $FILE                 $1    defaults        0 0"
}
###判断参数
        if [ $1 ]
        then
                filetypeList=$1
        else
                echo "Usage: autofdisk_format.sh config_file"
                exit
        fi
	df > $MOUNTFILE
	F=`fdisk -l | tail -1 | cut -d/ -f3 | awk '{print $1}'`
	mountpoint="/dev/$F"
while read serItem
do
	mountnode=`echo -e "$serItem" | awk '{print $1}' `
	if [ $mountnode = $mountpoint ]
	then
		umount $mountpoint
	fi
done <$MOUNTFILE
	rm -rf $MOUNTFILE
while read serItem
do
	fileType=`echo -e "$serItem" | awk -F'\t' '{print $1}' `
	testFdisk_format $fileType $F
	ret=$?
	echo ""
	case "$ret" in
	0)
		echo -e "\033[1A\033[35C[\033[32m$fileType format success!\033[0m]"
		;;
	1)
		echo -e "\033[1A\033[35C[\033[31m$fileType format fail!\033[0m]"
		;;
	esac
done <$filetypeList
