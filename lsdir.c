
//#lsdir dirname
#include "sys/types.h"
#include "stdio.h"
#include "dirent.h"
#include "unistd.h"

int main(int argc,char **argv){
DIR * dir;
struct dirent * ptr;
int i;

if(argc==1)
dir=opendir("./");
else
dir=opendir(argv[1]);

while((ptr=readdir(dir))!=NULL) {
printf("%s\n",ptr->d_name);

}
closedir(dir);
return 0;
}
