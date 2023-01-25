/*En un establecimiento se cobra de la siguiente manera
: Los primeros 10 minutos son gratis,los siguientes 15 minutos
consecuentes cuentan $3. La primera hora cuenta $10 y cada hora consecuente 
$5 dólares. A partir de la primera hora se cobra horas completas. Si es domingo
se hace un descuento del 10% sobre el monto total. Leer los minutos y las horas y 
mostrar el valor de pago del usuario. Además, el programa debe calcular el cambio que
debe entregarse al usuario.
El proceso debe permitir repetir varias veces el proceso.
*/
#include <stdio.h>
#include <conio.h>
int main(){

    int min,hora,b;
    float costo,desc,total,pago,vuelto;
    char op;
    do
    {
        b=0;
        desc=0;
        do{
            printf("CANTIDAD DE MINUTOS ESTACIONADOS: ");
            scanf("%i",&min);
            printf("CANTIDAD DE HORAS ESTACIONADOS: ");
            scanf("%i",&hora);
            if(min<0 || hora<0){
                printf("ERROR: NO SE PERMITE VALORES NEGATIVOS\n");
                getch();
            }else if(min>59){
                printf("ERROR: INGRESE DATOS REALES\n");
                getch();
            }else{
                b=1;
            }
        }while(b==0);

        b=0;
        char d;

        do{
            fflush(stdin);
            printf("INGRESE UN DIA: (L,M,X,J,V,S,D)\n");
            fflush(stdin);
            scanf("%c",&d);
            fflush(stdin);
            if(d!='L' && d!='M' && d!='X' && d!='J' && d!='V' && d!='S' && d!='D' && d!='l' && d!='m' && d!='x' && d!='j' && d!='v' && d!='s' && d!='d'){
                printf("ERROR: INGRESE UN DIA CORRECTO\n");
            }else{
                b=1;
            }
        }while(b==0);


        if(min>0 && min<=10 && hora==0){
            costo=0;
        }else if(min>10 && min<=25 && hora==0){
            costo=3;
        }else if(min>25 && hora==0){
            costo=10;
        }else if(hora>=1 && min>0){
            costo=5*(hora+1);
        }

        if(d=='D' || d=='d'){
            desc=costo*0.1;
        }
        total=costo-desc;

        if(total<1){
            printf("PARQUEADERO GRATIS\n");
            getch();
        }else{


        printf("VALOR A PAGAR: %2.f\n",total);

        b=0;

        int b1,bi1,bi5,bi10,bi20,bi50,bi100,aux;

        do{
                b1=0;
                do{
                    aux=0;
                    printf("Ingrese denominaciones de billtes\n");
                    printf("Cuantos billetes de 1: ");
                    scanf("%i",&bi1);
                    printf("Cuantos billetes de 5: ");
                    scanf("%i",&bi5);
                    printf("Cuantos billetes de 10: ");
                    scanf("%i",&bi10);
                    printf("Cuantos billetes de 20: ");
                    scanf("%i",&bi20);
                    printf("Cuantos billetes de 50: ");
                    scanf("%i",&bi50);
                    printf("Cuantos billetes de 100: ");
                    scanf("%i",&bi100);

                    aux=(bi1*1)+(bi5*5)+(bi10*10)+(bi20*20)+(bi50*50)+(bi100*100);
                    if(aux>=total){
                        b1=1;
                    }
                    else{
                        printf("INGRESE UN VALOR Q CANCELE EL TOTAL A PAGAR\n\n");
                        getch();
                    }

                }while(b1==0);
                b=1;


        }while(b==0);

        vuelto=aux-total;


        int vb1,vb5,vb10,vb20,vb50,vb100=0;
        vb1=vuelto;
        vb100=(vb1-vb1%100)/100;
        vb1=vb1%100;



        vb50=(vb1-vb1%50)/50;
        vb1=vb1%50;
        vb20=(vb1-vb1%20)/20;
        vb1=vb1%20;

        vb10=(vb1-vb1%10)/10;
        vb1=vb1%10;
        vb5=(vb1-vb1%5)/5;
        vb1=vb1%5;
        printf ("Valor de cambio: %2.f\n", vuelto);
        printf ("Valor de Billetes de 1: %d\n", vb1);
        printf ("Valor de Billetes de 5: %d\n", vb5);
        printf ("Valor de Billetes de 10: %d\n", vb10);
        printf ("Valor de Billetes de 20: %d\n", vb20);
        printf ("Valor de Billetes de 50: %d\n", vb50);
        printf ("Valor de Billetes de 100: %d\n", vb100);
        }
        printf("Desea continuar S/N\n");
        scanf("%s",&op);
    }while(op=='s' || op=='S');

    return 0;
}
