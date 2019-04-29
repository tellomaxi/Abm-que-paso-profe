#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "clientes.h"

int function_esTelefono(char msj[],char str[])
{
    char aux[50];
    strcpy(aux,str);
    function_getString(msj,aux);
    int retorno=-1;
    int i=0;
    int contadorGuiones=0;
    while(aux[i]!=NULL && aux[i] != '\0')
    {
        if((aux[i] != ' ') && (aux[i] != '-') && (aux[i] < '0' || aux[i] > '9'))
            return 0;
        if(aux[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1)
    {

     // debe tener un guion
        strcpy(str,aux);
        retorno=1;
        return retorno;
    }
    if(contadorGuiones==0)
    {
        retorno=-1;
        strcpy(str,aux);
        return retorno;
    }
}
//

float getFloat(char msj[])
{
    float aux;
    printf("%s",msj);
    scanf("%f",&aux);
    return aux;
}
//

int function_getInt(char msj[] )
{
    int resultado;
    printf("%s",msj);
    scanf("%d",&resultado);
    return resultado;
}
//
char function_getChar(char msj[])
{
    char aux;
    printf("%s",msj);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}
//
int function_esNum(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] < '0' || str[i] > '9')&&(str[i]!='.')&&(str[i]!=',')&&(str[i]!=NULL)&&(str[i]!=' '))
           return 0;
       i++;
   }
   return 1;
}
//
int function_esSoloLetras(char str[])
{
    int i=0;
    int retorno = 1;
    if(str[i] == '\0')
        retorno = 0;
    else{
        while(str[i] != '\0')
        {
            if(  (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
//
void function_getString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}
//
int function_getStringLetras(char msj[],char input[])
{
    char aux[256];
    function_getString(msj,aux);
    if(function_esSoloLetras(aux)&&(strlen(aux)<51))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0 ;
}
//
int function_getStringNumeros(char msj[],char input[])
{
    char aux[256];
    function_getString(msj,aux);
    if(function_esNum(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int function_ValidaSexo(char msj[],char input[])
{

    do
    {
        if(!function_getStringLetras(msj,input))
        {
            printf("*** ERROR *** Debe ingresar el sexo como M o F");
            system("pause");
            system("cls");
        }

    }
    while(!(input[0] == 'm' || input[0] == 'f' || input[0] == 'M' || input[0] == 'F' && input[1] == '\0')); // lo ingresado en el indice "0".

    return 1;
}
//
char function_getCharSexo(char msj[])
{
    char aux;
    printf("%s",msj);
    fflush(stdin);
    scanf("%c",&aux);
    while(aux !='m' || aux!='f' || aux!='M' || aux!='F')
    {
        printf("Ingrese el sexo como f o m");
    }
    return aux;
}
//
       /*
        getChar(" Ingrese sexo:\n", auxNewSexo);
                    while (auxNewSexo!='m' || auxNewSexo!='f' || auxNewSexo!='M' || auxNewSexo!='F')
                    {
                        printf (" Error, ingrese sexo nuevamente (f o m).");
                        getChar(" Ingrese sexo:\n", auxNewSexo);
                        */

//


