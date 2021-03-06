#!/bin/sh
ot@mips

LSJDK=$1
NKJDK=$2

LSDIR=/tmp/$$_LS
NKDIR=/tmp/$$_NK

rm -rf $LSDIR
rm -rf $NKDIR

mkdir -pv ${LSDIR}
mkdir -pv ${NKDIR}

mkdir -pv ${NKDIR}/usr/lib64/jvm/java-1.6.0-openjdk-1.6.0.0-mips64el
mkdir -pv ${NKDIR}/usr/share/



tar -xvpf ${LSJDK} -C ${LSDIR}
cd ${LSDIR}/j2sdk-image

mv demo ${NKDIR}/usr/share 
mv man ${NKDIR}/usr/share  
mv sample ${NKDIR}/usr/share

mv * ${NKDIR}/usr/lib64/jvm/java-1.6.0-openjdk-1.6.0.0-mips64el

cd ${NKDIR}

tar -czvpf ${HOME}/${NKJDK} *


  
 



