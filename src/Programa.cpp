#include "../headers/Programa.h"

#define CAMINHO_ARQUIVO_10 "assets/listas_originais/NomeRG10.txt"
#define CAMINHO_ARQUIVO_50 "assets/listas_originais/NomeRG50.txt"
#define CAMINHO_ARQUIVO_100 "assets/listas_originais/NomeRG100.txt"
#define CAMINHO_ARQUIVO_1K "assets/listas_originais/NomeRG1K.txt"
#define CAMINHO_ARQUIVO_10K "assets/listas_originais/NomeRG10K.txt"
#define CAMINHO_ARQUIVO_1M "assets/listas_originais/NomeRG1M.txt"
#define CAMINHO_ARQUIVO_10M "assets/listas_originais/NomeRG10M.txt"

// --------------- PRIVATE ---------------------------------- PRIVATE -------------------------------------------------

// ------------------------------------ METODOS MENU ------------------------------------------------

void Programa::selecionarArquivo() {
	std::cout
		<< "\tBem-vindo.\n\n"
		<< "Qual arquivo deseja ler?\n\n"
		<< "1. 10;\n"
		<< "2. 50;\n"
		<< "3. 100;\n"
		<< "4. 1K;\n"
		<< "5. 10K;\n"
		<< "6. 1M;\n"
		<< "7. 10M;\n\n"
		<< "Digite o numero (e nao o tamanho) do arquivo: \n";

	std::cin >> _arquivoSelecionado;
	while (_arquivoSelecionado < 1 || _arquivoSelecionado > 7) {
		std::cout
			<< "\nNumero informado incorreto.\n"
			<< "Tente novamente.\n";

		std::cin >> _arquivoSelecionado;
	}
}

void Programa::opcoesGerais() {
	_opcaoSelecionada = -1;

	std::cout
		<< "Agora escolha uma opcao: \n\n"
		<< "1. Inserir uma informacao no comeco das listas;\n"
		<< "2. Inserir uma informacao no final das listas;\n"
		<< "3. Inserir uma informacao em uma posicao escolhida das listas;\n"
		<< "4. Remover uma informacao no comeco das listas;\n"
		<< "5. Remover uma informacao no final das listas;\n"
		<< "6. Remover uma informacao em uma posicao escolhida das listas;\n"
		<< "7. Procurar uma informacao a partir do RG nas listas;\n"
		<< "8. Mostrar a lista na tela;\n"
		<< "9. Salvar a lista modificada em um arquivo .txt;\n"
		<< "10. Ordenar listas.\n\n"
		<< "0. Encerrar programa.\n";

	std::cin >> _opcaoSelecionada;
	while (_opcaoSelecionada < 0 || _opcaoSelecionada > 11) {
		std::cout
			<< "\nNumero informado incorreto.\n"
			<< "Tente novamente." << std::endl;

		std::cin >> _opcaoSelecionada;
	}

	switch (_opcaoSelecionada) {
	case 1:
		limparTela();
		inserirComeco();
		limparTela();
		break;
	case 2:
		limparTela();
		inserirFinalDetalhado();
		limparTela();
		break;
	case 3:
		limparTela();
		inserir();
		limparTela();
		break;
	case 4:
		limparTela();
		removerComeco();
		limparTela();
		break;
	case 5:
		limparTela();
		removerFinal();
		limparTela();
		break;
	case 6:
		limparTela();
		remover();
		limparTela();
		break;
	case 7:
		limparTela();
		opcoesProcurar();
		limparTela();
		break;
	case 8:
		limparTela();
		mostrarLista();
		limparTela();
		break;
	case 9:
		limparTela();
		salvarLista();
		limparTela();
		break;
	case 10:
		limparTela();
		opcoesOrdenar();
		limparTela();
	}
}

