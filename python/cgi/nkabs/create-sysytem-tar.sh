#!/bin/bash

export TAEGET=$1
export RESULT=$2/nk6-mips-64.tar.gz

check_is_root()
{
if [ "$UID" == "0" ]
then
	echo "";
else
  echo "必需以管理员权限运行程序！"
  sleep 1 && exit 1
fi
}


clean_var_log()
{

local TARGET=$1

for LOG_FILE in `find ${TAEGET}/var/log/ -type f` 
do
    echo "$LOG_FILE 文件将被清空"
    echo "" > $LOG_FILE
done
}


clean_tmp()
{

local TARGET=$1
rm -rvf ${TARGET}/tmp/*

}

clean_net_info()
{

local TARGET="$1"
echo "" > ${TARGET}etc/udev/rules.d/70-persistent-net.rules

}

clean_vnc_info()
{

local TARGET="$1"
rm -rf  ${TARGET}/root/.vnc*

}

clean_ssh_info()
{

local TARGET="$1"
rm -rf  ${TARGET}/root/.ssh*
}

create_tar()
{

local TARGET="$1"
[ -f $RESULT ] && rm -f $RESULT && echo "$RESULT 已经被删除 "
cd $TAEGET  
time tar --numeric-owner -czplf  $RESULT *
[ "$?" -eq "0" ] && echo "$RESULT 制作完毕" || echo "$RESULT 制作失败"
}


start_work()
{

clean_net_info $TAEGET
clean_ssh_info $TAEGET
clean_var_log $TAEGET
clean_tmp $TAEGET   

create_tar $TAEGET
}


check_is_root && 

case "$TAEGET" in
	-h)	echo "使用方法：命令 源路径 目标路径"
		;;

	-v)	echo "create-sysytem-tar.sh 0.01版"
		;;

	* ) echo "开始创建系统镜像文件"
		start_work
		;;
esac	
	





