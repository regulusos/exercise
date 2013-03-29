#!/bin/bash
############################################################################
#File: fs_test.sh
#Description: This program calls the program of fs_test.sh.
#Author: yan.fu@cs2c.com.cn
#Date:  2011/01/11
############################################################################
usage()
{
cat <<-EOF >&2
usage: ./${0##*/} [-t FilesystemType] [-l logFileName]
EOF
exit 0
} 
run_test()
{
    TYPE=$1
   # . shapi.sh
    echo "Type is $TYPE"
    [ ! -d results ] && mkdir results
#    resFileName=`date +%y%m%d_%H:%M:%S.${0##*/}.res`
    (./run_fstest.sh $TYPE; echo $? >tmpfile.$$) 2>&1 | tee results/$resFileName
    res=$(cat tmpfile.$$)
    echo $res
    if [ "$res" -eq "0" ]
    then
        log_results_ok $TYPE PASS
    else
        log_results_error $TYPE FAIL
    fi
    rm -rf tmpfile.$$
}

#logFileName=`date +%y%m%d_%H:%M:%S.${0##*/}.log`
logFileName='fsresult'
resFileName=`date +%y%m%d_%H:%M:%S.${0##*/}.res`
. shapi.sh
start_log $logFileName
if [ ! -s 'test.cfg' ]
then
	exit
else :
fi
 
while read TYPE
do
	run_test $TYPE
done < test.cfg
 

