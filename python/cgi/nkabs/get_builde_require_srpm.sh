#!/bin/bash

#export SRC=$1;
#export TMP=/tmp/$(date +'%d%H%M%S')
#
#rpm -i --nodeps ${SRC} -D "_topdir ${TMP}"  &>/dev/null  
#
#
#for file in `cat ${TMP}/SPECS/*.spec |grep BuildRequires | awk -F: '{print $2} ' | sed 's/,//g' | sed 's@>=@@g'| sed '/#/d'`
#do
#	echo $file 
#	for src_file in `ls *.rpm | grep -v src.rpm | grep "^$file" | sort | uniq`
#		do
#			rpm -qpa $src_file --queryformat "%{SOURCERPM}\n"  | grep "src.rpm" >> ${TMP}/$1-list  
#		done
#done
#cat  ${TMP}/$1-list | sort | uniq
#rm -rf ${TMP}
#
# get_srpm_depend函数用查询一个SRPM的编译依赖对应的所有SRPM包，
#
#  参数1: path/pakage.src.rpm
#  参数2: SHELL数组


#shopt -s -o nounset

SRPMS=$1
#declare S_DEP=""


function get_srpm_depend()
{

	
	local i=0;
	local SRC=$1;
	local SRC_DEPAND=""
	local TMP=/tmp/$(date +'%d%H%M%S')

	for file in `rpm -qpR ${SRC} | sed 's/,//g' | sed 's@>=@@g'| sed '/#/d'`
	do
		for src_file in `ls *.rpm | grep -v src.rpm | grep "^$file" | sort | uniq`
		do
			rpm -qpa $src_file --queryformat "%{SOURCERPM}\n"  | grep "src.rpm" >> ${TMP}/$1-list-tmp  
		done
	done

cat  ${TMP}/$1-list-tmp | sort | uniq > ${TMP}/$1-list

echo "################################################"
while read src_dep 
do
	SRC_DEPAND[i]=$src_dep
	echo $src_dep >> $HOME/log
	let i++;
done < ${TMP}/$1-list


for j in `echo ${SRC_DEPAND[*]}`
do
	if [ $j -qe "" ];then
		break;
	else
		get_srpm_depend $j
	fi
done
	
rm -rf ${TMP}

	 
}

srpm=$1


#while getopts p opt
#do
#	case $opt in
#	p]
#		get_srpm_depend $SRPMS && echo ${S_DEP[@]} 
#	*)
#		echo "重新输入"
#done
	 
get_srpm_depend $SRPMS

