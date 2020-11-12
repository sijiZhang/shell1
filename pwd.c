#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{


        char this_name[20]=".",father_name[20]="..";
        char name[16][32];
        struct dirent *this_dir=NULL,*father_dir=NULL,*temp=NULL;
        DIR *dir=NULL;
        int i=0;
        unsigned long int this_ino;
        while(1)
        {
                dir = opendir(this_name);
                if(dir == NULL)
                printf("error open");
                while(1)
                {
                        this_dir = readdir(dir);
                        if(strcmp(this_dir->d_name,".")==0)
                        break;
                }
                this_ino=this_dir->d_ino;
                closedir(dir);
                dir = opendir(father_name);

                while(1)
                {
                        father_dir = readdir(dir);
                        if(father_dir->d_name[0]=='.'&&father_dir->d_name[1]=='.')
                        break;
                }
                if(this_dir->d_ino==father_dir->d_ino)
                break;
                closedir(dir);
                dir=opendir(father_name);
                while((temp=readdir(dir))!=NULL)
                {
                        if(temp->d_ino==this_ino)
                        {
                                bzero(name[i],32);
                                strcat(name[i++],temp->d_name);
                                break;
                        }
                }
                closedir(dir);
                strcat(this_name,"/..");
                strcat(father_name,"/..");
        }
        for(i--;i>=0;i--)
        printf("/%s",name[i]);
        printf("\n");
}
~                             