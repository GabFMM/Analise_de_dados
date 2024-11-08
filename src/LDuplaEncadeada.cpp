#include "../headers/LDuplaEncadeada.h"

#define CAMINHO_ARQUIVO_NOVO "assets/listas_novas/NomeRG.txt"

// Possivel melhoria
#define CAMINHO_ARQUIVO_10_NOVO "assets/listas_novas/NomeRG10_novo.txt"
#define CAMINHO_ARQUIVO_50_NOVO "assets/listas_novas/NomeRG50_novo.txt"
#define CAMINHO_ARQUIVO_100_NOVO "assets/listas_novas/NomeRG100_novo.txt"
#define CAMINHO_ARQUIVO_1K_NOVO "assets/listas_novas/NomeRG1K_novo.txt"
#define CAMINHO_ARQUIVO_10K_NOVO "assets/listas_novas/NomeRG10K_novo.txt"
#define CAMINHO_ARQUIVO_1M_NOVO "assets/listas_novas/NomeRG1M_novo.txt"
#define CAMINHO_ARQUIVO_10M_NOVO "assets/listas_novas/NomeRG10M_novo.txt"

LDuplaEncadeada::LDuplaEncadeada() {
	_primeiro = nullptr;
	_ultimo = nullptr;
	_qtd = 0;
}

LDuplaEncadeada::~LDuplaEncadeada() {
	No* atual = nullptr;
	No* aux = nullptr;

	if (_primeiro != nullptr && _ultimo != nullptr) {
		atual = _primeiro;
		while (atual != nullptr) {
			aux = atual;
			atual = atual->proximo;
			delete aux;
		}
	}	
}

// ------------------------------- METODOS T1 -----------------------------------------------------

