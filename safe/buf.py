

if __name__=='__main__':
 #my_matrix = numpy.loadtxt(open("d:\\local.pcm", "rb"), delimiter=",", skiprows=0)
 #print my_matrix
 with open('dump', 'rb') as f:
  all = f.read()
  string=''
  string=string+'''
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
  '''
  string=string+"unsigned char buf[]=\""
  number=0
  for d in all:
   number=number+1
   he=hex(d)
   if len(he)==3:
    e="\\x0%s" % he[2:]
   else:
    e = "\\x%s" % he[2:]
   string=string+e
  string=string+'";'
  string=string+'''
      elfbuf=buf;
      '''
  string=string+'filesize='+str(number)+';'
  string=string+'''
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
  '''
  print(number)
  f = open('y.c', 'w')
  f.write(string)
  f.close()
  print(string)
