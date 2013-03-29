#!/bin/bash
export TOPDIR=/root/
export SRPM=$1
export DESTDIR=/home/kojiadmin/TASK/NS6.3-SRPMS
export BACKDIR=/home/kojiadmin/TASK/NS6.3-BACKS

mkdir -pv ${BACKDIR}
mkdir -pv ${DESTDIR}

if [ -d ${DESTDIR} ];then
	mkdir -pv ${DESTDIR}
fi


rm -rf ${TOPDIR}/rpmbuild/*

rpm -ivh ${SRPM}

rpmbuild -bs ${TOPDIR}/rpmbuild/SPECS/*.spec
mv ${TOPDIR}/rpmbuild/SRPMS/* ${DESTDIR}
mv ${SRPM} ${BACKDIR}

rm -rf ${TOPDIR}/rpmbuild/*
