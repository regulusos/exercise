#!/bin/bash

cd /home/kojiadmin/TASK/NS6.3-SRPMS
ls *.src.rpm | xargs -n 1 koji build ns6.3 &>/dev/null &
