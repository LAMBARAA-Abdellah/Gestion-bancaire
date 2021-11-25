#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
//*********  Structure Compte   ***********
typedef struct Compte{
	char Cin[20];
	char Nom[20];
	char Prenom[20];
	double Montant;
	struct Compte *next;	
}compte;
//=============================header================================
void header(){
	int i;
	system("COLOR 3");
	printf("\n\n\t\t\t ");
	for(i=0;i<25;i++){
			 printf("\xB2");
	}
    printf("Gestion Bancaire");
	for(i=0;i<25;i++){
			 printf("\xB2");
	}
	Sleep(100);
    printf("\n\n\t+====================================================================================================+\n");
    Sleep(100);
    printf("\t\t@Lambaraa Abdellah                                                     @Youcode Safi \n");
    Sleep(100);
    printf("\t+====================================================================================================+\n\n");
    Sleep(100);
   	printf("\t\t\t\t\t       __________________________\n");
	Sleep(100); 
    printf("\t\t\t\t\t      /|         _____          /|\n"); 
    Sleep(100);
    printf("\t\t\t\t\t     / |        /____/         / |\n");
	Sleep(100);  
    printf("\t\t\t\t\t    /__|______________________/  |\n");
	Sleep(100); 
    printf("\t\t\t\t\t    |  |                      |  |\n");
    Sleep(100);
    printf("\t\t\t\t\t    |  |______________________|__|\n");
    Sleep(100);
    printf("\t\t\t\t\t    |  /                      | /\n");
    Sleep(100);
    printf("\t\t\t\t\t    | /                       |/\n");
    Sleep(100);
    printf("\t\t\t\t\t    |/________________________|\n");
    Sleep(100);
    printf("\n\n\t\t\tPres any key to continue . . .");
	system("pause > null");
}

void title(){
	int i;
	printf("\033[0;34m ");
	printf("\n\n\t\t\t");
	for(i=0;i<25;i++){
			 printf("\xB2");
	}
    printf("Gestion Bancaire");
	for(i=0;i<25;i++){
			 printf("\xB2");
	}
}

