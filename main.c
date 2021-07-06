#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int option, counterData, counterClients;
int counterOne, productCode;


typedef struct Products{

    int code;
    char product [20];
    int price;
    int stock;

}Products;

Products prod[5];

/*
prod[1].code=1;
prod[1].product="aire acondicionado";
prod[1].price=10000;
prod[1].stock=10;
prod[2].code=2;
prod[2].product="pc gama media";
prod[2].price=5000;
prod[2].stock=20;
prod[3].code=3;
prod[3].product="pc gama alta";
prod[3].price=15000;
prod[3].stock=5;
prod[4].code=4;
prod[4].product="placa de video ";
prod[4].price=1000000;
prod[4].stock=2;
prod[5].code=5;
prod[5].product="lavarropas";
prod[5].price=7500;
prod[5].stock=8;
*/

void productList(){

printf("---------------LISTA DE PRODUCTOS-----------------");

for(counterOne=0;counterOne<5;counterOne++)

printf("\ncodigo de producto %d :\n %s \nPrecio: $ %d \n Cantidad en stock: %d \n", prod[counterOne].code, prod[counterOne].product, prod[counterOne].price, prod[counterOne].stock );
printf("------------------------------------------------------------------");
}

void particularProdutc(){

do{
printf ("\nIngrese el codigo del producto que desea consultar: ");
scanf("%d",&productCode);
}while (productCode<0 || productCode>5);
for(counterOne=0;counterOne<5;counterOne++){

    if(productCode==prod[counterOne+1].code){
        printf("\ncodigo de producto %d :\n %s \nPrecio: $ %d \n Cantidad en stock: %d \n", prod[counterOne].code, prod[counterOne].product, prod[counterOne].price, prod[counterOne].stock );

    
    }

}


}

void menu(){
	do{
	
	printf("Seleccione una de las siguientes opciones\n1.carga de clientes\n2.Ver lista de productos\n3.ver datos de un producto en particular\n4.Ver lista de clientes\n5.ver datos de un cliente en particular\n0.salir\n");
	scanf("%d",&option);
}while(option<0 || option>5);
	switch(option){
		
		case 1:
            counterClients++;
			//funcion de carga de clientes

            menu();
			
			break;
		case 2:
			system("cls");
			
			productList();
			system("pause");
			system("cls");	
			
			
			
			menu();
			break;	
			
        case 3:

            system("cls");
            particularProduct();
            system("pause");
            system("cls");

            menu();

            break;

		case 4:
			system("cls");
			if(counterClients==0){
			printf("--------------------------------\n");
			printf("\nNo se han ingresado datos de clientes\n");
			printf("--------------------------------\n");
			system("pause");
			system("cls");
		}
		if(counterClients>0){

			//funcion de lista de clientes
			
            system("pause");
			system("cls");
		}
		menu();
		break;
        case 5:
			system("cls");
			if(counterClients==0){
			printf("--------------------------------\n");
			printf("\nNo se han ingresado datos de clientes\n");
			printf("--------------------------------\n");
			system("pause");
			system("cls");
		}
		if(counterClients>0){
			
            //funcion de cliente en particular

			system("pause");
			system("cls");
		}
		menu();
		break;

		case 0:
			system("cls");
			printf("--------------------------------");
			printf("\n   Usted ha salido del sistema.\n    Que tenga un buen dia.");
			break;
	}
	
	
}



int main(int argc, char const *argv[])
{

prod[0].code=1;
prod[0].product="aire acondicionado";
prod[0].price=10000;
prod[0].stock=10;
prod[1].code=2;
prod[1].product="pc gama media";
prod[1].price=5000;
prod[1].stock=20;
prod[2].code=3;
prod[2].product="pc gama alta";
prod[2].price=15000;
prod[2].stock=5;
prod[3].code=4;
prod[3].product="placa de video ";
prod[3].price=1000000;
prod[3].stock=2;
prod[4].code=5;
prod[4].product="lavarropas";
prod[4].price=7500;
prod[4].stock=8;




    return 0;
}
