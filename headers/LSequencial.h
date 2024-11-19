#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "Informacao.h"

class LSequencial {
private:
    unsigned int _tam;
    unsigned int _posicao;
    Informacao* _lista;

public:
    LSequencial();
    ~LSequencial();

    // ACESSO AOS ATRIBUTOS
    const unsigned int getPosicao() const;

    // METODOS T1
    void mostrar();                                                // Concluido
    void removerComeco();                                          // Concluido
    void removerFinal();                                           // Concluido
    void remover(int posicao);                                     // Concluido
    void salvarLista();                                            // Concluido
    void adicionarInformacao(unsigned int rg, const char* nome);   // Concluido
    void inserir(int posicao, unsigned int rg, const char* nome);  // Concluido
    void inserirComeco(unsigned int rg, const char* nome);         // Concluido
    void inserirFinal(unsigned int rg, const char* nome);          // Concluido
    void criarLista(int tam);                                      // Concluido
    void procurar(unsigned int RG);                                // Concluido
    
    // METODOS T2
    bool verificarOrdem();
    void procurarBinario(unsigned int RG);                                   // Concluido
    void selectionSort();                                                    // Concluido
    void insertionSort();                                                    // Concluido
    void bobbleSort();                                                       // Concluido
    void quickSort(unsigned int indiceInicial, unsigned int indiceFinal);    // Em processo
};