void Programa::opcoesOrdenar() {
	_opcaoSelecionada = -1;
	
	std::cout
		<< "Agora escolha um metodo para ordenar as listas: \n\n"
		<< "1. Selection Sort;\n"
		<< "2. Insertion Sort;\n"
		<< "3. Bobble Sort;\n"
		<< "\n0. Voltar;\n";
		
	std::fflush(stdin);

	std::cin >> _opcaoSelecionada;
	while (_opcaoSelecionada < 0 || _opcaoSelecionada > 3) {
		std::cout
			<< "\nNumero informado incorreto.\n"
			<< "Tente novamente." << std::endl;

		std::cin >> _opcaoSelecionada;
	}

	switch (_opcaoSelecionada) {
	case 1:
		limparTela();
		selectionSort();
		limparTela();
		break;
	case 2:
		limparTela();
		insertionSort();
		limparTela();
		break;
	case 3:
		limparTela();
		bobbleSort();
		limparTela();
		break;
	case 0:
		limparTela();
		opcoesGerais();
		limparTela();
		break;
	}
}

void Programa::opcoesProcurar() {
	_opcaoSelecionada = -1;

	std::cout
		<< "Agora escolha um metodo para procurar o RG: \n\n"
		<< "1. Busca sequencial;\n"
		<< "2. Busca binaria;\n"
		<< "\n0. Voltar;\n";


	std::cin >> _opcaoSelecionada;
	while (_opcaoSelecionada < 0 || _opcaoSelecionada > 2) {
		std::cout
			<< "\nNumero informado incorreto.\n"
			<< "Tente novamente." << std::endl;

		std::cin >> _opcaoSelecionada;
	}

	switch (_opcaoSelecionada) {
	case 1:
		limparTela();
		procurarSequencial();
		limparTela();
		break;
	case 2:
		limparTela();
		
		limparTela();
	case 0:
		limparTela();
		opcoesGerais();
		limparTela();
		break;
	}
}

void Programa::limparTela() {
#ifdef _WIN32
	system("cls");  // Windows
#else
	system("clear");  // Linux/macOS
#endif

}

void Programa::copiarArquivo() {
	char linha[30]{ '\0' };
	char nome[15]{ '\0' };
	char RG[9]{ 0 };
	std::ifstream arquivo;

	switch (_arquivoSelecionado) {
	case 1:
		arquivo.open(CAMINHO_ARQUIVO_10);
		_lSequencial.criarLista(15);
		break;
	case 2:
		arquivo.open(CAMINHO_ARQUIVO_50);

		_lSequencial.criarLista(75);
		break;
	case 3:
		arquivo.open(CAMINHO_ARQUIVO_100);

		_lSequencial.criarLista(150);
		break;
	case 4:
		arquivo.open(CAMINHO_ARQUIVO_1K);

		_lSequencial.criarLista(1500);
		break;
	case 5:
		arquivo.open(CAMINHO_ARQUIVO_10K);

		_lSequencial.criarLista(15000);
		break;
	case 6:
		arquivo.open(CAMINHO_ARQUIVO_1M);

		_lSequencial.criarLista(1500000);
		break;
	case 7:
		arquivo.open(CAMINHO_ARQUIVO_10M);

		_lSequencial.criarLista(12000000);
		break;
	}

	if (!arquivo.is_open()) {
		std::cout << "Erro ao abrir o arquivo." << std::endl;
		return;
	}

	int i;
	unsigned int rg = 0;
	while (arquivo.getline(linha, 30, '\n')) {
		for (i = 0; linha[i] != ','; i++)
			nome[i] = linha[i];

		i++;
		for (int j = 0; linha[i] != '\0'; j++, i++)
			RG[j] = linha[i];

		rg = std::atoi(RG);

		_lSequencial.adicionarInformacao(rg, nome);
		_lDuplaEncadeada.inserirFinalSimples(nome, rg);

		// Limpeza
		for (i = 0; nome[i] != '\0'; i++)
			nome[i] = '\0';
		for (i = 0; i < 9; i++)
			RG[i] = 0;
		rg = 0;
	}

	arquivo.close();
}

// ----------------------------------- METODOS T1 -----------------------------------------------------

void Programa::salvarLista() {
	_lSequencial.salvarLista();

	char c;
	std::cout << "Clique em qualquer tecla para voltar às opcoes" << std::endl;
	std::cin >> c;
}

void Programa::inserirComeco() {
	char nome[30]{ '\0' };
	unsigned int rg = 0;

	std::cout << "Digite o primeiro nome: " << std::endl;
	std::cin >> nome;

	std::cout << "Digite o numero de RG: " << std::endl;
	std::cin >> rg;

	std::cout << "\n\nLista sequencial:\n\n";
	_lSequencial.inserirComeco(rg, nome);
	
	std::cout << "\n\nLista duplamente sequenciada:\n\n";
	_lDuplaEncadeada.inserirComeco(nome, rg);
	
	char c;
	std::cin >> c;
}

