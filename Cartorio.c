#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavél por cuidar das string

int registro ()//função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");     //coletando informação do usuário
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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file ==NULL)
	{
		printf("Usuário não se encontra no sistema!.\n");
		system("pause");
	}
	fclose(file);
	
}

int main()
{
	int opcao=0;//definindo variáveis
	int laco=1;
	char senhadigitada [10]="a";//senha de login  
	int comparacao;
	
	
	
	printf("###Cartório da EBAC###\n\n");
	printf("Login de administrador!\n\n Digite a sua senha:");
	scanf("%s",senhadigitada);//senha
	
	comparacao=strcmp(senhadigitada,"admin");//senha
	
	if(comparacao==0)//validação da senha
	{
	
	system("cls");
    
	
	 for(laco=1;laco=1;)

     {
      system("cls"); //responsavel por limpar a tela

	  setlocale(LC_ALL,"Portuguese"); //definindo a linguagem 
	
	
	    printf("###Cartório da EBAC###\n\n"); //inicio do menu
	    printf ("Escolha a opcão desejada do menu:\n\n");
	    printf("\t1-Registrar nomes\n");
	    printf("\t2-Consultar nomes\n");
	    printf("\t3-Deletar nomes\n");
	    printf("\t4-Sair do sistema\n\n");
	    printf("Opção:"); //fim do menu
	
	    scanf("%d",&opcao);// armazenando a escolha do usuário
	
	    system("cls");
	 
	  switch(opcao)//inicio da seleção do menu
	  {
	  case 1:
	    registro();//chamada de funções
	    break;
	 
	  case 2:
	    consulta();
	    break;
	 
	  case 3:
	    deletar();
	    break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
	    
	  default:
	 	printf("Essa opção não esta disponivel!\n");
	    system("pause");
	    break;
	  }
	

	
    }
  }
  else
    printf("Senha incorreta!");
    
}
