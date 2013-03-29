1+0 records in
1+0 records out
1048576 bytes (1.0 MB) copied, 0.00155 seconds, 677 MB/s
agsize (256b) too small, need at least 4096 blocks
Usage: mkfs.xfs
/* blocksize */		[-b log=n|size=num]
/* data subvol */	[-d agcount=n,agsize=n,file,name=xxx,size=num,
			    (sunit=value,swidth=value|su=num,sw=num),
			    sectlog=n|sectsize=num,unwritten=0|1]
/* inode size */	[-i log=n|perblock=n|size=num,maxpct=n,attr=0|1|2]
/* log subvol */	[-l agnum=n,internal,size=num,logdev=xxx,version=n
			    sunit=value|su=num,sectlog=n|sectsize=num,
			    lazy-count=0|1]
/* label */		[-L label (maximum 12 characters)]
/* naming */		[-n log=n|size=num,version=n]
/* prototype file */	[-p fname]
/* quiet */		[-q]
/* realtime subvol */	[-r extsize=num,size=num,rtdev=xxx]
/* sectorsize */	[-s log=n|size=num]
/* version */		[-V]
			devicename
<devicename> is required unless -d name=xxx is given.
<num> is xxx (bytes), xxxs (sectors), xxxb (fs blocks), xxxk (xxx KiB),
      xxxm (xxx MiB), xxxg (xxx GiB), xxxt (xxx TiB) or xxxp (xxx PiB).
<value> is xxx (512 byte blocks).
mount: you must specify the filesystem type
umount: /mnt: not mounted
