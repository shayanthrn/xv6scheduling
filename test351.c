#include "types.h"
#include "stat.h"
#include "user.h"


struct timevars {
  int creation_time;           //  {    
  int running_time;            //
  int sleep_time;              //       time variables!
  int waiting_time;            //
  int termination_time;        //  }
};


void print(struct timevars t1){
    printf(1,"%d %d %d %d %d\n\n\n",t1.creation_time,t1.running_time,t1.sleep_time,t1.termination_time,t1.waiting_time);
}

 
int                  // this test is perfoming by forcing quantum
main(void)
{
    int pid1,pid2,pid3;
    struct timevars t1,t2,t3;
    pid1=fork();
    if(pid1==0){
        //child
        int i;
        for(i=0;i<100;i++){
            printf(1,"n1\n");
        }
        exit();
    }
    else{
        pid2=fork();
        if(pid2==0){
            //child
            int i;
            for(i=0;i<30;i++){
            printf(1,"n2\n");
            }
            exit();
        }
        else{
            pid3=fork();
            if(pid3==0){
                //child
                int i;
                for(i=0;i<200;i++){
                printf(1,"n3\n");
                }
                exit();
            }
            else{
                waitChild(&t1);
                waitChild(&t2);
                waitChild(&t3);
                print(t1);
                print(t2);
                print(t3);
                exit();
            }
        } 
    }
}
