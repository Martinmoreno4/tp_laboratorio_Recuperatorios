#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include"ArrayEmployees.h"
#include "biblioteca.h"

#define LEN 1000

int menu();

int main()
{
    //char seguirModificar;
    //int indice;
    int rta;
    int eleccionInformar;

    int idBaja;
    int nextId = 1000;
    Employee lista[LEN];
    char seguir = 's';
    char confirma = 's';

    if(!initEmployees(lista, LEN))
    {
        printf("empleados inicializados con exito\n");
    }
    else
    {
        printf("error al inicializar\n");
    }

    do
    {
        int acumulador=0;
        float salarioPromedio=0;
        int divisor=0;
        int salariosSuperanPromedio=0;
        char newName[51];
        char newLastName[51];
        float newSalary =0;
        int newSector=0;
        //int findId = NULL;
        switch(menu())
        {

        case 1:

            if(addEmployee(lista, LEN, nextId, newName, newLastName, newSalary, newSector)==0)
            {
                nextId++;
                printf("alta exitosa\n\n");
            }
            else
            {
                printf("problemas con el alta\n\n");
            }
            break;

        break;

        case 2:
            rta=modifyEmployee(lista, LEN);
            switch(rta)
            {
            case 0:
                printf("se a realizado la modificacion \n");
                break;

            case 2:
                printf("se a cancelado la modificacion \n");
                break;

            case 1:
                printf("error durante modificacion... \n");
                break;
            }
        break;

        case 3:
            system("cls");
            printEmployees(lista, LEN);
            printf("\n\n ingrese el id: ");

            scanf("%d", &idBaja);

            rta=removeEmployee(lista, LEN, idBaja);
            switch(rta)
            {
            case 0:
                printf("se a realizado la baja\n");
                break;

            case 2:
                printf("se a cancelado la baja\n");
                break;

            case 1:
                printf("error durante la baja...\n");
                break;
            }
        break;

        case 4:

            printf("informar\n");
            printf("1 - Listado de los empleados ordenados alfabéticamente por Apellido y Sector ASCENDENTE\n");
            printf("2 - Listado de los empleados ordenados alfabéticamente por Apellido y Sector DESCENDENTE\n");
            printf("3 - Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n");
            fflush(stdin);
            eleccionInformar = getInt("ingrese eleccion");

            switch(eleccionInformar)
            {
            case 1:
                sortEmployees(lista, LEN, 1);
                printEmployees(lista, LEN);
                break;

            case 2:
                sortEmployees(lista, LEN, 0);
                printEmployees(lista, LEN);
                break;

            case 3:
                for(int i= 0; i < LEN; i++)
                {
                    if(!lista[i].isEmpty)
                    {
                        divisor++;
                        acumulador = acumulador + lista[i].salary;
                    }
                }
                salarioPromedio=(float)acumulador/(float)divisor;
                printf("El salario promedio es: %.2f\n\n",salarioPromedio);
                for(int i= 0; i < LEN; i++)
                {
                    if(!lista[i].isEmpty && lista[i].salary>salarioPromedio)
                    {
                        salariosSuperanPromedio++;
                    }
                }
                printf("Son %d empleado/s cuyo salario supera el promedio\n",salariosSuperanPromedio);
                break;
            }

        break;

            case 5:
            printf("Confirma salida?('s' para salir): ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
                break;

        }

        system("pause");

    }
    while( seguir == 's');

    return 0;
}

int menu()
{
    int opcion;
    system("cls");

    printf("1 ALTAS\n");
    printf("2 MODIFICAR\n");
    printf("3 BAJA\n");
    printf("4 INFORMAR\n");
    printf("5 SALIR\n");
    fflush(stdin);
    opcion = getInt("Ingrese opcion: ");

    return opcion;
}

