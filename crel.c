


#include <stdint.h>
#include  <stdio.h>
#include<stdlib.h>
#include<string.h>



char *replacesubstr(const char *s , const char *ser , const char *repl)

{


    char *result ; 
    int  slen =strlen(s);
    int serlen = strlen(ser);
    int _replen = strlen(repl);

    int i , cnt = 0;
   
    for(i = 0 ; s[i] !='\0'  ; i++){
        if(strstr(&s[i] ,  ser) ==&s[i])
        {
            cnt++ ;
            i+= serlen - 1;
        }
    }

    result = (char *) malloc(i +cnt *(_replen - serlen) + 1);
    i = 0;
    while(*s){

         if(strstr(s,ser) == s) {
             strcpy(&result[i] ,  repl );
             i+= _replen ; 
             s+= serlen;
         }
         else result[i++] = *s++ ;
    }

    result[i] = '\0';
    return result;

}


void _readfile (const char *filename , char *fg )
{
   

    char  _readline[2048];
     FILE *gh = fopen(filename , "r+");
     int _m ;
     int cnt = 1;
     while (fscanf(gh, "%s" , _readline) !=EOF)
     {
        printf("%s \n \t" ,  _readline);
         printf("%d \t" , cnt);

         cnt ++;
        

        char  *p = _readline;

          FILE *copier = fopen("copier.txt","a+");
            _m = ftell(gh);

         fprintf(copier , "%s  -%d  ", _readline,_m);

        if( (strcmp(_readline , fg) == 0 )  || (strstr(fg,p) == p)  )
        {
  _m = ftell(gh);
              FILE *saver = fopen("saver.txt","a+");
              
              fprintf(saver , "%s  - %d  ligne  %d   saver _data \n \t ", fg,cnt,_m);
        }
        else {
             FILE *saver = fopen("sror.txt","a+");
             _m = ftell(gh);
             fprintf(saver, " no data found at line %d"  ,_m );
        }



     }
     
}

int main(int argc , const char *argv[]) 
{ 


     if(argc > 1){
        _readfile((char*)argv[1] ,(char*) argv[2]);
         
     }
    char str[] = "yyyyyforyyyyy yyyyy for yyyyy"; 
    char c[] = "yy"; 
    char d[] = "Geeks"; 
 
    char* result = NULL; 
 
    // oldW string 
    printf("Old string: %s\n", str); 
 
    result = replacesubstr(str, c, d); 
    printf("New String: %s\n", result); 
 
    free(result); 
    return 0; 
} 
