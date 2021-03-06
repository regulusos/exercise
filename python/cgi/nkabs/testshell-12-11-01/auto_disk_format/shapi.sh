#!/bin/bash
############################################################################
#File: shapi.sh
#Description: The file provides the api of logging.
#Author: yan.fu@cs2c.com.cn
#Date:  2010/9/29
############################################################################


name=$0
name=${name%.*}
name=${name#*/}
echo $name

filename=    #Define the name of logging file.


#################################################################
#Function: start_log
#Description: Create dir and file
#Calls:
#Input:
#Output:
#################################################################
start_log()
{
	[ ! -d results ] && mkdir results
    filename=$1
	rm -rf ./results/$filename
    if [ -z $filename ]
	then
		echo "The logfilename is NULL."
	else :
	fi
	echo "testcasename			   results" | tee -a ./results/$filename
 }



#################################################################
#Function: start_log
#Description: Write information to the logging file.
#Calls:
#Input:
#Output:
#################################################################
 log_results_ok()
 {
#	 echo -e "$1 \033[1A\033[35C[\033[32m$2\033[0m]" | tee -a ./results/$filename
	echo -e "$1" | tee -a ./results/$filename
	echo -e "\033[1A\033[35C[\033[32m"$2"\033[0m]" | tee -a ./results/$filename
 }

 log_results_error()
 {

	echo -e "$1" | tee -a ./results/$filename
	echo -e "\033[1A\033[35C[\033[31m"$2"\033[0m]" | tee -a ./results/$filename
 }

 save_results()
 {
	 cp -r results $1
 }


