#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int option, counterData, counterClients, buyOption=1;
int counterOne, productCode, counterTwo, quantity;
int document, shipment, productBuy, menuOption;
char shipmentYes[5]="si";
char shipmentNo[5]="no";

typedef struct Clients{

	int dni;
	char fullName[30];
	char localion[30];
	char shipmentOption[5];
	int price;
	



}Clients;

 Clients client[1000];

typedef struct Abailability{

    int code;
    char* product;
    int price;
    int stock;
}producto;

producto prod[5];




void productList(){

printf("---------------LISTA DE PRODUCTOS-----------------");

for(counterOne=0;counterOne<5;counterOne++)

printf("\ncodigo de producto %d :\n %s \nPrecio: $ %d \n Cantidad en stock: %d \n", prod[counterOne].code, prod[counterOne].product, prod[counterOne].price, prod[counterOne].stock );
printf("------------------------------------------------------------------");
}

void particularProduct(){

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
void buy(){

printf("ingrese su numero de dni: \n\n");
scanf("%d",&client[counterTwo].dni);
printf("ingrese su nombre y apellido: \n\n");
fflush(stdin);
gets(client[counterTwo].fullName);
buyMenu();
do{
	printf("¿Desea retirar el pedido en la sucursal o recibir el pedido por envio?\nEl costo de envio es de $500\n1.Retiro en sucursal\n2.Envio");
	scanf("%d", &shipment);
}while(shipment<1 || shipment>2);
switch(shipment){
	case 1:
		strcpy(client[counterTwo].shipmentOption,shipmentNo);
		break;
	case 2:
		strcpy(client[counterTwo].shipmentOption,shipmentYes);
		client[counterTwo].price+=500;
		break;
	default:
		break;

counterTwo++;
}




}

void buyMenu(){
	while (buyOption!=0){
		printf("¿Que producto desea llevar? \n1. aire acondicionado\n2. pc gama media\n3. pc gama alta\n4. placa de video\n5. lavarropas \n");
		scanf("%d",&productBuy);
	if(productBuy==1){
	do{
		printf("Ingrese la cantidad que desea llevar: \n");
	if(quantity>prod[0].stock){
		printf("la cantidad seleccionada excede la cantidad disponible\n");
	}
	}while(quantity<=prod[0].stock);
	prod[0].stock-=quantity;
	client[counterTwo].price=quantity*prod[0].price;
	}
	if(productBuy==2){
		do{
			printf("Ingrese la cantidad que desea llevar: \n");
		if(quantity>prod[1].stock){
			printf("la cantidad seleccionada excede la cantidad disponible\n");
	}
	}while(quantity<=prod[1].stock);
	prod[1].stock-=quantity;
	}
	if(productBuy==3){
	do{
	printf("Ingrese la cantidad que desea llevar: \n");
	if(quantity>prod[2].stock){
		printf("la cantidad seleccionada excede la cantidad disponible\n");
	}
	}while(quantity<=prod[2].stock);
	prod[2].stock-=quantity;
	}
	if(productBuy==4){
	do{
	printf("Ingrese la cantidad que desea llevar: \n");
	if(quantity>prod[3].stock){
		printf("la cantidad seleccionada excede la cantidad disponible\n");
	}
	}while(quantity<=prod[3].stock);
	prod[3].stock-=quantity;
	}
	if(productBuy==5){
	do{
	printf("Ingrese la cantidad que desea llevar: \n");
	if(quantity>prod[4].stock){
		printf("la cantidad seleccionada excede la cantidad disponible\n");
	}
	}while(quantity<=prod[4].stock);
	prod[4].stock-=quantity;
	}

	printf("¿Desea llevar otro producto?\n1.SI 0.NO");
	scanf("%d" , &menuOption);

   }
}




void menu(){
	do{
	
	printf("Seleccione una de las siguientes opciones\n1.realizar compra\n2.Ver lista de productos\n3.ver datos de un producto en particular\n4.ver resumen de la compra\n0.salir\n");
	scanf("%d",&option);
}while(option<0 || option>4);
	switch(option){
		
		case 1:
            counterClients++;
			buy();			

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

	

		case 0:
			system("cls");
			printf("--------------------------------");
			printf("\nUsted ha salido del sistema.\nQue tenga un buen dia.");
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




	do{
	
	printf("Seleccione una de las siguientes opciones\n1.realizar compra\n2.Ver lista de productos\n3.ver datos de un producto en particular\n4.ver resumen de la compra\n0.salir\n");
	scanf("%d",&option);
}while(option<0 || option>4);
	switch(option){
		
		case 1:
            counterClients++;
			buy();			

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

	

		case 0:
			system("cls");
			printf("--------------------------------");
			printf("\nUsted ha salido del sistema.\nQue tenga un buen dia.");
			break;
	}
	




    return 0;
}
