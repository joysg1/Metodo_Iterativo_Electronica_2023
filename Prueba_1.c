#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>


#define VT  0.026
#define eu  2.71828




int main (){

	char op;
	float VSS, R, VD[10], ID[10], IS;
    int n;

    printf("\t\t\t\t METODO ITERATIVO \n\n");
	do{

	printf("Ingrese el valor de VSS: \n\n");
	scanf("%f",&VSS);
    }while(VSS<=0);

	printf("\n\n");



	do {
	printf("Ingrese el valor de R: \n\n");
	scanf("%f",&R);
	}while(R<=0);

	printf("\n\n");

	do {

	printf("Ingrese el valor de VD: \n\n");
	scanf("%f",&VD[0]);
	}while(VD[0]<=0);


	printf("\n\n");






	do{

		printf("Indique si el enunciado del problema le proporciona IS [Y/N]: \n\n");
		scanf("%c",&op);


	}while(op!= 'Y' && op!= 'y' && op!= 'N' && op!= 'n');

	printf("\n\n");

	if (op =='Y' || op == 'y'){


		do{

		printf("Ingrese el valor de IS: \n\n");
		scanf("%f",&IS);
		}while(IS<=0);

		printf("\n\n");

		do{

		printf("Ingrese el valor de n: \n\n");
		scanf("%d",&n);
		}while(n!=1 && n!=2);

		printf("\n\n");


		ID[0]= pow(eu, (VD[0]/(VT * n))) * IS;

		printf("Valor de ID1: %.4f \n\n",ID[0]);

		printf("\n\n");

		printf("Realizando calculos \n\n");
		printf("\n\n");

		for(int i=0; i<=5; i++){

        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".\n\n");
		ID[i+1] = (VSS - VD[i])/R;

		VD[i+1] = VD[i] + (2.3 * n * VT * log (ID[i+1]/ID[i]));

		printf("Iteracion %d \n\n",i);
		printf("\n\n");
		printf("El valor de ID %d en Ampere es: %.4f \n\n", i+1, ID[i]);
		printf("\n\n");
		printf("El valor de VD %d en Volts es: %.4f \n\n", i+1, VD[i]);
		printf("\n\n");

		if(fabs(VD[i] - VD[i-1])<= 0.001){
        printf("Proceso iterativo terminado ya que la diferencia entre VD %d y VD %d es %.4f \n\n",i+1,i,fabs(VD[i] - VD[i-1]));
		break;

      }
		}

	}

	else if(op =='N' || op == 'n'){

		printf("Ingrese el valor de ID: \n\n");
		scanf("%f",&ID[0]);
		printf("\n\n");

		do{

		printf("Ingrese el valor de n: \n\n");
		scanf("%d",&n);
		}while(n!=1 && n!=2);
		printf("\n\n");


        printf("Realizando calculos \n\n");
		printf("\n\n");

		for(int i=0; i<=5; i++){

        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".\n\n");

        ID[i+1] = (VSS - VD[i])/R;

		VD[i+1] = VD[i] + (2.3 * n * VT * log (ID[i+1]/ID[i]));

		printf("Iteracion %d \n\n",i);
		printf("\n\n");
		printf("El valor de ID %d en Ampere es: %.4f \n\n", i+1, ID[i]);
		printf("\n\n");
		printf("El valor de VD %d en Volts es: %.4f \n\n", i+1, VD[i]);
		printf("\n\n");

		if(fabs(VD[i] - VD[i-1])<= 0.001){
        printf("Proceso iterativo terminado ya que la diferencia entre VD %d y VD %d es %.4f \n\n",i+1,i,fabs(VD[i] - VD[i-1]));
		break;

      }




		}




	}


















    system("pause");
	return 0;
}

