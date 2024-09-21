/*
============================================================================
Name : 2.c
Author : Gnanendhar Reddy
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 30th Aug, 2024.
============================================================================
*/
#include<stdio.h>

int main(){
	for(;;){
		printf("Running!");
	}
	return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ps aux | grep info
gnanend+    8980 19.6  0.0   2616  1152 pts/1    R+   10:49   0:00 ./info
gnanend+    8982  0.0  0.0  17736  2304 pts/0    S+   10:50   0:00 grep --color=auto info
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cat /proc/8980/status
Name:	info
Umask:	0002
State:	R (running)
Tgid:	8980
Ngid:	0
Pid:	8980
PPid:	8621
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 118 1000 
NStgid:	8980
NSpid:	8980
NSpgid:	8980
NSsid:	8621
VmPeak:	    2616 kB
VmSize:	    2616 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	    1152 kB
VmRSS:	    1152 kB
RssAnon:	       0 kB
RssFile:	    1152 kB
RssShmem:	       0 kB
VmData:	     224 kB
VmStk:	     132 kB
VmExe:	       4 kB
VmLib:	    1672 kB
VmPTE:	      48 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
Threads:	1
SigQ:	0/127095
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	ff
Cpus_allowed_list:	0-7
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	210
nonvoluntary_ctxt_switches:	16
*/
