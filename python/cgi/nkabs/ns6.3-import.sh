#!/bin/bash
koji import `find /mnt/koji/work/tasks |grep "\.rpm$" | grep "\.ns6\.3" | grep -v "ns6\.0" | grep -v nk6.3-rawhide` 
koji list-untagged | grep ns6.3 | xargs -n 1 koji call tagBuildBypass ns6.3  
koji regen-repo ns6.3-build &>/dev/null &

