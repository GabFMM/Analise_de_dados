#pragma once

#include <iostream>
#include <utility>
#include <chrono>
#include <fstream>
#include "No.h"

class LDuplaEncadeada{
private:
	No* _primeiro;
	No* _ultimo;
	int _qtd;

public:
	LDuplaEncadeada();                                            
	~LDuplaEncadeada();
    
	// METODOS T1

	void inserirComeco(const char* nome, unsigned int RG);         // Concluido
	void inserirFinalDetalhado(const char* nome, unsigned int RG); // Concluido
	void inserirFinalSimples(const char* nome, unsigned int RG);   // Concluido
	void inserir(int posicao, const char* nome, unsigned int RG);  // Concluido
	void removerComeco();                                          // Concluido
	void removerFinal();                                           // Concluido
	void remover(int posicao);                                     // Concluido
	void procurar(unsigned int RG);                                // Concluido
	void mostrar();                                                // Concluido
	void salvarLista();                                            // Concluido

	// METODOS T2

	void selectionSort();                                         // Em processo (falta o detalhamento)
};