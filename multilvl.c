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

struct timevars {
  int creation_time;           //  {    
  int running_time;            //
  int sleep_time;              //       time variables!
  int waiting_time;            //
  int termination_time;        //  }
};


void print(struct timevars t1,int pid){
    printf(1," pid :%d  and %d %d %d %d %d\n\n\n",pid,t1.creation_time,t1.running_time,t1.sleep_time,t1.termination_time,t1.waiting_time);
}

 
 
int
main(void)
{
    int pid1,pid2,pid3,pid4,pid5,pid6;
    struct timevars t1,t2,t3,t4,t5,t6;
    pid1=fork();
    if(pid1==0){
        //child
        int i;
        int pro=0;
        setpro(&pro);
        for(i=0;i<3000;i++){
            printf(1,"n1");
        }
        exit();
    }
    else{
        pid2=fork();
        if(pid2==0){
            //child
            int pro=10;
        setpro(&pro);
            int i;
            for(i=0;i<3000;i++){
            printf(1,"n2");
                }
            exit();
        }
        else{
            pid3=fork();
            if(pid3==0){
                //child
                int pro=100;
        setpro(&pro);
                int i;
        for(i=0;i<3000;i++){
            printf(1,"n3");
        }
                exit();
            }
            else{
                pid4=fork();
                if(pid4==0){
                    int pro=1000;
        setpro(&pro);
                    //child
                    int i;
        for(i=0;i<3000;i++){
            printf(1,"n4");
        }
                    exit();
                }
                else{
                    pid5=fork();
                    if(pid5==0){
                        //child
                        int pro=1500;
        setpro(&pro);
                        int i;
        for(i=0;i<3000;i++){
            printf(1,"n5");
        }
                        exit();
                    }
                    else{
                        pid6=fork();
                        if(pid6==0){
                            int pro=2000;
        setpro(&pro);
                            //child
                            int i;
        for(i=0;i<3000;i++){
            printf(1,"n6");
        }
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
                            
                            int a=waitChild(&t1);
                            int b=waitChild(&t2);
                            int c=waitChild(&t3);
                            int d=waitChild(&t4);
                            int e=waitChild(&t5);
                            int f=waitChild(&t6);
                            printf(1,"\n");
                            print(t1,a);
                            print(t2,b);
                            print(t3,c);
                            print(t4,d);
                            print(t5,e);
                            print(t6,f);

                            printf(1,"\n\n\n the last algorithm was priority and processes had descending priority so we can see the first process ended faster because of more priority");
                            exit();
                        }
                    }
                }
            }
        }
    }
}