//=====================Fonction d'affichage===================
void afficher(compte *start){
	int i=0;
		compte *courant=start;

	if(start==NULL){
		printf("\033[0;31m");
		printf("La liste des comptes est vide, vous deverez creer des comptes premierment!!\n");
		printf("\033[0m");
	}else{
		printf("***** Affichage les Information des comptes ****\n");
		while(start){
			i++;
			printf("\n==============Compte N%d=================\n",i);
			printf("\033[0;34m ");
			printf("\t Cin:%s\n",start->Cin);
			printf("\t Nom:%s\n",start->Nom);
			printf("\t Prenom:%s\n",start->Prenom);
			printf("\033[0;33m ");
			printf("\t Montant:%.2f DH\n",start->Montant);
			printf("\033[0m ");
			start=start->next;
		}
	}
}
//===================Introduire un compte bancaire==============================
compte* AddCompte(compte *start){
	compte *nv=NULL;
	compte *tmp=start;
	int status=0;
	nv=(compte*)malloc(sizeof(compte));
	printf("\033[0;34m");
	printf("**** Entrer les information  de compte ****\n");
	printf("\033[0m");
	do{
		status=0;
		printf("\tEntrer le CIN:");
		printf("\033[0;33m ");
		scanf("%s",&nv->Cin);
		printf("\033[0m");
	while(tmp){
		if(strcmp(nv->Cin,tmp->Cin)==0){
			printf("\033[0;31m");
			printf("  Votre CIN est deje utilisee\n");
			printf("\033[0m");
			status=1;
		}
		tmp=tmp->next;
	}	
	}while(status==1);
	printf("\tEntrer le Nom:");
	printf("\033[0;33m ");
	scanf("%s",&nv->Nom);
	printf("\033[0m");
	printf("\tEntrer le prenom:");
	printf("\033[0;33m ");
	scanf("%s",&nv->Prenom);
	printf("\033[0m");
	printf("\tEntrer le Montant:");
	printf("\033[0;33m ");
	scanf("%lf",&nv->Montant);
	printf("\033[0m");
	nv->next=NULL;
	if(start==NULL){
		start=nv;
	}else{
		compte *tmp=start;
		while(tmp->next){
			tmp=tmp->next;
		}
		tmp->next=nv;
	}
	if(start){
		printf("\033[0;32m");
		printf("Votre compte a ete cree avec success!!\n");
		printf("\033[0m");
	}else{
		printf("Echec de cree votre compte!!\n");
	}
	return start;
}
//==================Introduire plusieurs comptes bancaire========================
compte* AddListCompte(compte *start){
	int n,i;
	printf("\033[0;35m ");
	printf("Donner le nombre des compte quui peut inserer!!:");
	printf("\033[0;33m ");
	scanf("%d",&n);
	printf("\033[0m");
	for(i=0;i<n;i++){
		printf("\033[0;31m");
		printf("\n\tCreation de compte%d ...\n",i+1);
		printf("\033[0m");
		start=AddCompte(start);
		printf("\033[0;32m");
		printf("\tCompte %d a ete cree\n",i+1);
		printf("\033[0m");
		}	
	return start;
}
//========================Par Ordre Ascendant==========================
void Ascendent(compte *start){
	compte *courant=start;
	compte *index,*tmp;
	if(start==NULL){
		printf("\033[0;31m");
		printf("La liste des comptes est vide, vous deverez creer des comptes premierment!!\n");
		printf("\033[0m");
	}else{
		while(courant){
			index=courant->next;
			while(index){
				if(courant->Montant>index->Montant)
				{
						char Nom[20],Prenom[20],Cin[20];
						double Montant=0;
						
					strcpy(Cin,index->Cin);
					strcpy(Nom,index->Nom);
					strcpy(Prenom,index->Prenom);
					Montant=index->Montant;

					strcpy(index->Cin,courant->Cin);
					strcpy(index->Nom,courant->Nom);
					strcpy(index->Prenom,courant->Prenom);
					index->Montant=courant->Montant;
					
					strcpy(courant->Cin,Cin);
					strcpy(courant->Nom,Nom);
					strcpy(courant->Prenom,Prenom);
					courant->Montant=Montant;				
		
				}
				index=index->next;
			}
			courant=courant->next;
		}
		afficher(start);
	}				
}

//=========================Par Ordre Descendent==============================
void Descendent(compte *start){
	compte *courant=start;
	compte *index,*tmp;
	if(start==NULL){
		printf("\033[0;31m");
		printf("La liste des comptes est vide, vous deverez creer des comptes premierment!!\n");
		printf("\033[0m");
	}else{
		while(courant){
			index=courant->next;
			while(index){
				if(courant->Montant<index->Montant)
				{
					char Nom[20],Prenom[20],Cin[20];
					double Montant=0;
						
					strcpy(Cin,index->Cin);
					strcpy(Nom,index->Nom);
					strcpy(Prenom,index->Prenom);
					Montant=index->Montant;

					strcpy(index->Cin,courant->Cin);
					strcpy(index->Nom,courant->Nom);
					strcpy(index->Prenom,courant->Prenom);
					index->Montant=courant->Montant;
					
					strcpy(courant->Cin,Cin);
					strcpy(courant->Nom,Nom);
					strcpy(courant->Prenom,Prenom);
					courant->Montant=Montant;				
				}
				index=index->next;
			}
			courant=courant->next;
		}
		afficher(start);	
	}			
}
//========================Par Ordre Ascendant à unchiffre introduit=============================
void AscChifre(compte *start){
	compte *c=start;
	int i=0;
	double chaifre;
		if(c==NULL){
		printf("\033[0;31m");
		printf("La liste des comptes est vide, vous deverez creer des comptes premierment!!\n");
		printf("\033[0m");
	}else{
		printf("\033[0;31m ");
		printf("\n Donner le chaifre pour comparais:");
		printf("\033[0m ");
		printf("\033[0;33m ");
		scanf("%lf",&chaifre);
		printf("\033[0m ");
		Ascendent(c);
		printf("\033[0;32m ");
		printf("\n=============Les compte trier!================\n");
		printf("\n=======Les compte superiure au %lf===========\n",chaifre);
		printf("\033[0m ");
		while(c!=NULL){
			i++;
			if(c->Montant>chaifre){
			printf("\n==============Compte N%d=================\n",i);
			printf("\033[0;34m ");
			printf("\t Cin:%s\n",c->Cin);
			printf("\t Nom:%s\n",c->Nom);
			printf("\t Prenom:%s\n",c->Prenom);
			printf("\033[0;33m ");
			printf("\t Montant:%lf DH\n",c->Montant);
			printf("\033[0m ");
			}
			c=c->next;
		}
	}
}

