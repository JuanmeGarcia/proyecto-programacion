#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int option, counterData, counterClients, buyOption=1, shipmentAmount;
int counterOne, productCode, counterTwo, quantity, counterFour, counterFive;
int document, shipment, productBuy, menuOption, adminOption;
char shipmentYes[5]="si";
char shipmentNo[5]="no";
char user[10], userCorrect[10]="admin";
char password[10], passwordCorrect[10]="admin";
int userComparison, passwordComparison, shipmentComparison;
int selledAmount[5];
float totalPrice;

typedef enum ProductNumber{
	aire_acondicionado=0, 
	pc_gama_media=1,
	pc_gama_alta=2,
	placa_de_video=3,
	lavarropas=4,
};



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

typedef struct Bought
{
	char bought[30];
	int boughtQuantity;
}sellproduct;

sellproduct selled[10000];


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
	counterFour=0;
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
			if(quantity>prod[aire_acondicionado].stock){
				printf("la cantidad seleccionada excede la cantidad disponible\nVolviendo al menu\n");
				system("pause");
				system("cls");
				menu();
			}
			else{
				client[counterTwo].price+=prod[aire_acondicionado].price*quantity;
				prod[aire_acondicionado].stock-=quantity;
				strcpy(selled[counterFour].bought,prod[aire_acondicionado].product);
				selled[counterFour].boughtQuantity=quantity;
				selledAmount[aire_acondicionado]+=quantity;
			}
					
		break;
		case 2:
			if(quantity>prod[pc_gama_media].stock){
				printf("la cantidad seleccionada excede la cantidad disponible\nVolviendo al menu\n");
				system("pause");
				system("cls");
				menu();
			}
			else{
				client[counterTwo].price+=prod[pc_gama_media].price*quantity;
				prod[pc_gama_media].stock-=quantity;
				strcpy(selled[counterFour].bought,prod[pc_gama_media].product);
				selled[counterFour].boughtQuantity=quantity;
				selledAmount[pc_gama_media]+=quantity;
			}
					
		break;
		case 3:
			if(quantity>prod[pc_gama_alta].stock){
				printf("la cantidad seleccionada excede la cantidad disponible\nVolviendo al menu\n");
				system("pause");
				system("cls");
				menu();
			}
			else{
				client[counterTwo].price+=prod[pc_gama_alta].price*quantity;
				prod[pc_gama_alta].stock-=quantity;
				strcpy(selled[counterFour].bought,prod[pc_gama_alta].product);
				selled[counterFour].boughtQuantity=quantity;
				selledAmount[pc_gama_alta]+=quantity;

			}
					
		break;
		case 4:
			if(quantity>prod[placa_de_video].stock){
				printf("la cantidad seleccionada excede la cantidad disponible\nVolviendo al menu\n");
				system("pause");
				system("cls");
				menu();
			}
			else{
				client[counterTwo].price+=prod[placa_de_video].price*quantity;
				prod[placa_de_video].stock-=quantity;
				strcpy(selled[counterFour].bought,prod[placa_de_video].product);
				selled[counterFour].boughtQuantity=quantity;
				selledAmount[placa_de_video]+=quantity;
			}
					
		break;
		case 5:
			if(quantity>prod[lavarropas].stock){
				printf("la cantidad seleccionada excede la cantidad disponible\nVolviendo al menu\n");
				system("pause");
				system("cls");
				menu();
			}
			else{
				client[counterTwo].price+=prod[lavarropas].price*quantity;
				prod[lavarropas].stock-=quantity;
				strcpy(selled[counterFour].bought,prod[lavarropas].product);
				selled[counterFour].boughtQuantity=quantity;
				selledAmount[lavarropas]+=quantity;
			}
					
		break;
		default:
		break;
		
	}
	system("cls");
	counterFour++;
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
		shipmentAmount++;
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
	totalPrice+=client[counterTwo].price;
	counterTwo++;
	system("pause");
	system("cls");
	menu();
}


void adminMenu(){
	system("cls");
	printf("-------------Menu administrativo--------------\n");
	printf("Seleccione la opcion a la que desea ingresar\n\n1.Ver historial de ventas\n2.Resumen\n0.Volver al menu principal");
	scanf("%d",&adminOption);
	switch (adminOption)
	{
	case 1:
	if(counterClients==0){
		printf("No se han realizado ventas\n");
		system("pause");
		system("cls");
	}
	else{
		system("cls");
		sellHistory();
	}
		system("cls");
		adminMenu();
		break;
	case 2:
		system("cls");
		totalResume();
		system("pause");
		system("cls");
		adminMenu();
	break;
	case 0:
		system("cls");
		menu();
	break;
	default:
	break;
	}
}

