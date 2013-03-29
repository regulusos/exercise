#!/bin/bash
i=0
j=0
rm file_a.list
rm common.list

while read soft_a
do  
	r=$((i++))
	FILE_A[r]=$soft_a
done < $1 

while read soft_b
do  
	r=$((j++))
	FILE_B[r]=$soft_b
done < $2

for file_a in `echo ${FILE_A[@]}`
	do
		echo ${FILE_B[@]} | grep  $file_a 
		if [ $? == 0 ]; then
			echo $file_a >> common.list
		else
			echo $file_a >> file_a.list
		fi
	done	
			 

 

