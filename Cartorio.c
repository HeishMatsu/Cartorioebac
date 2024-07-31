#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsav�l por cuidar das string

int registro ()//fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");     //coletando informa��o do usu�rio
	scanf("%s",cpf);                               //%s refere~se a string
	
	strcpy(arquivo,cpf);                           //responsavel por copiar os valores das string
	
	FILE*file;                                     //cria o arquivo 
	file=fopen(arquivo,"w");                       //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);                             //salvo valor da variavel
	fclose(file);                                  //fecha o arquivo
	
	file=fopen(arquivo,"a");                       
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado:  ");
	scanf("%s",nome);
	
	file=fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file ==NULL)
	{
		printf("Usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	fclose(file);
	
}

int main()
{
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)

    {
     system("cls"); //responsavel por limpar a tela

	 setlocale(LC_ALL,"Portuguese"); //definindo a linguagem 
	
	
	    printf("###Cart�rio da EBAC###\n\n"); //inicio do menu
	    printf ("Escolha a opc�o desejada do menu:\n\n");
	    printf("\t1-Registrar nomes\n");
	    printf("\t2-Consultar nomes\n");
	    printf("\t3-Deletar nomes\n\n\n");
	    printf("Op��o:"); //fim do menu
	
	    scanf("%d",&opcao);// armazenando a escolha do usu�rio
	
	    system("cls");
	 
	 switch(opcao)//inicio da sele��o do menu
	 {
	 case 1:
	    registro();//chamada de fun��es
	    break;
	 
	 case 2:
	    consulta();
	    break;
	 
	 case 3:
	    deletar();
	    break;	
	    
	 default:
	 	printf("Essa op��o n�o esta disponivel!\n");
	    system("pause");
	    break;
	 }
	
	
	
}
}
