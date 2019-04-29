#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "clientes.h"
#include "alquileres.h"

void inicializarClientes(eClientes lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}

void cargarCategorias(eCategoria categorias[], int tamc)
{
    eCategoria sec[]=
    {
        {1, "Mesa"},
        {2, "Azar"},
        {3, "Estrategia"},
        {4, "salon"},
        {5, "magia"}
    };

    for(int i=0; i < 5; i++)
    {
        categorias[i] = sec[i];
    }
}

void listarCategorias(eCategoria categorias[], int tam)
{

    printf("Descripcion\n\n");
    for(int i=0; i< tam; i++)
    {
        printf("%d   %10s\n", categorias[i].id, categorias[i].descripcion);

    }
    printf("\n\n");
}

int buscarLibre(eClientes lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarCliente(eClientes lista[], int tam, int codigo)//devuelvo el indice del cliente.
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].codigoCliente == codigo && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

void altaCliente(eClientes lista[], int tam,int* pId)
{
    int idCliente= *pId;
    int indice;
    eClientes nuevoCliente;
    char auxName[51];
    char auxChar[10];
    char auxTel[30];

    indice = buscarLibre(lista, tam);

    system("cls");
    printf("*** Alta cliente ***\n\n");

    if( indice == -1)
    {
        printf("No hay lugar en el sistema para cargar mas clientes.\n\n");
        system("pause");
    }
    else
    {

            while(!function_getStringLetras("Ingrese el nombre del cliente: \n",auxName))
            {
                printf("Recuerde, el nombre solo debe tener letras.\n");
            }

            while(!function_ValidaSexo("Ingrese el sexo del cliente: \n",auxChar))
            {
                printf("Recuerde, ingresar el sexo como m o f\n");
            }

            while(!function_esTelefono("Ingrese el telefono del cliente: \n",auxTel))
            {
                printf("Recuerde, el telefono solo debe tener letras.\n");
            }

            fflush(stdin);
            strcpy(nuevoCliente.tel,auxTel);
            strcpy(nuevoCliente.nombre,auxName);
            strcpy(nuevoCliente.sexo,auxChar);
            nuevoCliente.codigoCliente=idCliente;
            nuevoCliente.isEmpty=0;
            lista[indice]=nuevoCliente;
            *pId = idCliente + 1;
            printf("Cliente cargado con exito!!\n");
            system("pause");

    }

}

void bajaCliente(eClientes listado[], int tam)
{

int id;
char auxId[10];
int indice;
char seguir;

   while(!function_getStringNumeros("Ingrese el ID: ",auxId))
    {
        printf("Error ingrese un ID numerico\n.");
        break;
    }

    id=atoi(auxId);

    indice = buscarCliente(listado,tam,id);

    if(indice==-1)
    {
        printf("No existe ese cliente en nuestro sistema!\n");
        system("pause");
    }
    else
    {
        mostrarCliente(listado[indice]);
        seguir=function_getChar("Esta seguro de borrar este cliente? s/n: \n");

        if(seguir=='s')
        {
            listado[indice].isEmpty=1;
            printf("Borrado Exitoso!!!\n");
        }
        else
        {
            printf("Baja cancelada, recuerde ingresar 's' para borrar el cliente! \n");
        }
        system("pause");
    }
}

void mostrarCliente (eClientes clienteAmostrar)
{
    printf("el cliente es: %d , nombre: %s , sexo: %s , telefono: %s  \n",clienteAmostrar.codigoCliente,clienteAmostrar.nombre,clienteAmostrar.sexo,clienteAmostrar.tel);
}

