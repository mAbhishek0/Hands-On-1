/*
============================================================================
Name : 2.c
Author : Abhishek Mandal
Description :Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 25th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
    while(1){
        printf("the program is running with pid : %d\n", getpid());
        sleep(10); // note: sleep() sleeps the running program
        // run the program with "./a.out &" to view the pid
    }
}

/*
============================================================================
output:
ab@ab:~$ ./a.out
the program is running with pid : 22072

ab@ab:/proc/21680$ cd /proc/22072
ab@ab:/proc/22072$ ls
arch_status         environ            maps           patch_state   statm
attr                exe                mem            personality   status
autogroup           fd                 mountinfo      projid_map    syscall
auxv                fdinfo             mounts         root          task
cgroup              gid_map            mountstats     sched         timens_offsets
clear_refs          io                 net            schedstat     timers
cmdline             ksm_merging_pages  ns             sessionid     timerslack_ns
comm                ksm_stat           numa_maps      setgroups     uid_map
coredump_filter     latency            oom_adj        smaps         wchan
cpu_resctrl_groups  limits             oom_score      smaps_rollup
cpuset              loginuid           oom_score_adj  stack
cwd                 map_files          pagemap        stat
ab@ab:/proc/22072$ cat status
Name:   a.out
Umask:  0002
State:  S (sleeping)
Tgid:   22072
Ngid:   0
Pid:    22072
PPid:   10036
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 256
Groups: 4 24 27 30 46 100 114 1000 
NStgid: 22072
NSpid:  22072
NSpgid: 22072
NSsid:  10036
Kthread:        0
VmPeak:     2680 kB
VmSize:     2680 kB
VmLck:         0 kB
VmPin:         0 kB
VmHWM:      1500 kB
VmRSS:      1500 kB
RssAnon:               0 kB
RssFile:            1500 kB
RssShmem:              0 kB
VmData:      224 kB
VmStk:       132 kB
VmExe:         4 kB
VmLib:      1748 kB
VmPTE:        44 kB
VmSwap:        0 kB
HugetlbPages:          0 kB
CoreDumping:    0
THP_enabled:    1
untag_mask:     0xffffffffffffffff
Threads:        1
SigQ:   0/61002
SigPnd: 0000000000000000
ShdPnd: 0000000000000000
SigBlk: 0000000000000000
SigIgn: 0000000000000000
SigCgt: 0000000000000000
CapInh: 0000000000000000
CapPrm: 0000000000000000
CapEff: 0000000000000000
CapBnd: 000001ffffffffff
CapAmb: 0000000000000000
NoNewPrivs:     0
Seccomp:        0
Seccomp_filters:        0
Speculation_Store_Bypass:       thread vulnerable
SpeculationIndirectBranch:      conditional enabled
Cpus_allowed:   ffff
Cpus_allowed_list:      0-15
Mems_allowed:   00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:      0
voluntary_ctxt_switches:        3
nonvoluntary_ctxt_switches:     0
x86_Thread_features:
x86_Thread_features_locked:
============================================================================
*/
