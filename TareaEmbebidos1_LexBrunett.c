#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    //Declaración de las variables para la calculadora
    char usuario[80];
    int cantventas;
    int cantgastos;
    float ventas[cantventas];
    float gastos[cantgastos];
    float exceso[]= {11290,14390,17990,21600,43190,64770,86370,115140};//Array Estatico de la tabla de impuestos
    float Impuestos[]= {0,0.05,0.1,0.12,0.15,0.2,0.25,0.3,0.35};//Array de Impuestos a pagar segun la base imponible 
    float tasabasica[]={0,0,155,515,948,4187,8503,13903,22534};
    int f;
    float sumaventas;
    float sumagastos;
    float impuesto;

    printf("-----------------------------------------------------\n");
    printf("-           MINI CALCULADORA TRIBUTARIA             -\n");
    printf("-----------------------------------------------------\n");
    printf("\n");

    printf("Bienvenido a la mini calculadora Tributaria, le pido seguir cada uno de las siguientes pasos: \n");
    /*Ahora vamos a colocar que ingrese la información del usuario para de ahi realizar el calculo tributario*/
    printf("\n");
    printf("1. Agregar su nombre y apellido. \n");
    printf("2. Agregar el número de ventas que obtuvo durante el ultimo mes. \n");
    printf("3. Agregar el valor de cada venta según el número que haya ingresado. \n");
    printf("4. Ingresar el número de compras o gastos que tuvo en el ultimo mes.\n");
    printf("5. Ingresar el valor de cada gasto referente.\n");
    printf("6. El programa mostrará cuanto es el valo a pagar de impuestos.\n");
    printf("\n");
    printf("------------------------------------------\n");
    printf("\n");
    printf("------------------------------------------\n");
    printf("\n");
    // Se agrega el valor del nombre y apellido 
    printf("Por favor escriba su nombre, ejemplo = Julio: \n");
    scanf("%s",usuario);
    printf("Bienvenido  %s ",usuario);
    printf("\n");
    //espacio para que no se vea todo tan apretado
    printf("\n");
    printf("------------------------------------------\n");
    printf("\n");
    printf("------------------------------------------\n");
    printf("\n");
    //procedemos a la parte de la calculadora
    printf("Por favor ingrese el número de Facturas de Ventas/ingresos que su razón social haya recibido, ejemplo = 5: \n");
    scanf("%i",&cantventas);
    for(f=0; f<cantventas; f++) 
    {
        printf("Por favor ingrese el valor del valor de la factura %i :",f);
        printf("\n");
        scanf("%f",&ventas[f]);
        sumaventas = sumaventas + ventas[f];
    }
    printf("Por favor ingrese el número de Facturas de Gastos referentes a su razón Social: \n");
    scanf("%i",&cantgastos);
    for(f=0; f<cantgastos; f++) 
    {
        printf("Por favor ingresar el valor de la factura número %i :",f);
        printf("\n");
        scanf("%2f",&gastos[f]);
        sumagastos = sumagastos +gastos[f];
    }
    //Una vez agregadas las facturas a sus vectores procederemos y sus sumas realizadas procedemos a obtener la Base imponible
    float baseimpo = sumaventas - sumagastos;
    baseimpo = fabs(baseimpo);//en caso de que haya perdida
    //ahora recorreremos la tabla de impuestos para confimar que impuesto tendrá el usuario
    int longitudexceso = sizeof(exceso) / sizeof(exceso[0]);
    for(f=0;f<longitudexceso;f++)
    {
        if(baseimpo <= exceso[f])
        {   
            //Esta formula ayuda a solucionar los impuestos a pagar
            impuesto = tasabasica[f] + ((baseimpo-exceso[f])*Impuestos[f]);
        }
        else if(baseimpo >=exceso[9])
        {
            //Esta formula ayuda a solucionar los impuestos a pagar
            impuesto = tasabasica[9] + ((baseimpo-exceso[9])*Impuestos[9]);
        }

    }
    printf("El valor a pagar de sus impuestos es de: %.2f",impuesto);
    system("pause");
    return 0;
}

