#include "types.h"
#include "stat.h"
#include "user.h"
 
int
main(void)
{
  int pid1,pid2,pid3;
  pid1=fork();
  if(pid1==0){
    while(1){
        
    }
  }
  else{
      pid2=fork();
      if(pid2==0){
        while(1){
        
    }
      }
      else{
          pid3=fork();
          if(pid3==0){
            while(1){
                
            }
          }
          else{
            printf(1,"pid of n1 child is: %d n2 is : %d and n3 is: %d and the output of getchildren is : %d\n",pid1,pid2,pid3,getChildren());

          }
      }
  }
  exit();
}