void LDuplaEncadeada::inserirComeco(const char* nome, unsigned int RG){
	// Atualiza a quantidade
	_qtd++;

	auto inicio = std::chrono::high_resolution_clock::now();
	int i,
		posicao = 0,
		comparacoes = 0,
		modificacoes = 0;
	No* atual = new No;

	atual->info._RG = RG;
	for (i = 0; nome[i] != '\0'; i++) {
		atual->info._nome[i] = nome[i];
		comparacoes++;
	}
	atual->info._nome[i] = '\0';

	comparacoes++;
	if (_primeiro == nullptr) {
		_primeiro = atual;
		_ultimo = atual;
		atual->proximo = nullptr;
		atual->anterior = nullptr;
		modificacoes += 4;
	}
	else {
		atual->anterior = nullptr;
		atual->proximo = _primeiro;
		_primeiro->anterior = atual;
		_primeiro = atual;
		modificacoes += 4;

		auto fim = std::chrono::high_resolution_clock::now();

		auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
		auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
		auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

		std::cout
			<< "Numero de RG e nome armazenados.\n\n"
			<< "Numero de RG: " << RG << "\n"
			<< "Nome da pessoa: " << nome << "\n"
			<< "Posicao na lista: " << 1 << "\n"
			<< "Numero de comparacoes: " << comparacoes << "\n"
			<< "Numero de modificacoes: " << modificacoes << "\n\n"
			<< "Tempo de Execucao:\n"
			<< "-> " << duracaoSegundos.count() << " s\n"
			<< "-> " << duracaoMilissegundos.count() << " ms\n"
			<< "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
			<< std::endl;
	}
}
void LDuplaEncadeada::inserirFinalDetalhado(const char* nome, unsigned int RG) {
	// Atualiza a quantidade
	_qtd++;

	auto inicio = std::chrono::high_resolution_clock::now();
	int posicao = 0,
		comparacoes = 0,
		modificacoes = 0;
	No* atual = new No;
	int i;

	atual->info._RG = RG;
	for (i = 0; nome[i] != '\0'; i++)
		atual->info._nome[i] = nome[i];
	atual->info._nome[i] = '\0';

	comparacoes++;
	if (_primeiro == nullptr) {
		_primeiro = atual;
		_ultimo = atual;
		atual->proximo = nullptr;
		atual->anterior = nullptr;
		modificacoes += 4;

		return;
	}

	atual->proximo = nullptr;
	atual->anterior = _ultimo;
	_ultimo->proximo = atual;
	_ultimo = atual;
	modificacoes += 4;

	auto fim = std::chrono::high_resolution_clock::now();

	auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
	auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
	auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

	std::cout
		<< "Numero de RG e nome armazenados.\n\n"
		<< "Numero de RG: " << RG << "\n"
		<< "Nome da pessoa: " << nome << "\n"
		<< "Posicao na lista: " << _qtd << "\n"
		<< "Numero de comparacoes: " << comparacoes << "\n"
		<< "Numero de modificacoes: " << modificacoes << "\n\n"
		<< "Tempo de Execucao:\n"
		<< "-> " << duracaoSegundos.count() << " s\n"
		<< "-> " << duracaoMilissegundos.count() << " ms\n"
		<< "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
		<< std::endl;
}
void LDuplaEncadeada::inserirFinalSimples(const char* nome, unsigned int RG){
	// Atualiza a quantidade
	_qtd++;

	No *atual = new No;
	int i;

	atual->info._RG = RG;
	for (i = 0; nome[i] != '\0'; i++)
		atual->info._nome[i] = nome[i];
	atual->info._nome[i] = '\0';

	if (_primeiro == nullptr) {
		_primeiro = atual;
		_ultimo = atual;
		atual->proximo = nullptr;
		atual->anterior = nullptr;

		return;
	}

	atual->proximo = nullptr;
	atual->anterior = _ultimo;
	_ultimo->proximo = atual;
	_ultimo = atual;
}
void LDuplaEncadeada::inserir(int posicao, const char* nome, unsigned int RG){
	auto inicio = std::chrono::high_resolution_clock::now();

	No* atual = nullptr;
	No* novo  = nullptr;
	int posicaoAtual = 0,
		modificacoes = 0,
		comparacoes  = 0;

	comparacoes += 2;
	if (posicao > _qtd) {
		std::cout << "Nao exite posicao " << posicao << "." << std::endl;
		return;
	}
	else if (posicao < _qtd / 2) {
		atual = _primeiro;
		posicaoAtual = 1;

		while (posicaoAtual < posicao) {
			atual = atual->proximo;
			posicaoAtual++;
			comparacoes++;
		}

		novo = new No;
		novo->info._RG = RG;
		int i;
		for (i = 0; nome[i] != '\0'; i++)
			novo->info._nome[i] = nome[i];
		novo->info._nome[i] = '\0';

		if (atual == _primeiro) {
			atual->anterior = novo;
			novo->proximo = atual;
			novo->anterior = nullptr;
			_primeiro = novo;
		}
		else {
			atual->anterior->proximo = novo;
			novo->anterior = atual->anterior;
			atual->anterior = novo;
			novo->proximo = atual;
		}
		
	}
	else {
		atual = _ultimo;
		posicaoAtual = _qtd;

		while (posicaoAtual > posicao) {
			atual = atual->anterior;
			posicaoAtual--;
			comparacoes++;
		}

		novo = new No;
		novo->info._RG = RG;
		int i;
		for (i = 0; nome[i] != '\0'; i++)
			novo->info._nome[i] = nome[i];
		novo->info._nome[i] = '\0';

		if (atual == _ultimo) {
			atual->proximo = novo;
			novo->anterior = atual;
			novo->proximo = nullptr;
			_ultimo = novo;
		}
		else {
			atual->anterior->proximo = novo;
			novo->anterior = atual->anterior;
			atual->anterior = novo;
			novo->proximo = atual;
		}
	}
	// Atualiza a quantidade de nos
	_qtd++;

	auto fim = std::chrono::high_resolution_clock::now();

	auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
	auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
	auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

	std::cout
		<< "Numero de RG e nome armazenados.\n\n"
		<< "Numero de RG: " << RG << "\n"
		<< "Nome da pessoa: " << nome << "\n"
		<< "Posicao na lista: " << posicao << "\n"
		<< "Numero de comparacoes: " << comparacoes << "\n"
		<< "Numero de modificacoes: " << modificacoes << "\n\n"
		<< "Tempo de Execucao:\n"
		<< "-> " << duracaoSegundos.count() << " s\n"
		<< "-> " << duracaoMilissegundos.count() << " ms\n"
		<< "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
		<< std::endl;
}
void LDuplaEncadeada::removerComeco(){
	auto inicio = std::chrono::high_resolution_clock::now();
	int comparacoes = 0,
		modificacoes = 0;
	unsigned int rg = 0;
	char nome[30]{ '\0' };

	rg = _primeiro->info._RG;
	for (int i = 0; _primeiro->info._nome[i] != '\0'; i++) {
		comparacoes++;
		nome[i] = _primeiro->info._nome[i];
	}

	comparacoes++;
	if (_primeiro == nullptr) {
		std::cout << "\nA lista nao possui RG's cadastrados.\n" << std::endl;
		return;
	}
	// Atualiza a quantidade
	_qtd--;

	comparacoes++;
	if (_primeiro->proximo != nullptr) {
		modificacoes++;
		_primeiro->proximo->anterior = nullptr;
	}
	modificacoes++;
	_primeiro = _primeiro->proximo;

	auto fim = std::chrono::high_resolution_clock::now();
	auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
	auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
	auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

	std::cout
		<< "Dados deletados.\n\n"
		<< "Numero de RG: " << rg << "\n"
		<< "Nome da pessoa: " << nome << "\n"
		<< "Posicao na lista: " << 1 << "\n"
		<< "Numero de comparacoes: " << comparacoes << "\n"
		<< "Numero de modificacoes: " << modificacoes << "\n\n"
		<< "Tempo de Execucao:\n"
		<< "-> " << duracaoSegundos.count() << " s\n"
		<< "-> " << duracaoMilissegundos.count() << " ms\n"
		<< "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
		<< std::endl;
}
void LDuplaEncadeada::removerFinal(){
	auto inicio = std::chrono::high_resolution_clock::now();
	int comparacoes = 0,
		modificacoes = 0;
	unsigned int rg = 0;
	char nome[30]{ '\0' };

	rg = _ultimo->info._RG;
	for (int i = 0; _ultimo->info._nome[i] != '\0'; i++) {
		comparacoes++;
		nome[i] = _ultimo->info._nome[i];
	}

	comparacoes++;
	if (_ultimo == nullptr) {
		std::cout << "\nA lista nao possui RG's cadastrados.\n" << std::endl;
		return;
	}
	comparacoes++;
	// Atualiza a quantidade
	_qtd--;
	if (_ultimo->anterior != nullptr) {
		modificacoes++;
		_ultimo->anterior->proximo = nullptr;
	}
	modificacoes++;
	_ultimo = _ultimo->anterior;

	auto fim = std::chrono::high_resolution_clock::now();
	auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
	auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
	auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

	std::cout
		<< "Dados deletados.\n\n"
		<< "Numero de RG: " << rg << "\n"
		<< "Nome da pessoa: " << nome << "\n"
		<< "Numero de comparacoes: " << comparacoes << "\n"
		<< "Numero de modificacoes: " << modificacoes << "\n\n"
		<< "Tempo de Execucao:\n"
		<< "-> " << duracaoSegundos.count() << " s\n"
		<< "-> " << duracaoMilissegundos.count() << " ms\n"
		<< "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
		<< std::endl;
}
void LDuplaEncadeada::remover(int posicao){
	auto inicio = std::chrono::high_resolution_clock::now();

	No* atual = nullptr;
	int posicaoAtual = 0,
		modificacoes = 0,
		comparacoes = 0;

	comparacoes += 2;
	if (posicao > _qtd) {
		std::cout << "Nao exite posicao " << posicao << "." << std::endl;
	}
	else if (posicao < _qtd / 2) {
		atual = _primeiro;
		posicaoAtual = 1;

		while (posicaoAtual < posicao) {
			atual = atual->proximo;
			posicaoAtual++;
			comparacoes++;
		}
	}
	else {
		atual = _ultimo;
		posicaoAtual = _qtd;

		while (posicaoAtual > posicao) {
			atual = atual->anterior;
			posicaoAtual--;
			comparacoes++;
		}
	}
	// Caso especial: remover o primeiro nó
	comparacoes++;
	if (atual == _primeiro) {
		modificacoes++;
		_primeiro = atual->proximo;
		comparacoes++;
		if (_primeiro != nullptr) {
			modificacoes++;
			_primeiro->anterior = nullptr;
		}
	}
	// Caso especial: remover o último nó
	else if (atual == _ultimo) {
		comparacoes++;
		modificacoes++;
		_ultimo = atual->anterior;
		comparacoes++;
		if (_ultimo != nullptr) {
			modificacoes++;
			_ultimo->proximo = nullptr;
		}
	}
	// Caso geral: remover um nó do meio
	else {
		atual->anterior->proximo = atual->proximo;
		atual->proximo->anterior = atual->anterior;
		modificacoes += 2;
	}
	
	auto fim = std::chrono::high_resolution_clock::now();
	auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
	auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
	auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

	std::cout
		<< "Dados deletados.\n\n"
		<< "Numero de RG: " << atual->info._RG << "\n"
		<< "Nome da pessoa: " << atual->info._nome << "\n"
		<< "Numero de comparacoes: " << comparacoes << "\n"
		<< "Numero de modificacoes: " << modificacoes << "\n\n"
		<< "Tempo de Execucao:\n"
		<< "-> " << duracaoSegundos.count() << " s\n"
		<< "-> " << duracaoMilissegundos.count() << " ms\n"
		<< "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
		<< std::endl;

	delete atual;  // Libera a memória do nó removido
	_qtd--;
}
void LDuplaEncadeada::procurar(unsigned int RG){
	auto inicio = std::chrono::high_resolution_clock::now();
	int posicao = 0,
		comparacoes = 0,
		modificacoes = 0;

	comparacoes += 2;
	if (_ultimo == nullptr || _primeiro == nullptr) {
		std::cout << "\nA lista nao possui RG's cadastrados.\n";
		return;
	}

	No* atual = _primeiro;
	bool encontrou = false;

	while (atual != nullptr) {
		comparacoes++;
		posicao++;

		if (atual->info._RG == RG) {
			encontrou = true;
			comparacoes++;
			break;
		}
		else {
			atual = atual->proximo;
		}
	}

	comparacoes++;
	if (!encontrou) {
		std::cerr << "\nNumero de RG nao encontrado.\n";
		return;
	}

	auto fim = std::chrono::high_resolution_clock::now();

	auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
	auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
	auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

	std::cout
		<< "Numero de RG encontrado.\n\n"
		<< "Numero de RG: " << atual->info._RG << "\n"
		<< "Nome da pessoa: " << atual->info._nome << "\n"
		<< "Posicao na lista: " << posicao << "\n"
		<< "Numero de comparacoes: " << comparacoes << "\n"
		<< "Numero de modificacoes: " << modificacoes << "\n\n"
		<< "Tempo de Execucao:\n"
		<< "-> " << duracaoSegundos.count() << " s\n"
		<< "-> " << duracaoMilissegundos.count() << " ms\n"
		<< "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
		<< std::endl;
}
void LDuplaEncadeada::mostrar(){
	No* atual = _primeiro; // Começa do primeiro nó

	while (atual != nullptr) {
		// Mostra o nome
		for (int i = 0; atual->info._nome[i] != '\0'; i++)
			std::cout << atual->info._nome[i];

		// Mostra o RG
		std::cout << " " << atual->info._RG << '\n';

		// Passa para o próximo nó
		atual = atual->proximo;
	}
}
void LDuplaEncadeada::salvarLista(){
	No* atual = nullptr;

	std::ofstream arquivo(CAMINHO_ARQUIVO_NOVO);

	if (!arquivo.is_open()) {
		std::cout << "Caminho do arquivo a ser salvo esta incorreto." << std::endl;
		return;
	}

	atual = _primeiro;
	while (atual != nullptr) {
		arquivo << atual->info._nome << "," << atual->info._RG << "\n";
		atual = atual->proximo;
	}
}

// ------------------------------- METODOS T2 ----------------------------------------------------

void LDuplaEncadeada::selectionSort() {
	No* atual = nullptr;
	No* menor = _primeiro;
	No* aux = _primeiro;

	while (aux != nullptr) {
		atual = aux->proximo;

		// Procura pelo menor RG
		while (atual != nullptr) {
			if (atual->info._RG < menor->info._RG) {
				menor = atual;
			}
			atual = atual->proximo;
		}

		// Troca as informações se 'menor' for diferente de 'aux'
		if (menor != aux) {
			std::swap(menor->info, aux->info);
		}

		// Atualiza o aux
		aux = aux->proximo;

		// Reinicia o menor
		menor = aux;
	}
}