//===================Par Ordre Ascendant à unchiffre introduit=======================
void DescChifre(compte *start){
	compte *c=start;
	int i=0;
	double chaifre;
	if(c==NULL){
		printf("\033[0;31m");
		printf("La liste des comptes est vide, vous deverez creer des comptes premierment!!\n");
		printf("\033[0m");
	}else{
		printf("\033[0;31m ");
		printf("\n Donner le chaifre pour comparais:");
		printf("\033[0m ");
		printf("\033[0;33m ");
		scanf("%lf",&chaifre);
		printf("\033[0m ");
		Ascendent(c);
		printf("\033[0;32m ");
		printf("\n=======Les compte inferiure au %lf===========\n",chaifre);
		printf("\033[0m ");
		while(c!=NULL){
			i++;
			if(c->Montant<chaifre){
			printf("\n==============Compte N%d=================\n",i);
			printf("\033[0;34m ");
			printf("\t Cin:%s\n",c->Cin);
			printf("\t Nom:%s\n",c->Nom);
			printf("\t Prenom:%s\n",c->Prenom);
			printf("\033[0;33m ");
			printf("\t Montant:%.2f DH\n",c->Montant);
			printf("\033[0m ");
			}
			c=c->next;
		}
	}
}

//======================Recherche par Cin==================================
void Recherche(compte *start){
	char cin[20];
	int status=0;
	if(start==NULL){
		printf("\033[0;31m");
		printf("La liste des comptes est vide, vous deverez creer des comptes premierment!!\n");
		printf("\033[0m");
	}else{
		printf("\tDonner votre Cin:");
		printf("\033[0;33m ");
		scanf("%s",cin);
		printf("\033[0m");
	while(start){
		if(strcmp(start->Cin,cin)==0){
			printf("\033[0;32m ");
			printf("\n Affichage des information de compte:%s",cin);
			printf("\033[0m ");	
			printf("\033[0;34m ");
			printf("\n\t Cin:%s\n",start->Cin);
			printf("\t Nom:%s\n",start->Nom);
			printf("\t Prenom:%s\n",start->Prenom);
			printf("\t Montant:%.2f DH\n",start->Montant);
			printf("\033[0m ");		
			break;
		}
		/*
		else{
			printf("\033[0;31m");
			printf("\n Votre cin est incorect\n");
			printf("\033[0m");
		}
		*/
		start=start->next;	
	}
	if(status==0){
			printf("\033[0;31m");
			printf("\n Votre cin est incorect\n");
			printf("\033[0m");
	}
	
	}
}
//=========================Effectuer une opertion Retrait ou Dépot=======================
void Operation(compte *start){
	char opp;
	char cin[20];
	double val;
	int status=0;
	if(start==NULL){
		printf("\033[0;31m");
		printf("La liste des comptes est vide, vous deverez creer des comptes premierment!!\n");
		printf("\033[0m");
	}else{
		printf("\033[0;31m");
		printf("\n============Faire votre operation:==============\n");
		printf("\033[0m");
		printf("\t Donner votre Cin:");
		printf("\033[0;33m ");
		scanf("%s",cin);
		printf("\033[0m");
		printf("\tDonner l operation qui veut fait :R->Retrait,D->Depot:");
		printf("\033[0;33m ");
		scanf("%c",&opp);scanf("%c",&opp);
		printf("\033[0m");
		printf("\tDonner la valeur:");
		printf("\033[0;33m ");
		scanf("%lf",&val);
		printf("\033[0m");
		while(start){
			if(strcmp(start->Cin,cin)==0){
				status=1;
				if(opp=='R'){
					if(val>start->Montant){
						printf("\033[0;31m ");
						printf("Impossible de retirer car la valeur est supperier a compte\n");
						printf("\033[0m");
						printf("\033[0;33m ");
						printf("Votre solde est:%lf\n",start->Montant);
						printf("\033[0m");
					}else{
						start->Montant-=val;
						printf("\033[0;32m ");
						printf("Operation effectuer avec succes!!\n");	
						printf("\033[0m");
					}
				}
				else if(opp=='D'){
						start->Montant+=val;
						printf("\033[0;32m ");
						printf("Operation effectuer avec succes!!\n");	
						printf("\033[0m");
						printf("\033[0;33m ");
						printf("Votre solde est:%lf\n",start->Montant);
						printf("\033[0m");
							
					}
				break;
			}
			/*					
			else{
				printf("\033[0;31m ");
				printf("Ne se trouve aucun compte de %s\n",cin);
				printf("\033[0m");
			}*/
			start=start->next;
		}
			if(status==0){
			printf("\033[0;31m");
			printf("\n Votre cin est incorect\n");
			printf("\033[0m");
	}
		}
}
//=============Fidélisation Ajouter 1.3% aux comptes ayant les 3 premiers montants supérieurs================
compte* Fidelisation(compte *start){
	compte *courant;
	int i;
		if(start==NULL){
		printf("\033[0;31m");
		printf("La liste des comptes est vide, vous deverez creer des comptes premierment!!\n");
		printf("\033[0m");
	}else if(start->next->next!=NULL){
		printf("\033[0;31m ");
		printf("***** Avant fidelisation *****\n");
		printf("\033[0m");
		Descendent(start);
		courant=start;
		for(i=0;i<3;i++){
			courant->Montant*=1.3;
			courant=courant->next;
		}
		printf("\033[0;32m ");
		printf("***** Apres fidelisation *****\n");
		printf("\033[0m");
		afficher(start);
	}else{
		printf("\033[0;31m ");
		printf("la liste ne contient pas plus de 3 compte!!!!!!!\n");
		printf("\033[0m");
	}
	return start;	
}

