#include "biblioteca.h"

/** \brief funcion que suma dos numeros enteros
 *
 * \param a int, primer numero
 * \param b int, segundo numero
 * \return int, resultado de la suma de los dos numeros
 *
 */
int sumar(int a, int b)
{
    int rdo;

    rdo= a + b;

    return rdo;
}

/** \brief funcion que resta dos numeros enteros
 *
 * \param a int, primer numero
 * \param b int, segundo numero
 * \return int, resultado de la resta de los dos numeros
 *
 */
int resta(int a, int b)
{
    int rdo;

    rdo= a - b;

    return rdo;
}

/** \brief funcion que divide dos numeros enteros
 *
 * \param a float, primer numero
 * \param b float, segundo numero
 * \return float, resultado de la division de los dos numeros
 *
 */
float division(int a, int b)
{
    float rdo;

    rdo= (float)a / (float)b;

    return rdo;
}

/** \brief funcion que multiplica dos numeros enteros
 *
 * \param a int, primer numero
 * \param b int, segundo numero
 * \return int, resultado de la multiplicacion de los dos numeros
 *
 */
int multiplicacion(int a, int b)
{
    int rdo;

    rdo= a * b;

    return rdo;
}

/** \brief funcion que factoriza un numero entero
 *
 * \param a int, numero
 * \return int, resultado de la factorizacion del numero
 *
 * \return int, resultado factorial del numero A
 */
int factorial(int a)
{
    int rdo=0;
    if( a==1 || a==0 || a==(-1))
    {
        rdo= a;
    }
    else if(a<0)
    {
        rdo=(a * factorial((a+1)));
    }
    else
    {
        rdo=(a * factorial((a-1)));
    }
    return rdo;
}