void mostrarClientes (eClientes listado[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
   {
       if(listado[i].isEmpty==0)
        {
         mostrarCliente(listado[i]);
        }
   }
}

void modificaCliente(eClientes listado[], int tam)
{

int id;
char auxId[10];
int indice;
char seguir;
int opcion;
char auxOpcion[10];
//variables para empleado.
char auxName[21];
char auxSexo[21];
char auxTel[10] ;

 while(!function_getStringNumeros("Ingrese el ID: ",auxId))
    {
        printf("Error ingrese un ID numerico\n.");
        break;
    }

    id=atoi(auxId);

    indice = buscarCliente(listado,tam,id);
    if(indice==-1)
    {
        printf("No existe ese cliente en nuestro sistema!\n");
        system("pause");
    }
    else
    {
        mostrarCliente(listado[indice]);
        seguir=function_getChar("Esta seguro que desea modificar este cliente? s/n: \n");
        fflush(stdin);
        if(seguir=='s')
        {
            while(!function_getStringNumeros("\nIngrese opcion a modificar:\n 1.Nombre \n 2.Sexo\n 3.Telefono\n",auxOpcion))//valido legajo siempre.
            {
                {
                printf("Error ingrese una opcion numerica del 1 al 3\n.");
                system("pause");
                fflush(stdin);
                }
            }

            opcion=atoi(auxOpcion);

            if(opcion<1 || opcion>3)
            {
            printf("Error ingrese una opcion numerica del 1 al 3\n.");
            fflush(stdin);
            }

            switch(opcion)
            {

            case 1:
            while(!function_getStringLetras("Ingrese el nuevo nombre del empleado: \n",auxName))
            {
                printf("Recuerde, el nombre solo debe tener letras.\n");
            }

            strcpy(listado[indice].nombre,auxName);

            printf("Nombre modificado con exito!!\n");
            break;

            case 2:
            while(!function_getStringLetras("Ingrese el nuevo sexo del cliente: \n",auxSexo))
            {
                printf("Recuerde, el sexo solo debe tener letras.\n");
            }

            strcpy(listado[indice].sexo,auxSexo);
            printf("sexo modificado con exito!!\n");

            break;

            case 3:
            while(!function_esTelefono("Ingrese el nuevo telefono del empleado: \n",auxTel))
            {
                printf("Error el telefono debe ser numerico.\n");
            }
            strcpy(listado[indice].tel,auxTel);
            printf("telefono modificado con exito!!\n");
            break;


        }


    }
        else
        {
             printf("Modificacion cancelada, recuerde ingresar 's' para continuar con la modificacion!!! \n");
        }
      system("pause");
    }
}

int menu()
{
        char auxOpcion[10];
        int opcion;

        system("cls");
        printf("\n*** Bienvenido!!***\n");
        printf("\n*** Menu de opciones ***\n\n\n");
        printf("1-Alta Cliente\n");
        printf("2-Modificar Datos\n");
        printf("3-Baja de Cliente\n");
        printf("4-Listar\n"); // en este caso, informar los 2 puntos
        printf("5-Alta Alquiler\n");
        printf("6-Mostrar Alquileres\n");
        printf("7-Mostrar Juegos de categoria mesa\n");
        printf("8-Mostrar Alquileres por cliente\n");
        printf("9-Mostrar importe por cliente\n");
        printf("10-Mostrar Clientes que alquilaron un determinado juego\n");
        printf("11-Mostrar Clientes que no alquilaron\n");
        printf("12-Salir\n");


        while(!function_getStringNumeros("Ingrese la opcion deseada: \n",auxOpcion))
        {
            {
            printf("Error ingrese una opcion numerica del 1 al 11\n.");
            system("pause");
            fflush(stdin);
            }
        }
            opcion=atoi(auxOpcion);

            if(opcion<1 || opcion>11)
            {
            printf("Error ingrese una opcion numerica del 1 al 7\n.");
            system("pause");
            fflush(stdin);
            }

    return opcion;
}
//
void hardCordearJuegos(eJuegos juegos[], int tamjuegos)
{
    eJuegos juegosstock[]=
    {
        {1, "juego de accion", 50 ,4},
        {2, "juego de magia", 100,5 },
        {3, "juego de estrategia en tiempo real", 125,3},
        {4, "juego de sumas y restas", 150,1},
        {5, "juego de suerte", 10,2},
        {6, "juego para multiplicar" , 25,1},
        {7, "juego de pelea", 75,4},
        {8, "juego de baile", 150,4},
        {9, "juego de ingenio", 200,1},
        {10, "juegos de resolver problemas", 250,1}
    };

    for(int i=0; i < tamjuegos; i++)
    {
        juegos[i] = juegosstock[i];
    }
}
//
void listarJuegos(eJuegos arraydejuegos[], int tamj)
{

    printf("Descripcion\n\n");
    for(int i=0; i< tamj; i++)
    {
        printf("codigo: %d descpripcion: %10s \n ID Categoria: %d importe: %d \n\n", arraydejuegos[i].codigo, arraydejuegos[i].descripcion,arraydejuegos[i].idCategoria,arraydejuegos[i].importe);
    }
    printf("\n\n");
}
//
void hardCordearClientes(eClientes arraydeclientes[], int tamclientes)
{
    eClientes hardCodeoCliente[]=
    {
        {1,"jose","m","42410544",0},
        {2,"pepe","m","42660518",0},
        {3,"mayra","f","1166114942",0},
        {4,"laura","f","115485222",0},
        {5,"fernando","m","114488542",0}
    };

    for(int i=0; i < 5; i++)
    {
        arraydeclientes[i] = hardCodeoCliente[i];
    }
}


void ordenarClientesPorSexoYnombre(eClientes arraydeclientes[], int tamc)
{

    eClientes auxCliente;

    for(int i=0; i<tamc -1; i++)
    {
        for(int j = i +1; j < tamc; j++)
        {
            if( strcmp(arraydeclientes[i].sexo, arraydeclientes[j].sexo) > 0)
            {
                auxCliente = arraydeclientes[i];
                arraydeclientes[i] = arraydeclientes[j];
                arraydeclientes[j] = auxCliente;
            }
            else if( strcmp(arraydeclientes[i].sexo, arraydeclientes[j].sexo) == 0 && strcmp(arraydeclientes[i].nombre, arraydeclientes[j].nombre) > 0)
            {
                auxCliente = arraydeclientes[i];
                arraydeclientes[i] = arraydeclientes[j];
                arraydeclientes[j] = auxCliente;
            }
        }
    }
    printf("\Clientes ordenados con exito!!!\n\n");

}
