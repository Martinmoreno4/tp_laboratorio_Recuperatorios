#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer[4][128];
    int len;
    Employee* auxEmpleado;
    int i;
    len = ll_len(pArrayListEmployee);
    int cant;

    //pFile = fopen("data.csv","r");
    if(pFile==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    do
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(cant == 4)
        {
            auxEmpleado = newEmployeeParam(atoi(buffer[0]),buffer[1],atoi(buffer[2]),atoi(buffer[3]));
            ll_add(pArrayListEmployee, auxEmpleado);
            i++;
        }
        else
        {
            break;
        }

    }while( !feof(pFile) && i>len);

    fclose(pFile);

    printf("\n%d ",ll_len(pArrayListEmployee));

    return 1;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    //char buffer[4][128];
    int len;
    Employee* auxEmpleado = newEmployee();
    int i;
    len = ll_len(pArrayListEmployee);
    //int cant=0;

    pFile = fopen("data.bin","rb");
    if(pFile==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    do
    {
        //cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        fread(auxEmpleado, sizeof(Employee), len, pFile);
        ll_add(pArrayListEmployee, auxEmpleado);
        i++;

    }while( !feof(pFile) && i>len);

    fclose(pFile);

    printf("\n%d ",ll_len(pArrayListEmployee));

    return 1;

    //la diferencia es el uso de fwrite y fread en vez de los fprintf fscanf
}

