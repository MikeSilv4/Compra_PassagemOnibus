#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
	using namespace std;

// Definindo struct de cadastro de passagem

typedef struct 
{
	char nome[60], ida_volta[4];
	int origem, destino;
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
void onibus(tipo_passagem *, int, int, int, int, int, int);
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
			goto back1;
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
		
	cout << "Codigo da origem -> ";
	cin >> p.origem;
	
		// Verificação de existencia de cidade
	if ( p.origem < 0 or p.origem > 7)
	{
			
		cout << "Codigo invalido, insira apenas os codigos da tabela" << endl;
		Sleep(3000);
			
			goto back1;
			
	}
	
		// coleta do codigo da cidade de DESTINO
	cout << "Codigo do destino -> ";
	cin >> p.destino;
	
		// Verificação de existencia de cidade		
	if ( p.destino < 0 or p.destino > 7)
	{
			
		cout << "Codigo invalido, insira apenas os codigos da tabela" << endl;
			
			Sleep(3000);
			goto back1;
				
	}
		
	cout << endl;
		
		// Verificação de cidades iguais
	if ( p.origem == p.destino )
	{
		
		linha();
			
		cout << "Invalido. Origem -> " << cidades.cidades[p.origem] << ", Destino -> " <<cidades.cidades[p.origem] << endl;
			
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
	cout << "Digite o DIA de Ida [ Ex: 1, 2, 3 ...]:\n -> ";
	cin >> p.ida_dia;
	cout << "Digite o MES de Ida [ Ex: 1 - janeiro, 2 - fevereiro ... ]:\n -> " << p.ida_dia << "/";
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
		
		// Verificação caso seja necessario ida e volta
	if ( p.ida_volta[0] == 'S' or p.ida_volta[0] == 's')
	{
			
			system("cls");
			
		cout << "Digite o DIA de Volta[ Ex: 1, 2, 3 ... ]:\n -> ";
		cin >> p.volta_dia;
		cout << "Digite o MES de Volta [ Ex: 1 - janeiro, 2 - fevereiro ... ]:\n -> " << p.volta_dia << "/";
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
			
	//int cont  = 1;
			
	/*	for ( int a = 0; a < c; a++ )
	{
			
		if ((p.origem == r[a].origem and p.destino == r[a].destino) and (p.hora_ida)) cont++;
			
	}*/
	
	//int esolha;
	cout << "Escolha o numero da poltrona que deseja:"<< endl;
	onibus(r, c, p.origem, p.destino, p.hora_ida, p.ida_dia, p.ida_mes);
	cout << "Descrição: \n I = Saida\n O = Pltronas reservadas \n X = Poltronas disponiveis\n XX = banco do condutor" << endl << endl;
	Sleep(20000);
	cout << "Selecione apenas poltronas disponiveis: \n -> ";
	cin >> p.banco;
	
	//p.banco = cont;
	
	if ( p.origem > p.destino ) p.valor = cidades.kms[p.destino][p.origem] * 0.60 + 20;
	else p.valor = cidades.kms[p.origem][p.destino] * 0.60 + 20;
		
	if ( p.ida_volta[0] == 'S')
	{
			
		p.valor = p.valor * 2;
			
	}
	
	r[c] = p;
	
	cout << endl;
	cout << " \n\n--> Cadastro realizado com sucesso. Verifique a passagem na guia verificar do menu inicial." << endl;
	
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
	
	long long int cpf;

	cout << "Digite seu CPF: \n -> ";
	cin >>cpf;
	
		system("cls");
		linha();
	
	int pos = -1;
	
	for(int i = 0; i < c; i++)
	{
		
		if(r[i].cpf == cpf)
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
	Sleep(1000);
	cout << "Seja bem vindo " << r[pos].nome << endl;
	Sleep(1000);
	cout << "Sua poutrona:  " << r[pos].banco << endl;
	Sleep(1000);
	cout << "--------------" << endl;
	cout << " XX          I " << endl;
	cout << "------  ------" << endl;
		
	int contador = r[pos].banco;
	
	for (int a = 0; a < 11; a++)
	{
		
		cout << "| ";
		if(contador == 1)
		{
			
			cout << "O ";
			contador = 44;
			
		}else
		{
			
			cout << "X ";
			contador--;	
			
		}
		
		if(contador == 1)
		{
			
			cout << "O    ";
			contador = 44;
			
		}else
		{
			
			cout << "X    ";
			contador--;	
			
		}
		
		if(contador == 1)
		{
			
			cout << "O ";
			contador = 44;
			
		}else
		{
			
			cout << "X ";
			contador--;	
			
		}
		
		if(contador == 1)
		{
			
			cout << "O ";
			contador = 44;
			
		}else
		{
			
			cout << "X ";
			contador--;	
			
		}
		
		cout << "|" << endl;
	
		
	}
	cout << "--------------" << endl;
	cout << "Descrição: \n I = Saida\n O = Banco reservado\n X = outros bancos\n XX = banco do condutor" << endl << endl;
	Sleep(1000);
	Sleep(1000);
	cout << "Data da Ida: " << r[pos].ida_dia << "/" << r[pos].ida_mes << " - " << r[pos].hora_ida << ":00;" << endl;
	
	if(r[pos].ida_volta[0] == 'S')
		cout << "Data da Volta: " << r[pos].volta_dia << "/" << r[pos].volta_mes << " - " << r[pos].hora_volta << ":00;" << endl;
		
	Sleep(1000);
	tipo_cidades cidades;
	cout << "Origem: " << cidades.cidades[r[pos].origem] << ";" << endl;
	Sleep(1000);
	cout << "Destino: " << cidades.cidades[r[pos].destino] << ";" << endl;
	Sleep(1000);
	cout << fixed << setprecision(2);
	cout << "Valor da passagem: R$" << r[pos].valor << endl << endl;
	Sleep(1000);
	cout << "** O valor da passagem deve ser pago somente ao embarcar no transporte.\n Desde ja agradecemos a preferencia :)\nDeseja voltar ao inicio[Sim/Nao]?" << endl;
	char escolha[4];
		back3:
	fflush(stdin);
	gets(escolha);
	fflush(stdin);
	
	if(escolha[0] == 'S')
	{
		
		system("cls");
		return;
	}
	
	else
		goto back3;
	
}

void onibus(tipo_passagem *r, int c, int origem, int destino, int hora, int dia, int mes)
{
	
	
	int contador = 0;
	
	for(int i = 0; i< c; i++)
	{
		
		if(r[i].origem == origem and r[i].destino == destino)
		{
			if(r[i].hora_ida == hora and r[i].ida_dia == dia)
			{
				 if(r[i].ida_mes == mes)
				 	contador++;
				 	
			}
		}
		
	}

	int numeroBanco[contador], tamanho = contador;
	
	contador = 0;
	
	cout << "    --------------" << endl;
	cout << "     XX          I " << endl;
	cout << "    ------  ------" << endl;
	
	for(int i = 0; i< c; i++)
	{	

		if(r[i].origem == origem and r[i].destino == destino)
		{
			if(r[i].hora_ida == hora and r[i].ida_dia == dia)
			{
				 if(r[i].ida_mes == mes)
				 {
				 	
				 	numeroBanco[contador] == r[i].banco;
					contador++;
					
				 }
			}
		}
		
	}
	
	int poltrona = 0;
	
	for (int a = 0; a < 11; a++)
	{
		
		int cache = 0;
		
		if(poltrona + 1 < 10)
			cout <<  poltrona+1 << "   | ";
		else
			cout <<  poltrona+1 << "  | ";
			
		poltrona++;
		for(int b = 0; b < contador; b++)
		{
			
			if(numeroBanco[b] == poltrona)
			{
				
				cache = 1;
				break;
				
			}
			
		}
		if(cache == 1)
		{
			
			cout << "O ";
			cache = 0;
			
		}else
		{
			
			cout << "X ";	
			
		}
		
		
		
		poltrona++;
		for(int b = 0; b < contador; b++)
		{
			
			if(numeroBanco[b] == poltrona)
			{
				
				cache = 1;
				break;
				
			}
			
		}
		if(cache == 1)
		{
			
			cout << "O    ";
			cache = 0;
			
		}else
		{
			
			cout << "X    ";	
			
		}
		
		
		
		poltrona++;
		for(int b = 0; b < contador; b++)
		{
			
			if(numeroBanco[b] == poltrona)
			{
				
				cache = 1;
				break;
				
			}
			
		}
		if(cache == 1)
		{
			
			cout << "O ";
			cache = 0;
			
		}else
		{
			
			cout << "X ";	
			
		}
		
		
		
		
		poltrona++;
		for(int b = 0; b < contador; b++)
		{
			
			if(numeroBanco[b] == poltrona)
			{
				
				cache = 1;
				break;
				
			}
			
		}
		if(cache == 1)
		{
			
			cout << "O ";
			cache = 0;
			
		}else
		{
			
			cout << "X ";	
			
		}
		
		cout << "|  " << poltrona << endl;
	}
	cout << "    --------------" << endl;
 } 

