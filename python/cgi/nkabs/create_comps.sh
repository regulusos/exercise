#!/bin/bash
# 创建comps.xml
##########################################################################
cat > $1 <<COMPS_HEADER
<?xml version='1.0' encoding='UTF-8'?>
<!DOCTYPE comps PUBLIC "-//CS2C, Inc.//DTD Comps info//EN" "comps.dtd">
<comps>
	<group>
   		<id>base</id>
    	<name>Base</name>
    	<name xml:lang='zh_CN'>基本</name>
    	<description>The basic installation of NeoKylin Linux Server.</description>
    	<description xml:lang='zh_CN'>红帽企业版 Linux 基本安装。</description>
    	<default>true</default>
    	<uservisible>true</uservisible>
    	<packagelist>
COMPS_HEADER
##########################################################################
while  read pkg_name
do
cat >> $1 <<COMPS_LIST
<packagereq type='default'>$pkg_name</packagereq>
COMPS_LIST
done < $2
##########################################################################
cat >> $1 <<COMPS_END
	</packagelist>
</group>
COMPS_END
##########################################################################
#while  read ID
#do
#cat >> $1 <<COMPS_OTH
#<group>
#   	<id>$ID</id>
#    	<name>$ID<name>
#    	<name xml:lang='zh_CN'>基本</name>
#    	<description>The basic installation of NeoKylin Linux Server.</description>
#    	<description xml:lang='zh_CN'>红帽企业版 Linux 基本安装。</description>
#    	<default>true</default>
#    	<uservisible>true</uservisible>
#    	<packagelist>
#    	</packagelist>
#</group>
#COMPS_OTH
#done < $3
##########################################################################
cat >> $1 <<COMPS_END
</comps>
COMPS_END



