#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"ArrayEmployees.h"
#include "biblioteca.h"


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
    int error = -1;

    if( list != NULL && len > 0 && len <= 1000)
    {
        for(int i=0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        error=0;
    }

    return error;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector) //ESTO ESTA MAL ARREGLA solo falta la parte del id
{

    int i;
    int error = 1;
    int indice = -1;
    Employee nuevaPersona;

    if( list != NULL && len > 0 && id > 0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                indice = i;
                continue;
            }
        }

        if( indice == -1)
        {
            printf("el sistema esta completo\n");
        }
        else
        {
            getStringLetras("ingrese nombre: ", name);
            getStringLetras("ingrese apellido: ", lastName);
            salary = getFloat("ingrese salario: ");
            sector = getInt("ingrese sector: ");

            nuevaPersona.id = id;
            nuevaPersona.isEmpty = 0;
            strcpy(nuevaPersona.name,name);
            strcpy(nuevaPersona.lastName,lastName);
            nuevaPersona.salary = salary;
            nuevaPersona.sector=sector;
            list[indice] = nuevaPersona;
            error = 0;
        }
    }

return error;
}


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
    int indice = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
    int error = -1;
    int indice;
    char confirma;

    if(list != NULL && len > 0)
    {

        indice = findEmployeeById(list, len, id);

        if( indice == -1)
        {
            printf("no existe una persona con ese id\n\n");
        }
        else
        {
            printf(" %4d  %10s  %10s  %6.2f %5d\n",
            list[indice].id,
            list[indice].name,
            list[indice].lastName,
            list[indice].salary,
            list[indice].sector);

            printf("Confirma borrado: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                list[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 1;
            }
        }
    }
return error;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
    int error = -1;
    Employee auxPersona;

    if(list != NULL && len > 0 && order >= 0 && order <= 1)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j=i +1; j<len; j++)
            {
                if((strcmp(list[i].name, list[j].name) > 0 && order && list[i].sector > list[j].sector) ||
                   (strcmp(list[i].name, list[j].name) < 0 && !order && list[i].sector < list[j].sector))
                {
                    auxPersona = list[i];
                    list[i] = list[j];
                    list[j] = auxPersona;
                }
            }
        }
    error = 0;
    }
    return error;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{

    int flag = 0;
    int error = 1;


    if(list != NULL && length>0)
    {
        //system("cls");
        printf("  Id      Nombre     Apellido   Salario  Sector\n");
        printf("----------------------------\n");

        for(int i= 0; i < length; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printf(" %4d  %10s  %10s  %6.2f %5d\n",
                list[i].id,
                list[i].name,
                list[i].lastName,
                list[i].salary,
                list[i].sector);
                flag = 1;
            }

        }
        if( flag ==0)
        {
            printf("no hay empleados en la lista");
        }
        printf("\n\n");

        error = 0;
    }

return error;
}

/** \brief modify one of four values for an employee identified by id
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int
 *
 */
int modifyEmployee(Employee* list, int len)
{


    char newName[51];
    char newLastName[51];
    float newSalario=0;
    int newSector=0;
    int opcion = 0;
    int error = 1;
    int indice;
    int id=0;
    char confirma;
    Employee nuevaPersona;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("  *** modificar Persona *** \n\n");
        printEmployees(list, len);
        fflush(stdin);
        printf("ingrese el id: ");
        scanf("%d", &id);

        indice = findEmployeeById(list, len, id);

        if( indice == -1)
        {
            printf("no existe una persona con ese id\n\n");
        }
        else
        {
            printf(" %4d  %10s  %10s  %6.2f %5d\n",
            list[indice].id,
            list[indice].name,
            list[indice].lastName,
            list[indice].salary,
            list[indice].sector);

            strcpy(newName,list[indice].name);
            strcpy(newLastName, list[indice].lastName);
            newSalario = list[indice].salary;
            newSector = list[indice].sector;


            printf("Seleccione que dato modificar\n");
            printf("1 Nombre\n");
            printf("2 Apellido\n");
            printf("3 Salario\n");
            printf("4 Sector\n");
            fflush(stdin);
            opcion = getInt("Ingrese opcion: ");

            switch(opcion)
            {
            case 1:
                    getStringLetras("ingrese nuevo nombre: ", newName);
            break;

            case 2:
                    getStringLetras("ingrese nuevo apellido: ", newLastName);

            break;

            case 3:
                    newSalario= getFloat("ingrese nuevo salario: ");

            break;

            case 4:
                    newSector = getInt("ingrese nuevo sector: ");

            break;
            }

            printf("Confirma cambio: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                strcpy(nuevaPersona.name,newName);
                strcpy(nuevaPersona.lastName, newLastName);
                nuevaPersona.salary = newSalario;
                nuevaPersona.sector = newSector;
                nuevaPersona.id=id;
                nuevaPersona.isEmpty=0;
                list[indice]=nuevaPersona;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }
    return error;
}


