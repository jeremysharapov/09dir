#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void main(){
  char path[50] = ".";
  DIR * d = opendir(path);
  struct dirent * ent = readdir(d);
  printf("Statistics for directory: %s\n", path);
  int size = 0;
  struct stat stats;
  while (ent){
    if (ent -> d_type != DT_DIR){
      stat(ent -> d_name, & stats);
      size += stats.st_size;
    }
    ent = readdir(d);
  }
  printf("Total Directory Size: %d Bytes\n", size);
  closedir(d);

  d = opendir(path);
  ent = readdir(d);
  printf("Directories:\n");
  while (ent){
    if (ent -> d_type == DT_DIR){
      printf("\t%s\n", ent -> d_name);
    }
    ent = readdir(d);
  }
  closedir(d);

  d = opendir(path);
  ent = readdir(d);
  printf("Regular files:\n");
  while (ent){
    if (ent -> d_type == DT_REG) {
      printf("\t%s\n", ent -> d_name);
    }
    ent = readdir(d);
  }
  closedir(d);
}
