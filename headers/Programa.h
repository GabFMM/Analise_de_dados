#include "LSequencial.h"
#include "LDuplaEncadeada.h"
#include "Informacao.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>

class Programa {
private:
	LSequencial _lSequencial;
	LDuplaEncadeada _lDuplaEncadeada;
	int _arquivoSelecionado;
	int _opcaoSelecionada;

	// Metodos menu
	void selecionarArquivo();
	void opcoesGerais();
	void opcoesOrdenar();
	void opcoesProcurar();
	void limparTela();
	void copiarArquivo();

	// Metodos T1
	void salvarLista();
	void inserirComeco();
	void inserirFinalDetalhado();
	void inserir();
	void removerComeco();
	void removerFinal();
	void remover();
	void procurarSequencial();
	void mostrarLista();

	// Metodos T2
	void procurarBinario();
	void selectionSort();
	void insertionSort();
	void bobbleSort();
	void quickSort();

public:
	Programa();
	~Programa();

	void iniciar();
};