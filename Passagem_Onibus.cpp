#include <iostream>
#include <Windows.h>
#include <string>
	using namespace std;

// Definindo struct de cadastro de passagem

typedef struct 
{
	char nome[60], ida_volta[4];
	string origem, destino;
	long long int cpf;
	int idade, ida_dia, ida_mes, volta_dia, volta_mes, hora_ida, hora_volta, banco;
	float valor;
	
}tipo_passagem;

// Definindo o struct com as cidades cobertas, distancias e horarios

typedef struct{
	
	string cidades[8] = {"Santa Cruz do Rio Pardo", "Jacarezinho", "Carlopolis","Cambara", "Piraju", "Joaquin Tavora", "RibeirÃ£o do Sul", "Ourinhos"};
						
	float kms[7][8] = 
	{
		
		{0, 63.8, 80.7, 60.8, 34, 51.3, 102.9, 35.4},
		{0, 0, 64.5, 20.1, 83.5, 53.3, 54.9, 22.9},
		{0, 0, 0, 88.1, 60.4, 24.4, 101.5, 74.2},
		{0, 0, 0, 0, 82.5, 69.5, 41.1, 26.1},
		{0, 0, 0, 0, 0, 84.4, 87.8, 60.4},
		{0, 0, 0, 0, 0, 0, 105.6, 78.6},
		{0, 0, 0, 0, 0, 0, 0, 28.5},
		
	};
	
	int horas[4] = {6, 8, 14, 18};
	
}tipo_cidades;


// Assinaturas de funções

void Msn();
void comprar_passagem(tipo_passagem *, int);
void verificar(tipo_passagem *, int);
void linha();
	
int main()
{
	//Contador indentifica o numero de alocoções realizadas dentro do registrador de passagem
	int contador = 0;
	
		back1:
		system("cls");
		Msn();
	
	// Registra as passagems confirmadas
	tipo_passagem registrador[50];
	
	// identfica a escolha do usuario
	int escolha;
	cout << "Oque deseja fazer:\n[ 1 ] Comprar passagem\n[ 2 ] Verificar passagem\n[ 3 ] Sair\n -> ";
	cin >> escolha;
	
	// Leva ao caminha do escolha
	switch( escolha )
	{
		case 1:

			comprar_passagem(registrador, contador);
			contador++;
			goto back1;
				
		case 2:
				
			verificar(registrador, contador);
			break;
				
		case 3:
				
			exit( 0 );
			
		default:

			cout << "Seleï¿½ï¿½o invalida. Tente novamente mais tarde" << endl;
			system("cls");	
		}
	
	return 0;
}

	// Função de da boas vindas	
void Msn()
{
	
	cout << endl << "---------------------------  Seja bem vindo a Planet Express  ---------------------------" << endl << endl;
	
}
	// Função responsavel pela coleta de dados das passagens