void Programa::inserirFinalDetalhado() {
	char nome[30]{ '\0' };
	unsigned int rg = 0;

	std::cout << "Digite o primeiro nome: " << std::endl;
	std::cin >> nome;

	std::cout << "Digite o numero de RG: " << std::endl;
	std::cin >> rg;

	std::cout << '\n';

	std::cout << "Lista sequencial: \n\n";
	_lSequencial.inserirFinal(rg, nome);

	std::cout << "\n\nLista duplamente encadeada.\n\n";
	_lDuplaEncadeada.inserirFinalDetalhado(nome, rg);

	char c;
	std::cin >> c;
}

void Programa::inserir() {
	int posicao = 0;
	char nome[30]{ '\0' };
	unsigned int rg = 0;

	std::cout << "Em qual posicao deseja incluir?\n";
	std::cin >> posicao;

	std::cout << "Digite o primeiro nome: " << std::endl;
	std::cin >> nome;

	std::cout << "Digite o numero de RG: " << std::endl;
	std::cin >> rg;

	std::cout << std::endl;

	std::cout << "Lista Sequencial:\n\n";
	_lSequencial.inserir(posicao, rg, nome);

	std::cout << "Lista duplamente encadeada:\n\n";
	_lDuplaEncadeada.inserir(posicao, nome, rg);

	char c;
	std::cin >> c;
}

void Programa::removerComeco() {
	std::cout << "Lista Sequencial:\n\n";
	_lSequencial.removerComeco();

	std::cout << "Lista duplamente encadeada:\n\n";
	_lDuplaEncadeada.removerComeco();

	char c;
	std::cin >> c;
}

void Programa::removerFinal() {
	std::cout << "Lista sequencial:\n\n";
	_lSequencial.removerFinal();

	std::cout << "Lista duplamente encadeada:\n\n";
	_lDuplaEncadeada.removerFinal();

	char c;
	std::cin >> c;
}

void Programa::remover() {
	int posicao = 0;

	std::cout << "Qual posicao deseja remover?\n";
	std::cin >> posicao;

	std::cout << std::endl;

	std::cout << "Lista sequencial.\n\n";
	_lSequencial.remover(posicao);

	std::cout << "\nLista duplamente encadeada.\n\n";
	_lDuplaEncadeada.remover(posicao);

	char c;
	std::cin >> c;
}

void Programa::procurarSequencial() {
	unsigned int rg = 0;

	std::cout << "Qual o numero de RG?\n";
	std::cin >> rg;
	std::cout << std::endl;

	std::cout << "Lista sequencial:\n\n";
	_lSequencial.procurar(rg);
	std::cout << "\n\nLista duplamente encadeada:\n\n";
	_lDuplaEncadeada.procurar(rg);

	char c;
	std::cin >> c;
}

void Programa::mostrarLista() {
	std::cout << "Lista sequencial:\n\n";
	_lSequencial.mostrar();
	std::cout << "\n\nLista duplamente encadeada:\n\n";
	_lDuplaEncadeada.mostrar();

	char c;
	std::cin >> c;
}

// -------------------------------- METODOS T2 --------------------------------------------------------

void Programa::selectionSort() {
	_lSequencial.selectionSort();

	std::cout << "Feito com sucesso.\n";

	char c;
	std::cin >> c;
}

void Programa::insertionSort() {
	_lSequencial.insertionSort();

	std::cout << "Feito com sucesso.\n";

	char c;
	std::cin >> c;
}

void Programa::bobbleSort() {
	_lSequencial.bobbleSort();

	std::cout << "Feito com sucesso.\n";

	char c;
	std::cin >> c;
}

// --------------- PUBLIC ---------------------------------- PUBLIC ---------------------------------------

Programa::Programa() {
	_arquivoSelecionado = -1;
	_opcaoSelecionada = -1;

}

Programa::~Programa() {

}

void Programa::iniciar() {
	selecionarArquivo();
	copiarArquivo();
	limparTela();

	while (_opcaoSelecionada != 0) {
		opcoesGerais();
	}
}