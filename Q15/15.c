/*
============================================================================
Name : 15.c
Author : Abhishek Mandal
Description : Write a program to display the environmental variable of the user (use environ).
Date : 1th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

extern char **environ;

int main(){
	char **env = environ;

	while(*env != NULL){
		printf("%s/n", *env);
		env++;
	}

	return 0;

}

/*
============================================================================
output:
ab@ab:~$ gcc 15.c
ab@ab:~$ ./a.out
SHELL=/bin/bash/nSESSION_MANAGER=local/ab:@/tmp/.ICE-unix/3292,unix/ab:/tmp/
.ICE-unix/3292/nQT_ACCESSIBILITY=1/nCOLORTERM=truecolor/nXDG_CONFIG_DIRS=/etc
/xdg/xdg-ubuntu:/etc/xdg/nXDG_MENU_PREFIX=gnome-/nTERM_PROGRAM_VERSION=1.103.
2/nGNOME_DESKTOP_SESSION_ID=this-is-deprecated/nGNOME_SHELL_SESSION_MODE=ubuntu
/nSSH_AUTH_SOCK=/run/user/1000/keyring/ssh/nMEMORY_PRESSURE_WRITE=c29tZSAyMDAwM
DAgMjAwMDAwMAA=/nXMODIFIERS=@im=ibus/nDESKTOP_SESSION=ubuntu/nGTK_MODULES=gail:a
tk-bridge/nPWD=/home/ab/nXDG_SESSION_DESKTOP=ubuntu/nLOGNAME=ab/nXDG_SESSION_TY
PE=x11/nGPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1/nSYSTEMD_EXEC_PID=33
37/nXAUTHORITY=/run/user/1000/gdm/Xauthority/nGJS_DEBUG_TOPICS=JS ERROR;JS LOG/
nWINDOWPATH=2/nHOME=/home/ab/nUSERNAME=ab/nLANG=en_US.UTF-8/nLS_COLORS=rs=0:di=
01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;3
1;01:mi=00:su=37;41:sg=30;43:ca=00:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01
;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.l
zh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;
31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;3
1:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz
=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:
*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01
;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.avif=01;35:*.
jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm
=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:
*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov
=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;
35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nu
v=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35
:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01
;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.fl
ac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;
36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:*~=00;90:*#=00;90:*.bak=00;90:*.crdownload=00;90:*.dpkg-dist=00;90:*.dpkg-new=00;90:*.dpkg-old=00;90:*.dpkg-tmp=00;90:*.old=00;90:*.orig=00;90:*.part=00;90:*.rej=00;90:*.rpmnew=00;90:*.rpmorig=00;90:*.rpmsave=00;90:*.swp=00;90:*.tmp=00;90:*.ucf-dist=00;90:*.ucf-new=00;90:*.ucf-old=00;90:/nXDG_CURRENT_DESKTOP=Unity/nMEMORY_PRESSURE_WATCH=/sys/fs/cgroup/user.slice/user-1000.slice/user@1000.service/session.slice/org.gnome.Shell@x11.service/memory.pressure/nINVOCATION_ID=141d39f1a8ed478e8d9c25025ee1837f/nMANAGERPID=2861/nCHROME_DESKTOP=code.desktop/nGJS_DEBUG_OUTPUT=stderr/nLESSCLOSE=/usr/bin/lesspipe %s %s/nXDG_SESSION_CLASS=user/nTERM=xterm-256color/nLESSOPEN=| /usr/bin/lesspipe %s/nUSER=ab/nCLUTTER_DISABLE_MIPMAPPED_TEXT=1/nDISPLAY=:1/nSHLVL=1/nGSM_SKIP_SSH_AGENT_WORKAROUND=true/nQT_IM_MODULE=ibus/nXDG_RUNTIME_DIR=/run/user/1000/nDEBUGINFOD_URLS=https://debuginfod.ubuntu.com /nJOURNAL_STREAM=9:26787/nXDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/ab/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share/:/usr/share/:/var/lib/snapd/desktop/nGDK_BACKEND=x11/nPATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin/nGDMSESSION=ubuntu/nORIGINAL_XDG_CURRENT_DESKTOP=ubuntu:GNOME/nDBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus/nGIO_LAUNCHED_DESKTOP_FILE_PID=14915/nGIO_LAUNCHED_DESKTOP_FILE=/usr/share/applications/code.desktop/nTERM_PROGRAM=vscode/n_=./a.out/nOLDPWD=/home/ab/na
============================================================================
*/	

