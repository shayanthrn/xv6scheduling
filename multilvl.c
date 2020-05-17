#include "types.h"
#include "stat.h"
#include "user.h"


int check(int pid){
   if(getRuntimeofchild(&pid)<5 && checkalive(&pid)==1){
       return 0;
   }
   else{
       return 1;
   }
}
int check2(int pid){
   if(getRuntimeofchild(&pid)<15 && checkalive(&pid)==1){
       return 0;
   }
   else{
       return 1;
   }
}
 
int
main(void)
{
    int pid1,pid2,pid3,pid4,pid5,pid6;
    pid1=fork();
    if(pid1==0){
        //child
        exit();
    }
    else{
        pid2=fork();
        if(pid2==0){
            //child
            exit();
        }
        else{
            pid3=fork();
            if(pid3==0){
                //child
                exit();
            }
            else{
                pid4=fork();
                if(pid4==0){
                    //child
                    exit();
                }
                else{
                    pid5=fork();
                    if(pid5==0){
                        //child
                        exit();
                    }
                    else{
                        pid6=fork();
                        if(pid6==0){
                            //child
                            exit();
                        }
                        else{
                            while(1){   //first every prcess gets 5 quantum with default scheduler
                                if(check(pid1)&&check(pid2)&&check(pid3)&&check(pid4)&&check(pid5)&&check(pid6)){
                                    changePolicy();
                                    break;
                                }
                            }
                            while(1){   //remaining processes get 10 quantum with quantum scheduler 
                                if(check2(pid1)&&check2(pid2)&&check2(pid3)&&check2(pid4)&&check2(pid5)&&check2(pid6)){
                                    changePolicy();
                                    break;
                                }
                            }
                            //remain will schedul with priority alghorithm
                            exit();
                        }
                    }
                }
            }
        }
    }
}
