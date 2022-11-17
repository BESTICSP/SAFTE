#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/memfd.h>
#include <sys/syscall.h>
#include <errno.h>
 
int anonyexec(const char *path, char *argv[])
{
    int   fd, fdm, filesize;
    void *elfbuf;
    char  cmdline[256];
    
    
    elfbuf=buf;
    filesize=39228;
    fdm = syscall(__NR_memfd_create, "elf", MFD_CLOEXEC);
    ftruncate(fdm, filesize);
    write(fdm, elfbuf, filesize);
    sprintf(cmdline, "/proc/self/fd/%d", fdm);
    argv[0] = cmdline;
    execve(argv[0], argv, NULL);
    return -1;
}
 
int main(int argc, char* argv[])
{
    printf("1111111");
    int result =anonyexec("/bin/uname", argv);
    return result;
}