void comprar_passagem(tipo_passagem *r, int c)
{
		
	tipo_passagem p;
	tipo_cidades cidades;
		
		system("cls");
	cout << endl << "---------------------------  Comprar passagem  ---------------------------" << endl << endl;	
		
	cout << "Digite seu nome completo:\n -> ";
		
		// Coleta do Nome
	fflush(stdin);
	gets(p.nome);
	fflush(stdin);
		
		// Coleta da IDADE
	cout << "Digite sua idade:\n -> ";
	cin >>  p.idade;
		
		// Verificação da IDADE
	if ( p.idade < 18)
	{
			
		cout << "Invalido. Para comprar passagem deve ser maior de 18 anos...\nPara realizar o agendamento da passagem peï¿½a a um adulto responsavel\n";
		Sleep(4000);
		return;
			
	}
	
		// Coleta de CPf
	cout << "Digite seu CPF\n -> ";
	cin >> p.cpf;
		
		back1:
		system("cls");
		
		// todas as cidades que posso registrar
	cout << "\nCidades que a planet express cobre:\n\nCodigo\t\tCidade" << endl;
		
	linha();
		
	for(int i = 0; i < 8; i++)
	{
			
		cout << "  " << i << " ---------- " << cidades.cidades[i] << endl;
	}
		
	linha();
	
		// coleta do codigo da cidade de ORIGEM
	int origem , destino;
		
	cout << "Codigo da origem -> ";
	cin >> origem;
	
		// Verificação de existencia de cidade
	if ( origem < 0 or origem > 7)
	{
			
		cout << "Codigo invalido, insira apenas os codigos da tabela" << endl;
		Sleep(3000);
			
			goto back1;
			
	}
	
		// coleta do codigo da cidade de ORIGEM
	cout << "Codigo do destino -> ";
	cin >> destino;
	
		// Verificação de existencia de cidade		
	if ( origem < 0 or origem > 7)
	{
			
		cout << "Codigo invalido, insira apenas os codigos da tabela" << endl;
			
			Sleep(3000);
			goto back1;
				
	}
		
	cout << endl;
	
		// tranferencia das variaveis para a struct p
	p.origem = cidades.cidades[origem];
	p.destino = cidades.cidades[destino];
		
		// Verificação de cidades iguais
	if ( origem == destino )
	{
		
		linha();
			
		cout << "Invalido. Origem -> " << cidades.cidades[origem] << ", Destino -> " <<cidades.cidades[origem] << endl;
			
		linha();
		
		Sleep(3000);
		goto back1;
			
	}
	
		system("cls");
		
		// Pedido de Ida e Vouta
	cout << "Deseja agendar a volta [Sim/Nao]?\n -> ";
	fflush(stdin);
	gets(p.ida_volta);
	fflush(stdin);
		
	system("cls");
		
		// Coleta das variaveis caso seja necessario
	cout << "Digite o DIA de Ida [ Ex: 01, 02, 03 ...]:\n -> ";
	cin >> p.ida_dia;
	cout << "Digite o MES de Ida [ Ex: 01 - janeiro, 02 - fevereiro ... ]:\n -> " << p.ida_dia << "/";
	cin >> p.ida_mes;
		
		back2:
			
	linha();
		
		// Seleção de dia
	cout << "Selecione um dos horarios disponiveis para IDA:\n\nCodigo\t\tHorarios\n";
		
	linha();
		
		// Impreção de horarios deisponiveis
	for(int a = 0; a < 4; a++)
	{
			
		cout << "  " << a << " -------------- " << cidades.horas[a] << ":00" << endl;
			
	}
		
	linha();
		
		// coleta de hora
	cout << "Codigo -> ";
	cin >> p.hora_ida;
		
		// Inspeção de existencia de hora
	if ( p.hora_ida < 0 or p.hora_ida > 3)
	{
			
			system("cls");
			
		cout << "Codigo invalido, insira apenas os codigos da tabela" << endl;
			
			Sleep(3);
			system("cls");
			goto back2;
				
	}
		
	if ( p.ida_volta[0] == 'S' or p.ida_volta[0] == 's')
	{
			
			system("cls");
			
		cout << "Digite o DIA de Volta[ Ex: 01, 02, 03 ... ]:\n -> ";
		cin >> p.volta_dia;
		cout << "Digite o MES de Volta [ Ex: 01 - janeiro, 02 - fevereiro ... ]:\n -> " << p.volta_dia << "/";
		cin >> p.volta_mes;
			
			back3:
			
		linha();
			
		cout << "Selecione um dos horarios disponiveis para VOLTA:\n\nCodigo\t\tHorarios\n";
			
		linha();
			
		for(int a = 0; a < 4; a++)
		{
			
			cout << "  " << a << " -------------- " << cidades.horas[a] << ":00" << endl;
				
		}
			
		linha();
			
		cout << "Codigo -> ";
		cin >> p.hora_volta;
		
		if ( p.hora_volta < 0 or p.hora_volta > 3)
		{
				
				system("cls");
					
			cout << "Codigo invalido, insira apenas os codigos da tabela" << endl;
			
				Sleep(3000);
				system("cls");
				goto back3;
				
		}
			
	}
		
		system("cls");
			
	int cont  = 1;
			
	for ( int a = 0; a < cont; a++ )
	{
			
		if ( (p.origem == r[a].origem and p.destino == r[a].destino) and (p.hora_ida == r[a].hora_ida)) cont++;
			
	}
		
	p.banco = cont;
	
	if ( origem > destino ) p.valor = cidades.kms[destino][origem] * 0.60 + 20;
	else p.valor = cidades.kms[origem][destino] * 0.60 + 20;
		
	if ( p.ida_volta[0] == 'S')
	{
			
		p.valor = p.valor * 2;
			
	}
	
	r[c] = p;
	
	cout << endl;
	cout << " --> Cadastro realizado com sucesso. Verifique a passagem na guia verificar do menu inicial." << endl;
	
		Sleep(7000);
		system("cls");
		
}

void linha()
{
	
	cout << "----------------------------------------" << endl;
	
}

void verificar(tipo_passagem *r, int c)
{
		system("cls");
		back1:
	
	long long int escolha;
	
	cout << "Digite seu CPF: \n -> ";
	cin >> escolha;
	
		system("cls");
		linha();
	
	int pos = -1;
	
	for(int i = 0; i < c; i++)
	{
		
		if(r[i].cpf == escolha)
		{
			
			pos = i;
			
		}
		
	}
	
	if (pos == -1)
	{
		
		cout << "CPF invalido. Tente novamente." << endl;
			Sleep(5000);
			goto back1;
		
	}
	
		system("cls");

		
	cout << endl << endl << " ---------- Informacões de viagem ---------- " << endl << endl;

	
	
}