void totalResume(){
	printf("Cantidad de ventas realizadas: %d\n", counterTwo);
	printf("Total recaudado: $%.2f\n", totalPrice);
	printf("Cantidad de envios a realizar: %d\n", shipmentAmount);
	printf("cantidad de unidades vendidas de cada producto:\n");
	for(counterFive=0;counterFive<5;counterFive++){
	printf("--%s: %d\n", prod[counterFive].product, selledAmount[counterFive]);
	}



}
void sellHistory(){
	for(counterFive=0;counterFive<counterTwo;counterFive++){
		printf("nombre del cliente: %s \n",client[counterFive].fullName );
		printf("envio: %s \n", client[counterFive].shipmentOption);
		shipmentComparison=strcmp(client[counterFive].shipmentOption,shipmentYes);
		if(shipmentComparison==0){
			printf("localidad: %s\n", client[counterFive].location);	
		}
		printf("precio total: %.2f \n", client[counterFive].price);
		printf("---------------------------------\n");
	}
	system("pause");
}

void buyResume(){
	
	printf("------Resumen de la compra anterior--------------\n");
	printf("nombre del cliente: %s \n",client[counterTwo-1].fullName );
	printf("envio: %s \n", client[counterTwo-1].shipmentOption);
	if(shipment==1){
	printf("localidad: %s\n", client[counterTwo-1].location);	
	}
	for(counterFive=0;counterFive<counterFour;counterFive++){
		printf("%s x %d\n",selled[counterFive].bought, selled[counterFive].boughtQuantity);
	}
	printf("precio total: %.2f ", client[counterTwo-1].price );
	

}



void menu(){
	int option;
	do{
	
	printf("Seleccione una de las siguientes opciones\n1.realizar compra\n2.Ver lista de productos\n3.ver datos de un producto en particular\n4.ver resumen de la compra\n5.Menu administrativo\n0.salir\n");
	scanf("%d",&option);
}while(option<0 || option>5);
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
		case 5:
			do{ 
        	printf("\nIngrese el nombre de usuario: ");
        	fflush(stdin);
        	gets(user);
        	printf("Ingrese la contraseña: ");
        	fflush(stdin);
        	gets(password);
        	userComparison = strcmp(user, userCorrect);
       		passwordComparison = strcmp(password, passwordCorrect);
			if(userComparison!=0 || passwordComparison!=0){
				system("cls");
				printf("Usurario o contraseña incorrectos");
				system("pause");
				system("cls");
			}
			}while(userComparison!=0 || passwordComparison!=0);
			if(userComparison==0 && passwordComparison==0){
				adminMenu();
			}
		break;
	

		case 0:
			system("cls");
			printf("--------------------------------");
			printf("\nUsted ha salido del sistema.\nQue tenga un buen dia.");
		break;
		default:
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


menu();

/*
	do{
	
printf("Seleccione una de las siguientes opciones\n1.realizar compra\n2.Ver lista de productos\n3.ver datos de un producto en particular\n4.ver resumen de la compra\n5.Menu administrativo\n0.salir\n");
	scanf("%d",&option);
}while(option<0 || option>5);
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
		case 5:
			do{ 
        	printf("\nIngrese el nombre de usuario: ");
        	fflush(stdin);
        	gets(user);
        	printf("Ingrese la contraseña: ");
        	fflush(stdin);
        	gets(password);
        	userComparison = strcmp(user, userCorrect);
       		passwordComparison = strcmp(password, passwordCorrect);
			if(userComparison!=0 || passwordComparison!=0){
				system("cls");
				printf("Usurario o contraseña incorrectos");
				system("pause");
				system("cls");
			}
			}while(userComparison!=0 || passwordComparison!=0);
			if(userComparison==0 && passwordComparison==0){
				adminMenu();
			}
		break;
		case 0:
			system("cls");
			printf("--------------------------------");
			printf("\nUsted ha salido del sistema.\nQue tenga un buen dia.");
			break;
	}
	

*/


    return 0;
}
