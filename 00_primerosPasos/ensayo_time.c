#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

/*
 * Archivo : relojbinario.c
 * Compila : gcc -o relojbinario relojbinario.c
 */


#define BUF_TIME 60
#define BITS 4

typedef enum {
    ZERO = 0x30,
    UNO,
    DOS,
    TRES,
    CUATRO,
    CINCO,
    SEIS,
    SIETE,
    OCHO,
    NUEVE
} Hora;

typedef struct _f_hora {
    int hora_decena[BITS];
    int hora_unidad[BITS];
    int minuto_decena[BITS];
    int minuto_unidad[BITS];
    int segundo_decena[BITS];
    int segundo_unidad[BITS];
} f_hora;

char formato[] = "%k%M%S";
char fecha[BUF_TIME];
void create_clock();
void create_num(char num,f_hora *hora,int i);
void destroy_Binary(f_hora *hora);
void create_binary(f_hora *hora);
void show_clock(f_hora hora);

int main()
{
    f_hora hora;
    create_clock();
    create_binary(&hora);
    show_clock(hora);
    return 0;
}

void create_clock()
{
    struct tm *tiempo;
    time_t ahora = time(0);
    tiempo = localtime(&ahora);
    strftime(fecha,BUF_TIME,formato,tiempo);
}

void create_binary(f_hora *hora)
{
    int len = strlen(fecha),i;
    if (len == 0)
        exit(1);
    for (i = 0;i< len;i++)
        create_num(fecha[i],hora,i);
}

void create_num(char num,f_hora *hora,int iter)
{
    int aux[BITS],i;
    switch((int)num)
    {
        case ZERO:
            aux[0] = 0;
            aux[1] = 0;
            aux[2] = 0;
            aux[3] = 0;
            break;
        case UNO:
            aux[0] = 0;
            aux[1] = 0;
            aux[2] = 0;
            aux[3] = 1;
            break;
        case DOS:
            aux[0] = 0;
            aux[1] = 0;
            aux[2] = 1;
            aux[3] = 0;
            break;
        case TRES:
            aux[0] = 0;
            aux[1] = 0;
            aux[2] = 1;
            aux[3] = 1;
            break;
        case CUATRO:
            aux[0] = 0;
            aux[1] = 1;
            aux[2] = 0;
            aux[3] = 0;
            break;
        case CINCO:
            aux[0] = 0;
            aux[1] = 1;
            aux[2] = 0;
            aux[3] = 1;
            break;
        case SEIS:
            aux[0] = 0;
            aux[1] = 1;
            aux[2] = 1;
            aux[3] = 0;
            break;
        case SIETE:
            aux[0] = 0;
            aux[1] = 1;
            aux[2] = 1;
            aux[3] = 1;
            break;
        case OCHO:
            aux[0] = 1;
            aux[1] = 0;
            aux[2] = 0;
            aux[3] = 0;
            break;
        case NUEVE:
            aux[0] = 1;
            aux[1] = 0;
            aux[2] = 0;
            aux[3] = 1;
            break;
        default:
            break;
    }
    for (i=0;i<BITS;i++)
    {
        if (iter == 0)
        {
            hora->hora_decena[i] = aux[i];
        }
        else if (iter == 1)
        {
            hora->hora_unidad[i] = aux[i];
        }
        else if (iter == 2)
        {
            hora->minuto_decena[i] = aux[i];
        }
        else if (iter == 3)
        {
            hora->minuto_unidad[i] = aux[i];
        }
        else if (iter == 4)
        {
            hora->segundo_decena[i] = aux[i];
        }
        else
        {
            hora->segundo_unidad[i] = aux[i];
        }
    }
}

void show_clock(f_hora hora)
{
    int i;
    for (i=0;i<BITS;i++)
    {
        printf("\t%d\t",hora.hora_decena[i]);
        printf("\t%d\t",hora.hora_unidad[i]);
        printf("\t%d\t",hora.minuto_decena[i]);
        printf("\t%d\t",hora.minuto_unidad[i]);
        printf("\t%d\t",hora.segundo_decena[i]);
        printf("\t%d\t",hora.segundo_unidad[i]);
        puts("");
    }
}
