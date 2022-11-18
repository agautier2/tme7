#include <stdio.h>
#include "tme7.h"

void tas_init(){

    tas[0]=TAILLE_FIXE-1;
    tas[1]=-1;
}

void tas_print(){

    
    for(int i = 0; i <TAILLE_FIXE+1;i++){
        if((i>0 && (i%16==0|| i ==128))){
            printf("\n");
            for(int j = i-16; j<i;j++){
                printf("%*d|", 5, j);  
            }   
             
            printf("\n\n");   
        }
        if(i<TAILLE_FIXE){
            printf("%*d|", 5, tas[i]);
        }   
    }
    printf("\n");
}

char* tas_malloc(unsigned int taille){
    free_zone();
    int espace_libre = tas[index_libre];  
    if (taille<tas[index_libre]){
        tas[index_libre]= taille;
        if( tas[index_libre+taille+1]==0){}
        tas[index_libre+taille+1]= espace_libre-(taille+1);
        tas[index_libre+taille+2]= -1;
        index_libre+=taille+1;
        return &tas[index_libre-taille];
    }
    else{
        return NULL;
    }
}  

int tas_free(char *ptr){
    *ptr=-1;  
    first_index_libre();  
    return 0;
}

int first_index_libre(){
     int i =0;
    while(tas[i]!= -1){
        i++;
    }
    index_libre = i-1;
    return index_libre;    
}

void free_zone(){
char *ptr;
char *block_suivant;
ptr = tas+index_libre; 
char size_block=*ptr;
block_suivant=ptr+size_block+1;
char size_bock_suivant= *block_suivant;

while (block_suivant-ptr<(127-index_libre))
{
    

if (*(block_suivant+1)!=-1)
{
    block_suivant+=size_bock_suivant+1; 
}
else{
    while(*(block_suivant+1)==-1){
        *ptr+=size_bock_suivant;
        block_suivant+=size_bock_suivant+1;  
    }

}

}


}



