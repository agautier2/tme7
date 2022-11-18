#include <stdio.h>
#include "tme7.h"
#include <string.h>

int main(){
tas_init();

char *p1, *p2,*p3;//*p4;
p1 = (char *) tas_malloc(10);
p2 = (char *) tas_malloc(9);
p3 = (char *) tas_malloc(5);
strcpy( p1, "tp1" );
strcpy( p2, "tp2" );
strcpy( p3, "tp3" );
tas_free( p2 );
tas_free( p3 );
//p4 = (char *) tas_malloc(8);
//strcpy( p4, "systeme" );
tas_print();

printf("\n%d",index_libre);

}