//=========================Fonction main=========================
int main(){
	int i;
	header();
	system("cls");
		system("COLOR f");

	compte *start=NULL;
	int choix;	
do{
	title();
	printf("\033[0m ");
printf("\n\t\t\t  ===========================Start==============================");
printf("\033[0;36m ");
printf("\n\t\t\t  =   choisir votre choix:                                     =");
printf("\n\t\t\t  =   Introduire un compte bancaire:1	                       =");
printf("\n\t\t\t  =   Introduire plusieurs comptes bancaire:2                  =");
printf("\n\t\t\t  =   Effectuer une opertion Retrait ou Depot:3	               =");
printf("\n\t\t\t  =   Affichage par Ordre Ascendant :4	                       =");
printf("\n\t\t\t  =   Affichage par Ordre Descendent :5	                       =");
printf("\n\t\t\t  =   Affichage Par Ordre Ascendant a un chiffre introduit :6  =");
printf("\n\t\t\t  =   Affichage Par Ordre Descendent a un chiffre introduit :7 =");
printf("\n\t\t\t  =   Recherche par Cin:8                                      =");
printf("\n\t\t\t  =   Fidelisation :9                                          =");
printf("\n\t\t\t  =   Affichage de la liste 10                                 =");
printf("\033[0m ");
printf("\033[0;31m ");
printf("\n\t\t\t  =   Quitter Application :0                                   =");
printf("\033[0m ");
printf("\n\t\t\t  ============================The end===========================\n");
printf("Entrer votre choix:");
printf("\033[0;33m ");
scanf("%d",&choix);
printf("\033[0m ");
	switch(choix){
		case 1:
			start=AddCompte(start); 
			break;
		case 2:
			start=AddListCompte(start);
			break;
		case 3:
			Operation(start);
			break;	
		case 4:
			Ascendent(start);
			break;
		case 5:
			Descendent(start);
			break;
		case 6:
			AscChifre(start);
			break;
		case 7:
			DescChifre(start);
			break;
		case 8:
			Recherche(start);
			break;
		case 9:
			Fidelisation(start);
			break;
		case 10:
			afficher(start);
			break;
		default:
			printf("\033[0;31m ");
			printf("\n Quitter Application:[oui][non]\n");
			printf("\033[0m ");				
}
system("pause");
system("cls");
}while(choix!=0);
	return 0;
}
