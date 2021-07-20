#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>

/* 
██████  ██ ███████ ███    ██ ██    ██ ███████ ███    ██ ██ ██████   ██████       █████       ██████  ██████  ███    ███ ██████  ██████   █████       ██████   █████  ███    ███ ███████ ██████  
██   ██ ██ ██      ████   ██ ██    ██ ██      ████   ██ ██ ██   ██ ██    ██     ██   ██     ██      ██    ██ ████  ████ ██   ██ ██   ██ ██   ██     ██       ██   ██ ████  ████ ██      ██   ██ 
██████  ██ █████   ██ ██  ██ ██    ██ █████   ██ ██  ██ ██ ██   ██ ██    ██     ███████     ██      ██    ██ ██ ████ ██ ██████  ██████  ███████     ██   ███ ███████ ██ ████ ██ █████   ██████  
██   ██ ██ ██      ██  ██ ██  ██  ██  ██      ██  ██ ██ ██ ██   ██ ██    ██     ██   ██     ██      ██    ██ ██  ██  ██ ██      ██   ██ ██   ██     ██    ██ ██   ██ ██  ██  ██ ██      ██   ██ 
██████  ██ ███████ ██   ████   ████   ███████ ██   ████ ██ ██████   ██████      ██   ██      ██████  ██████  ██      ██ ██      ██   ██ ██   ██      ██████  ██   ██ ██      ██ ███████ ██   ██ 
                                                                                                                                                                                                
                                                                                                                                                                                                

 */

int option, counterData, counterClients=0, buyOption=1, shipmentAmount;
int counterOne, productCode, counterTwo, quantity, counterFour, counterFive;
int document, shipment, productBuy, menuOption, adminOption;
char shipmentYes[5]="si";
char shipmentNo[5]="no";
char user[10], *userCorrect="admin";
char password[10], passwordCorrect[10]="admin";
int userComparison, passwordComparison, shipmentComparison;
int selledAmount[5];
float totalPrice;
int trys = 5;
char *localities[10] = {"Temperley", "Rafael Calzada", "Lomas de Zamora", "Monte Grande", "Adrogue", "Lavallol", "Banfield", "Lanus", "Avellaneda", "Ezeiza"};

enum Colors { 
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LGREY = 7,
    DGREY = 8,
    LBLUE = 9,
    LGREEN = 10,
    LCYAN = 11,
    LRED = 12,
    LMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};


void color(int background, int text){ 

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 

    int newColor = text + (background * 16);

    SetConsoleTextAttribute(console, newColor); 
}

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

	for(counterOne=0;counterOne<5;counterOne++){
		printf("\nCodigo de producto %d: \n%s \nPrecio: $ %d \nCantidad en stock: %d \n", prod[counterOne].code, prod[counterOne].product, prod[counterOne].price, prod[counterOne].stock );
		printf("------------------------------------------------------------------\n");
	}
	system("pause");
	system("cls");
	menu();
}

void particularProduct(){

	do{
	printf ("\nIngrese el codigo del producto que desea consultar: ");
	scanf("%d",&productCode);
	system("cls");
	}while (productCode<0 || productCode>5);

	printf("\nCodigo de producto %d:\n%s \nPrecio: $ %d \nCantidad en stock: %d \n", prod[productCode-1].code, prod[productCode-1].product, prod[productCode-1].price, prod[productCode-1].stock );

	system("pause");
	menu();
}

void sell(){
	int i;
	counterFour=0;
	system("cls");
	printf("Ingrese su nombre y apellido:\n");
	fflush(stdin);
	gets(client[counterTwo].fullName);
	system("cls");
	//mucho trabajo escribir una Regex en C, lo lamento.😞
	char *roda [3]= {"roda", "Roda", "RODA"};

	int nameComaparison = strcmp(client[counterTwo].fullName, roda[0]);
	int nameComaparison2 = strcmp(client[counterTwo].fullName, roda[1]);
	int nameComaparison3 = strcmp(client[counterTwo].fullName, roda[2]);

	if(nameComaparison == 0 || nameComaparison2 == 0  || nameComaparison3 == 0){
		color(BLACK, RED);
		system("cls");
		printf("Hubo un error en el sistema\nSe le recargara $20000\n\n\a");
		client[counterTwo].price = 20000;
		system("pause");
	}
	color(BLACK, MAGENTA);
	while(buyOption!=0){
		printf("Que producto desea llevar?\n");
		for(i=0;i<5;i++){
			printf("%d.%s.............$%d\n", i+1,prod[i].product, prod[i].price);
		}
		scanf("%d",&productBuy);
		system("cls");
		printf("ingrese la cantidad que desea llevar: \n");
		scanf("%d", &quantity);
		system("cls");
		switch(productBuy){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			if(quantity>prod[productBuy-1].stock){
				printf("La cantidad seleccionada excede la cantidad disponible\nVolviendo al menu\n");
				system("pause");
				system("cls");
				menu();
			}
			else{
				client[counterTwo].price+=prod[productBuy-1].price*quantity;
				prod[productBuy-1].stock-=quantity;
				strcpy(selled[counterFour].bought,prod[productBuy-1].product);
				selled[counterFour].boughtQuantity=quantity;
				selledAmount[productBuy-1]+=quantity;
			}
		break;
		break;
		default:
		break;
		
	}
	system("cls");
	counterFour++;
		printf("Desea llevar otro producto?\n1.SI 0.NO\n");
		scanf("%d",&buyOption);
		system("cls");
		
		
}

system("cls");
shipmentAsk();
}


