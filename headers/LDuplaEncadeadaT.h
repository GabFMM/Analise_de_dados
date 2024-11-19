#pragma once
#include <iostream>

template <class TIPO>
class LDuplaEncadeada {
private:

	No* _primeiro;
	No* _ultimo;
	unsigned int _quantidade;

public:

	class No {
	private:
		TIPO* _informacao;
		No* _proximo;
		No* _anterior;

	public:
		No(TIPO* informacao = nullptr) : _informacao(informacao), _proximo(nullptr), _anterior(nullptr) {}

		~No() {
			delete _informacao;
		}

		void setProximo(No* tipo) {
			_proximo = tipo;
		}
		No* getProximo() const {
			return _proximo;
		}

		void setAnterior(TIPO* tipo) {
			anterior = tipo
		}
		No* getAnterior() const {
			return _anterior;
		}

		void setInformacao(TIPO* tipo) {
			// Verifica se tipo existe
			if (tipo == nullptr) {
				std::cerr << "\nAcesso ao ponteiro negado. Ponteiro era nullptr.\n";
				return;
			}

			// Seta
			_informacao = tipo;
		}
		TIPO getInformacao() const {
			return *_informacao;
		}
	};

public:
	LDuplaEncadeada() : _primeiro(nullptr), _ultimo(nullptr), _quantidade(0) {};
	~LDuplaEncadeada() {
		No* atual = _primeiro;
		No* aux = nullptr;

		while (atual != nullptr) {
			aux = atual;
			atual = atual->getProximo();
			delete aux;
		}
	}

	// metodos de insercao
	void inserir(unsigned int posicao) {

	}
	void inserirComeco(TIPO* tipo) {
		No* novo = new No(tipo);
		_quantidade++;

		// Verifica se a lista possui somente um elemento 
		if (_ultimo == _primeiro) {
			_primeiro = novo;
			_ultimo = novo;
		}
		else {
			// novo->setAnterior(nullptr); presente no construtor
			novo->setProximo(_primeiro);
			_primeiro->setAnterior(novo);
			_primeiro = novo;
		}

	}
	void inserirFim(TIPO* tipo) {
		No* novo = new No(tipo);
		_quantidade++;

		// Verifica se a lista possui somente um elemento nela
		if (_ultimo == _primeiro) {
			_ultimo = novo;
			_primeiro = novo;
		}
		else {
			// novo->setProximo(nullptr); presente no construtor
			novo->setAnterior(_ultimo);
			_ultimo->setProximo(novo);
			_ultimo = novo;
		}
	}

	// metodos de remocao
	void removerComeco(){
		_quantidade--;

		_primeiro->getProximo()->getAnterior();

	}
	void removerFim(){}
	void remover(unsigned int posicao){}
};