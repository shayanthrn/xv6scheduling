#include "types.h"
#include "stat.h"
#include "user.h"
 
int
main(void)
{
    int pid;
    pid=fork();
    if(pid==0){
        //child
        while(1){

        }
        exit();
    }
    else{
        printf(1,"%d",pid);
        while(1)
           printf(1,"%d",getRuntimeofchild(&pid));
    }
    exit();
}