void shipmentAsk(){
	int i;
	int lol=0;
	do{
		printf("Como desea recibir el pedido?\nEl costo del envio es de $500\n\n1.Envio\n\n2.Retiro en sucursal\n");
		scanf("%d",&shipment);
}while(shipment<1 || shipment>2);
	if(shipment==1){
		strcpy(client[counterTwo].shipmentOption,shipmentYes);
		shipmentAmount++;
		system("cls");
		printf("Ingrese la localidad a la que se le ralizara el envio: \n");
		fflush(stdin);
		gets(client[counterTwo].location);
		int localitieComparison;

		for(i=0;i<10;i++){
			localitieComparison = strcmp(client[counterTwo].location, localities[i]);
			if(localitieComparison == 0){
				lol = i;
			}
		}
		localitieComparison = strcmp(client[counterTwo].location, localities[lol]);
		if(localitieComparison == 0){
			printf("Su localidad se encuentra dentro de las zonas de entrega, su envio es gratis!!\n");
		}else{
			printf("Se le recargara $500 por el envio\n");
			client[counterTwo].price+=500;
		}
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
	buyResume();
}


void adminMenu(){
	system("cls");
	printf("----------------------------Menu administrativo----------------------------\n");

	if(counterClients == 0){
		printf("No hay ventas todavia\n");
		printf("Ingrese alguna para accerder\n");
		printf("------------------------Presione enter para continuar------------------------\n");
		getch();
		system("cls");
		menu();
	}
	printf("Seleccione la opcion a la que desea ingresar\n\n1.Ver historial de ventas\n2.Resumen\n0.Volver al menu principal\n");
	scanf("%d",&adminOption);
	switch (adminOption){
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
		printf("Nombre del cliente: %s \n",client[counterFive].fullName );
		printf("Envio: %s \n", client[counterFive].shipmentOption);
		shipmentComparison=strcmp(client[counterFive].shipmentOption,shipmentYes);
		if(shipmentComparison==0){
			printf("Localidad: %s\n", client[counterFive].location);	
		}
		printf("Precio total: %.2f \n", client[counterFive].price);
		printf("---------------------------------\n");
	}
	system("pause");
}

void buyResume(){
	
	printf("------Resumen de la compra--------------\n");
	printf("Nombre del cliente: %s \n",client[counterTwo-1].fullName );
	printf("Envio: %s \n", client[counterTwo-1].shipmentOption);
	if(shipment==1){
	printf("Localidad: %s\n", client[counterTwo-1].location);	
	}
	for(counterFive=0;counterFive<counterFour;counterFive++){
		printf("%s x %d\n",selled[counterFive].bought, selled[counterFive].boughtQuantity);
	}
	printf("Precio total: %.2f ", client[counterTwo-1].price );
	
	system("pause");
	system("cls");
	menu();

}

void enterCredential(){
	int credential=0;
	do{ 
    	printf("\nIngrese el nombre de usuario: ");
    	fflush(stdin);
    	gets(user);
    	printf("Ingrese la contraseña: ");
    	fflush(stdin);
    	gets(password);
    	userComparison = strcmp(user, userCorrect); //admin
    	passwordComparison = strcmp(password, passwordCorrect); //admin
	if(userComparison!=0 || passwordComparison!=0){
		printf("Tu contraseña o usuario no es correcta.\nVuelve a comprobarla.\n");
		printf("Desea intentar nuevamente o prefiere volve al menu\n");
		printf("1.Intentar de nuevo\n2.Volver al menu principal\n");
		scanf("%d", &credential);
		if(credential == 1){
			trys--;
			enterCredential();
			if(trys == 0){
				printf("Ha superado el limite de intentos\n");
				system("pause");
				system("cls");
				menu();
			}
		}else if(credential == 2){
			menu();
		}else{
			trys--;
			enterCredential();
			if(trys == 0){
				printf("Ha superado el limite de intentos\n");
				system("pause");
				system("cls");
				menu();
			}
		}
	}
	}while(userComparison!=0 || passwordComparison!=0);
	if(userComparison==0 && passwordComparison==0){
		adminMenu(); 
	}	
}

void menu(){
	int doooooooooucee=0;
	int option;
	do{
	
	printf("Seleccione una de las siguientes opciones\n1.realizar compra\n2.Ver lista de productos\n3.ver datos de un producto en particular\n4.Menu administrativo\n0.salir\n");
	scanf("%d",&option);
}while(option<0 || option>4);
	switch(option){
		
		case 1:
            counterClients++;
            buyOption=1;
			sell();			

			break;
		case 2:
			system("cls");
			
			productList();
			system("pause");
			system("cls");	
			
			break;	
			
        case 3:

            system("cls");
            particularProduct();
            system("pause");
            system("cls");

            break;
		
		case 4:
			enterCredential();
		break;
	
		case 0:
			do{
				
				system("cls");
				printf("Esta seguro que desea salir del sistema?\n");
				printf("1.SI\n2.NO\n");
				scanf("%d", &doooooooooucee);
				if(doooooooooucee == 1){
					printf("--------------------------------");
					printf("\nUsted ha salido del sistema.\nQue tenga un buen dia.\n");
					printf("01110010 01101111 01100100 01100001  01110100 01101011 01101101");
					return 0;
				}else if(doooooooooucee == 2){
					menu();
				}
			}while(doooooooooucee<1 || doooooooooucee>2);
			
		break;

		default:
			menu();
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
prod[3].product="placa de video";
prod[3].price=1000000;
prod[3].stock=2;
prod[4].code=5;
prod[4].product="lavarropas";
prod[4].price=7500;
prod[4].stock=8;

color(BLACK, MAGENTA);

menu();

    return 0;
}
