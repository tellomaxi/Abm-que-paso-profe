#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "clientes.h"
#include "alquileres.h"


void inicializarAlquileres(eAlquileres lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

int buscarLibreAlquileres(eAlquileres arraydealquileres[], int tama)
{
    int indice=-1;

    for(int i=0;i<tama;i++)
    {
        if(arraydealquileres[i].isEmpty==1)
        indice=i;
    }

    return indice;
}

void mostrarAlquileres(eAlquileres arraydealquileres[], int tama)
{
    int flag = 0;

    system("cls");
    printf("id   cod de juego:   cod de cliente:   fecha:   \n\n");

    for(int i=0; i < tama; i++)
    {
        if( arraydealquileres[i].isEmpty == 0)
        {
            mostrarAlquiler(arraydealquileres[i]);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay alquileres cargados");
    }
    printf("\n\n");
}
//
void mostrarAlquiler (eAlquileres alquilerAmostrar)
{
    printf("%d ,       %d ,                %d ,     %02d/%02d/%d\n",alquilerAmostrar.codigoDeAlquiler,alquilerAmostrar.codigoDeJuego,alquilerAmostrar.codigoDeCliente,alquilerAmostrar.fecha.dia,alquilerAmostrar.fecha.mes,alquilerAmostrar.fecha.anio);
}
//
void altaAlquiler(eAlquileres arraydealquileres[],int tama ,eClientes arraydeclientes[], int tamc,eJuegos arraydejuegos[],int tamj,eCategoria arraydecategorias[],int tamcat, int* pId)
{
    int idAlquiler=*pId;
    int indice;
    eAlquileres nuevoAlquiler;
    int auxCodJuego;
    int auxCodCliente;
    eFecha fecha;

    indice=buscarLibreAlquileres(arraydealquileres,tama);

    system("cls");
    printf("*** Alta Alquiler ***\n\n");

    printf("indice libre: %d ",indice);

    if( indice == -1)
    {
        printf("No hay lugar en el sistema para cargar mas alquileres.\n\n");
        system("pause");
    }
    else
    {

        listarJuegos(arraydejuegos,tamj);
        auxCodJuego=function_getInt("Ingrese el codigo de juego: \n");
        nuevoAlquiler.codigoDeJuego=auxCodJuego;
        mostrarClientes(arraydeclientes,tamc);
        auxCodCliente=function_getInt("Ingrese el codigo de cliente: \n");
        nuevoAlquiler.codigoDeCliente=auxCodCliente;

        printf("\nIngrese dia: ");
        scanf("%d", &fecha.dia);

        printf("\nIngrese mes: ");
        scanf("%d", &fecha.mes);

        printf("\nIngrese anio: ");
        scanf("%d", &fecha.anio);

        nuevoAlquiler.fecha = fecha;
        nuevoAlquiler.codigoDeAlquiler=idAlquiler;
        nuevoAlquiler.isEmpty=0;

        arraydealquileres[indice]=nuevoAlquiler;

            *pId = *pId+1;

    }

}
////
/*
int juegosMasAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos)
{
    int retorno=-1;
    int i, j; //uno nunca sabe
    int cantidadClientesMax=0;
    int juegoMaximo=0;
    int acumuladorCliente;

    if(listaAlquileres!=NULL && listaJuegos!=NULL)
    {
        for(i=0; i<lenJuegos; i++)
        {
            acumuladorCliente=0; //Va contando la cantidad de clientes que tiene cada juego
            for(j=0; j<lenAlquileres; j++)
            {
                if(listaJuegos[i].codigoJuego == listaAlquileres[j].codigoJuego && listaAlquileres[j].isEmpty==0 && listaJuegos[i].isEmpty==0)
                {
                    acumuladorCliente++;
                }
            }
            if(acumuladorCliente>cantidadClientesMax)
            {
                juegoMaximo=listaJuegos[i].codigoJuego;
            }

        }
        retorno=juegoMaximo;
    }

    return retorno;

}

//Mostrar alquileres por importe y apellido
int mostrarAlquileresConImporteYApellido(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente )
{
    int retorno=-1;
    int i; //por las moscas

    if(listaAlquileres!=NULL && listaCliente!=NULL && listaJuegos!=NULL)
    {
        printf("importe juego || apellido persona");
        for( i=0 ; i<lenAlquileres ; i++)
        {
            if(listaAlquileres[i].isEmpty==0)
            {
                printf("%f\t   %s\t\n", listaJuegos[buscarJuegoPorId(listaJuegos, lenJuegos, listaAlquileres[i].codigoJuego)].importe, listaCliente[buscarClientePorId(listaCliente, lenCliente, listaAlquileres[i].codigoCliente)].apellido);

            }

        }
        retorno=0;
    }

    return retorno;
}
//El cliente con mas alquileres de juego
int clienteConMasAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eCliente* listaClintes, int lenClientes)
{
    int retorno=-1;
    int i, j;
    int cantidadMax=0;
    int clienteMaximo=0;
    int acumuladorAlquiler;

    if(listaAlquileres!=NULL && listaClintes!=NULL)
    {
        for(i=0; i<lenClientes; i++)
        {
            acumuladorAlquiler=0; //Va contando la cantidad de clientes que tiene cada juego
            for(j=0; j<lenAlquileres; j++)
            {
                if(listaClintes[i].codigoCliente == listaAlquileres[j].codigoCliente && listaAlquileres[j].isEmpty==0 && listaClintes[i].isEmpty==0)
                {
                    acumuladorAlquiler++;
                }
            }
            if(acumuladorAlquiler>cantidadMax)
            {
                clienteMaximo=listaClintes[i].codigoCliente;
            }

        }
        retorno=clienteMaximo;
    }

    return retorno;

}

//El juego con mas importes
int juegoMasImporte(eJuegos* lista, int len)
{
    int retorno=-1;
    int i;
    float maxImporte;

    if(lista!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(lista[i].importe > maxImporte && lista[i].isEmpty==0)
            {
                maxImporte=lista[i].importe;
            }
        }

        printf("%f", maxImporte);
        retorno=0;

    }

    return retorno;
}

////
*/
