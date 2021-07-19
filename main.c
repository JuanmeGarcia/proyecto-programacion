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
	char location[40];
	char shipmentOption[5];
	float price;
	



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

printf("\ncodigo de producto %d: \n%s \nPrecio: $ %d \nCantidad en stock: %d \n", prod[counterOne].code, prod[counterOne].product, prod[counterOne].price, prod[counterOne].stock );
printf("------------------------------------------------------------------\n");
}

void particularProduct(){

do{
printf ("\nIngrese el codigo del producto que desea consultar: ");
scanf("%d",&productCode);
system("cls");
}while (productCode<0 || productCode>5);
for(counterOne=0;counterOne<5;counterOne++){

    if(productCode==prod[counterOne].code){
        printf("\ncodigo de producto %d:\n%s \nPrecio: $ %d \nCantidad en stock: %d \n", prod[counterOne].code, prod[counterOne].product, prod[counterOne].price, prod[counterOne].stock );

    
    }

}
}

void sell(){
	system("cls");
	printf("Ingrese su nombre y apellido: \n");
	fflush(stdin);
	gets(client[counterTwo].fullName);
	system("cls");
	while(buyOption!=0){
		printf("¿Que producto desea llevar? \n1.%s\n2.%s\n3.%s\n4.%s\n5.%s \n",prod[0].product, prod[1].product, prod[2].product, prod[3].product, prod[4].product );
		scanf("%d",&productBuy);
		system("cls");
		printf("ingrese la cantidad que desea llevar: \n");
		scanf("%d", &quantity);
		system("cls");
		switch(productBuy){
		case 1:
			if(quantity>prod[0].stock){
				printf("la cantidad seleccionada excede la cantidad disponible\nVolviendo al menu\n");
				system("pause");
				system("cls");
				menu();
			}
			else{
				client[counterTwo].price+=prod[0].price*quantity;
				prod[0].stock-=quantity;
			}
					
		break;
		case 2:
			if(quantity>prod[1].stock){
				printf("la cantidad seleccionada excede la cantidad disponible\nVolviendo al menu\n");
				system("pause");
				system("cls");
				menu();
			}
			else{
				client[counterTwo].price+=prod[1].price*quantity;
				prod[1].stock-=quantity;
			}
					
		break;
		case 3:
			if(quantity>prod[2].stock){
				printf("la cantidad seleccionada excede la cantidad disponible\nVolviendo al menu\n");
				system("pause");
				system("cls");
				menu();
			}
			else{
				client[counterTwo].price+=prod[2].price*quantity;
				prod[2].stock-=quantity;

			}
					
		break;
		case 4:
			if(quantity>prod[3].stock){
				printf("la cantidad seleccionada excede la cantidad disponible\nVolviendo al menu\n");
				system("pause");
				system("cls");
				menu();
			}
			else{
				client[counterTwo].price+=prod[3].price*quantity;
				prod[3].stock-=quantity;
			}
					
		break;
		case 5:
			if(quantity>prod[4].stock){
				printf("la cantidad seleccionada excede la cantidad disponible\nVolviendo al menu\n");
				system("pause");
				system("cls");
				menu();
			}
			else{
				client[counterTwo].price+=prod[4].price*quantity;
				prod[4].stock-=quantity;
			}
					
		break;
		
	}
	system("cls");
		printf("desea llevar otro producto?\n1.SI 0.NO\n");
		scanf("%d",&buyOption);
		system("cls");
		
		
}

system("cls");
shipmentAsk();
}


void shipmentAsk(){
	do{
		printf("Como desea recibir el pedido?\nEl costo del envio es de $500\n\n1.Envio\n\n 2.Retiro en sucursal\n");
		scanf("%d",&shipment);
}while(shipment<1 || shipment>2);
	if(shipment==1){
		strcpy(client[counterTwo].shipmentOption,shipmentYes);
		
		system("cls");
		printf("Ingrese la localidad a la que se le ralizara el envio: \n");
		fflush(stdin);
		gets(client[counterTwo].location);
		client[counterTwo].price+=500;
	}
	else{
		strcpy(client[counterTwo].shipmentOption,shipmentNo);
		
		system("cls");
		printf("Debera retirar el pedido en la sucursal\n");
		
	}
	counterTwo++;
	system("pause");
	system("cls");
	menu();
}





void buyResume(){
	
	printf("------Resumen de la compra anterior--------------\n");
	printf("nombre del cliente: %s \n",client[counterTwo-1].fullName );
	printf("envio: %s \n", client[counterTwo-1].shipmentOption);
	if(shipment==1){
	printf("localidad: %s\n", client[counterTwo-1].location);	
	}
	printf("precio total: %.2f ", client[counterTwo-1].price );
	

}




void menu(){
	do{
	
	printf("Seleccione una de las siguientes opciones\n1.realizar compra\n2.Ver lista de productos\n3.ver datos de un producto en particular\n4.ver resumen de la compra\n0.salir\n");
	scanf("%d",&option);
}while(option<0 || option>4);
	switch(option){
		
		case 1:
            counterClients++;
            buyOption=1;
			sell();			

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
			if(counterClients==0){
				system("cls");
				printf("No se ha realizado ninguna venta\n");
			}
			else{
			
				system("cls");
				buyResume();
			}
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
			sell();			

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
			if(counterClients==0){
				system("cls");
				printf("No se ha realizado ninguna venta\n");
			}
			else{
			
				system("cls");
				buyResume();
			}
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
