

#include<stdio.h>
#include <stdlib.h>

#include <string.h>

#include <windows.h>

#include<ctype.h>

#include<time.h>

int  __vvv (char *s , char *b0){


    int _occure =0;
    char *p = s ;

    if(strlen(b0) >  strlen(s)) return -1;


    char *t = strtok(p,b0);

    while (*p != '\0' ){

  t =strtok(NULL , b0);
        
    printf("%s" , t);
        if(strcmp(t, b0)  ==0 ) 
       {
            
  
    _occure ++;

              p = p +strlen(b0)+1;
    printf("%s \n" , p);
          

         
             


                
   

       }

       else p++;

    }
       

       return _occure;
}


int main(int argc  ,   const char *argv[])

{

  

   char *p = "hello tehre  ,  hello , hi  ,  hello , there  , there , there how many there here   , teher , there ,  hello  there";

   char *m = "there";

   printf("%s" , strtok(p,m));

 getchar()

  int _u  =__vvv(p , m);
  printf("%d \n" , _u);

    int a,  b ,c ;


    printf("enter number  aa  >>  \n\t");


    scanf("%d", &a);

    
    printf("enter number   b>>  \n\t");


    scanf("%d", &b);

    
    printf("enter number  c>>  \n\t");


    scanf("%d", &c);


    fflush(stdout);

    fflush(stdin);

    int _somme = 0 ;


    _somme = a  +b  * c ;


    printf("%d " ,  _somme);



  

    printf(" \t %d  >> \n" , argc);

    printf("argv[%d] %s  >> \n" , argc, argv[0]);


     

     printf(" \t \n >> hello  wordl \n \t >>");
     return 1 ;
}