#ifndef tme7
#define tme7
#define TAILLE_FIXE 128
char tas[TAILLE_FIXE];
int index_libre;

void tas_init( );
void tas_print();
char* tas_malloc(unsigned int taille);
int tas_free(char *ptr);
int first_index_libre();
void free_zone();


#endif 