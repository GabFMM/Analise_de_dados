#pragma once
#include <iostream>

template <class TIPO>
class LDuplaEncadeada {
private:

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
	No* _primeiro;
	No* _ultimo;
	unsigned int _quantidade;

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
	void inserirComeco() {

	}
	void inserirFim(TIPO* tipo) {
		No* novo = new No(tipo);

		// Verifica se a lista possui somente um elemento nela
		if (_ultimo == _primeiro) {
			_ultimo = novo;
			_ultimo->setAnterior(_primeiro);
			_ultimo->setProximo(nullptr);
		}
		else {

		}
	}
};