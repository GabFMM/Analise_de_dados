#include "../headers/LSequencial.h"

#define CAMINHO_ARQUIVO_NOVO "assets/listas_novas/NomeRG.txt"

// Possivel melhoria
#define CAMINHO_ARQUIVO_10_NOVO "assets/listas_novas/NomeRG10_novo.txt"
#define CAMINHO_ARQUIVO_50_NOVO "assets/listas_novas/NomeRG50_novo.txt"
#define CAMINHO_ARQUIVO_100_NOVO "assets/listas_novas/NomeRG100_novo.txt"
#define CAMINHO_ARQUIVO_1K_NOVO "assets/listas_novas/NomeRG1K_novo.txt"
#define CAMINHO_ARQUIVO_10K_NOVO "assets/listas_novas/NomeRG10K_novo.txt"
#define CAMINHO_ARQUIVO_1M_NOVO "assets/listas_novas/NomeRG1M_novo.txt"
#define CAMINHO_ARQUIVO_10M_NOVO "assets/listas_novas/NomeRG10M_novo.txt"

// ----------------------------------------- OBSERVACOES ---------------------------------------------------------

// 1. Posicao = indice + 1

// ------------------------------------------ METODOS -------------------------------------------------------------

LSequencial::LSequencial() {
    _tam = 0;
    _posicao = 0;
    _lista = nullptr;
}

LSequencial::~LSequencial() {
    if(_lista != nullptr)
        delete[] _lista;
}

// ------------------------------------------ METODOS T1 ---------------------------------------------------------

void LSequencial::mostrar() {
    for (unsigned int i = 0; i < _posicao; i++) {
        // Mostra o nome
        std::cout << _lista[i]._nome;
        std::cout << ' ';
        // Mostra o RG
        std::cout << _lista[i]._RG << '\n';
    }
    std::cout << '\n';
}

void LSequencial::adicionarInformacao(unsigned int rg, const char* nome) {
    int i;

    // Verifica se a lista esta cheia
    if (static_cast<int>(_posicao) == _tam) {
        _tam += _tam * 0.2f;
        Informacao* informacao = new Informacao[_tam];

        for (unsigned int i = 0; i < _posicao; i++) {
            informacao[i]._RG = _lista[i]._RG;
            strcpy_s(informacao[i]._nome, sizeof(informacao[i]._nome), _lista[i]._nome);
        }

        _lista = informacao;
    }

    // Adiciona o RG na ultima posicao
    _lista[_posicao]._RG = rg;

    // Adiciona o nome
    for (i = 0; nome[i] != '\0'; i++)
        _lista[_posicao]._nome[i] = nome[i];
    _lista[_posicao]._nome[i] = '\0';

    // Muda a posicao atual na lista
    _posicao++;
}

void LSequencial::inserirFinal(unsigned int rg, const char* nome) {
    auto inicio = std::chrono::high_resolution_clock::now();

    int i;
    int comparacoes = 0,
        modificacoes = 0;

    // Verifica se a lista esta cheia
    if (static_cast<int>(_posicao) == _tam) {
        _tam *= 1.25f;
        Informacao* informacao = new Informacao[_tam];

        for (unsigned int i = 0; i < _posicao; i++) {
            informacao[i]._RG = _lista[i]._RG;
            strcpy_s(informacao[i]._nome, sizeof(informacao[i]._nome), _lista[i]._nome);
        }

        _lista = informacao;
    }

    _lista[_posicao]._RG = rg;
    modificacoes++;
    for (i = 0; nome[i] != '\0'; i++) {
        comparacoes++;
        modificacoes++;
        _lista[_posicao]._nome[i] = nome[i];
    }
    modificacoes++;
    _lista[_posicao]._nome[i] = '\0';

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
    auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout
        << "Informacoes salvas na lista.\n\n"
        << "Numero de RG: " << rg << "\n"
        << "Nome da pessoa: " << nome << "\n"
        << "Posicao na lista: " << _posicao + 1 << "\n"
        << "Numero de comparacoes: " << comparacoes << "\n"
        << "Numero de modificacoes: " << modificacoes << "\n\n"
        << "Tempo de Execucao:\n"
        << "-> " << duracaoSegundos.count() << " s\n"
        << "-> " << duracaoMilissegundos.count() << " ms\n"
        << "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
        << std::endl;

    // Atualiza a posicao
    _posicao++;
}

void LSequencial::inserir(int posicao, unsigned int rg, const char* nome) {
    // Verifica se existe posicao
    if (posicao > static_cast<int>(_posicao) + 1 || posicao < 1) {
        std::cout << "\nPosicao " << posicao << " invalida.\n\n";
        return;
    }
    // Verifica se a lista esta cheia
    if (static_cast<int>(_posicao) == _tam) {
        _tam *= 1.25f;
        Informacao* informacao = new Informacao[_tam];

        for (unsigned int i = 0; i < _posicao; i++) {
            informacao[i]._RG = _lista[i]._RG;
            strcpy_s(informacao[i]._nome, sizeof(informacao[i]._nome), _lista[i]._nome);
        }

        _lista = informacao;
    }

    // Comeca o metodo

    auto inicio = std::chrono::high_resolution_clock::now();
    int comparacoes = 0,
        modificacoes = 0;

    for (int i = static_cast<int>(_posicao); i > posicao - 1; i--) {
        comparacoes++;
        // Atualiza o RG
        modificacoes++;
        _lista[i]._RG = _lista[i - 1]._RG;
        // Atualiza o nome
        int j;
        for (j = 0; _lista[i - 1]._nome[j] != '\0'; j++) {
            comparacoes++;
            modificacoes++;
            _lista[i]._nome[j] = _lista[i - 1]._nome[j];
        }
        modificacoes++;
        _lista[i]._nome[j] = '\0';
    }

    // Insere o RG e o nome
    modificacoes++;
    _lista[posicao - 1]._RG = rg;
    int i;
    for (i = 0; nome[i] != '\0'; i++) {
        comparacoes++;
        modificacoes++;
        _lista[posicao - 1]._nome[i] = nome[i];
    }
    modificacoes++;
    _lista[posicao - 1]._nome[i] = '\0';

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
    auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout
        << "Informacoes salvas na lista.\n\n"
        << "Numero de RG: " << rg << "\n"
        << "Nome da pessoa: " << nome << "\n"
        << "Posicao na lista: " << posicao << "\n"
        << "Numero de comparacoes: " << comparacoes << "\n"
        << "Numero de modificacoes: " << modificacoes << "\n\n"
        << "Tempo de Execucao:\n"
        << "-> " << duracaoSegundos.count() << " s\n"
        << "-> " << duracaoMilissegundos.count() << " ms\n"
        << "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
        << std::endl;

    // Atualiza a posicao
    _posicao++;
}

void LSequencial::inserirComeco(unsigned int rg, const char* nome) {
    auto inicio = std::chrono::high_resolution_clock::now();

    int comparacoes = 0,
        modificacoes = 0;

    // Verifica se a lista esta cheia
    comparacoes++;
    if (static_cast<int>(_posicao) == _tam) {
        _tam *= 1.25f;
        Informacao* informacao = new Informacao[_tam];

        for (unsigned int i = 0; i < _posicao; i++) {
            informacao[i]._RG = _lista[i]._RG;
            strcpy_s(informacao[i]._nome, sizeof(informacao[i]._nome), _lista[i]._nome);
        }

        _lista = informacao;
    }

    // Empurra a lista
    for (int i = static_cast<int>(_posicao); i > 0; i--) {
        comparacoes++;
        // Atualiza o RG
        modificacoes++;
        _lista[i]._RG = _lista[i - 1]._RG;
        // Atualiza o nome
        int j;
        for (j = 0; _lista[i - 1]._nome[j] != '\0'; j++) {
            comparacoes++;
            modificacoes++;
            _lista[i]._nome[j] = _lista[i - 1]._nome[j];
        }
        modificacoes++;
        _lista[i]._nome[j] = '\0';
    }

    // Insere o RG e o nome
    modificacoes++;
    _lista[0]._RG = rg;
    int i;
    for (i = 0; nome[i] != '\0'; i++) {
        comparacoes++;
        modificacoes++;
        _lista[0]._nome[i] = nome[i];
    }
    modificacoes++;
    _lista[0]._nome[i] = '\0';

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
    auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout
        << "Informacoes salvas na lista.\n\n"
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

    // Atualiza a posicao
    _posicao++;
}

void LSequencial::criarLista(int tam) {
    _tam = tam;
    _lista = new Informacao[_tam];
    _posicao = 0;
}

void LSequencial::procurar(unsigned int RG) {
    auto inicio = std::chrono::high_resolution_clock::now();

    int i;
    bool encontrou = false;
    int comparacoes = 0,
        modificacoes = 0,
        posicao = 1;

    for (i = 0; i < static_cast<int>(_posicao); i++) {
        comparacoes++;

        if (_lista[i]._RG != RG) {
            comparacoes++;
            posicao++;
        }
        else {
            encontrou = true;

            break;
        }
    }

    comparacoes++;
    if (!encontrou) {
        std::cout << "Numero de RG nao encontrado." << std::endl;
        return;
    }

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
    auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout 
        << "Numero de RG encontrado.\n\n"
        << "Numero de RG: " << _lista[i]._RG << "\n"
        << "Nome da pessoa: " << _lista[i]._nome << "\n"
        << "Posicao na lista: " << posicao << "\n"
        << "Numero de comparacoes: " << comparacoes << "\n"
        << "Numero de modificacoes: " << modificacoes << "\n\n"
        << "Tempo de Execucao:\n" 
        << "-> " << duracaoSegundos.count() << " s\n"
        << "-> " << duracaoMilissegundos.count() << " ms\n"
        << "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
        << std::endl;
}

void LSequencial::removerComeco() {
    auto inicio = std::chrono::high_resolution_clock::now();

    unsigned int rg = 0;
    char nome[20]{ '\0' };
    int i;
    int comparacoes = 0,
        modificacoes = 0;

    // Verifica se a lista esta vazia
    comparacoes++;
    if (!_posicao) {
        std::cout << "A lista esta vazia.\n\n";
        return;
    }

    // Copia as informacoes
    rg = _lista[0]._RG;
    for (i = 0; _lista[0]._nome[i] != '\0'; i++) {
        nome[i] = _lista[0]._nome[i];
        comparacoes++;
    }

    // Mover a lista
    for (int i = 1; i < static_cast<int>(_posicao); i++) {
        comparacoes++;
        // Move o RG
        _lista[i - 1]._RG = _lista[i]._RG;
        modificacoes++;
        // Move o nome
        int j;
        for (j = 0; _lista[i]._nome[j] != '\0'; j++)
            _lista[i - 1]._nome[j] = _lista[i]._nome[j];
        _lista[i - 1]._nome[j] = '\0';
    }

    // Atualiza a quantidade de itens
    _posicao--;
    modificacoes++;

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
    auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout
        << "Informacoes deletadas.\n\n"
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

void LSequencial::removerFinal() {
    auto inicio = std::chrono::high_resolution_clock::now();

    unsigned int rg = 0;
    char nome[20]{ '\0' };
    int i;
    int comparacoes = 0,
        modificacoes = 0;

    // Verifica se a lista esta vazia
    comparacoes++;
    if (!_posicao) {
        std::cout << "A lista esta vazia.\n\n";
        return;
    }
    
    // Copia as informacoes
    rg = _lista[_posicao - 1]._RG;
    for (i = 0; _lista[_posicao - 1]._nome[i] != '\0'; i++) {
        nome[i] = _lista[_posicao - 1]._nome[i];
        comparacoes++;
    }

    // Atualiza a quantidade de itens
    _posicao--;
    modificacoes++;

    // Apaga a informacao
    modificacoes += 21;
    _lista[_posicao]._RG = 0;
    for (int i = 0; i < 20; i++)
        _lista[_posicao]._nome[i] = '\0';

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
    auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout
        << "Informacoes deletadas.\n\n"
        << "Numero de RG: " << rg << "\n"
        << "Nome da pessoa: " << nome << "\n"
        << "Posicao na lista: " << _posicao << "\n"
        << "Numero de comparacoes: " << comparacoes << "\n"
        << "Numero de modificacoes: " << modificacoes << "\n\n"
        << "Tempo de Execucao:\n"
        << "-> " << duracaoSegundos.count() << " s\n"
        << "-> " << duracaoMilissegundos.count() << " ms\n"
        << "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
        << std::endl;
}

void LSequencial::remover(int posicao) {
    // Verifica se existe posicao
    if (posicao > static_cast<int>(_posicao) || posicao < 1) {
        std::cout << "\nPosicao " << posicao << " invalida.\n\n";
        return;
    }

    // Comeca o metodo

    auto inicio = std::chrono::high_resolution_clock::now();

    unsigned int rg = 0;
    char nome[20]{ '\0' };
    int i;
    int comparacoes = 0,
        modificacoes = 0;

    // Copia as informacoes removidas
    rg = _lista[posicao - 1]._RG;
    for (i = 0; _lista[posicao - 1]._nome[i] != '\0'; i++) {
        comparacoes++;
        nome[i] = _lista[posicao - 1]._nome[i];
    }

    for (i = posicao - 1; i < static_cast<int>(_posicao); i++) {
        comparacoes++;
        // Muda o RG
        modificacoes++;
        _lista[i]._RG = _lista[i + 1]._RG;
        // Muda o nome
        int j;
        for (j = 0; _lista[i + 1]._nome[j] != '\0'; j++) {
            comparacoes++;
            modificacoes++;
            _lista[i]._nome[j] = _lista[i + 1]._nome[j];
        }
        modificacoes++;
        _lista[i]._nome[j] = '\0';
    }
    _posicao--;
    modificacoes++;

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
    auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout
        << "Informacoes deletadas.\n\n"
        << "Numero de RG: " << rg << "\n"
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

void LSequencial::salvarLista() {
    // Abre o arquivo
    std::ofstream arquivo(CAMINHO_ARQUIVO_NOVO);

    // Verifica se existe
    if (!arquivo.is_open()) {
        std::cout << "O caminho do arquivo esta incorreto.\n\n";
        return;
    }

    // Salva o conteudo da lista no arquivo
    for (int i = 0; i < static_cast<int>(_posicao); i++)
        arquivo << _lista[i]._nome << "," << _lista[i]._RG << "\n";
    
    // Retorno
    std::cout << "Lista salva com sucesso.\n\n";
}

// ------------------------------------------- METODOS T2 ---------------------------------------------------

bool LSequencial::verificarOrdem() {
    for (unsigned int i = 1; i < _posicao; i++) 
        if (_lista[i - 1]._RG > _lista[i]._RG) 
            return false;
        
    return true;
}

void LSequencial::procurarBinario(unsigned int RG) {
    auto inicio = std::chrono::high_resolution_clock::now();

    int comparacoes = 0,
        modificacoes = 0;

    // Inicio da logica

    bool encontrou = false;
    unsigned int minimo = 0;
    unsigned int maximo = _posicao - 1;
    unsigned int posicaoAtual = 0;

    while (!encontrou) {
        comparacoes += 3;
        posicaoAtual = minimo + (maximo - minimo) / 2;

        if (_lista[posicaoAtual]._RG > RG) {
            maximo = posicaoAtual - 1;
            
        }
        else if(_lista[posicaoAtual]._RG < RG){
            minimo = posicaoAtual + 1;
        }
        else {
            encontrou = true;
        }
    }

    if (encontrou) {
        // Fim da logica

        auto fim = std::chrono::high_resolution_clock::now();

        auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
        auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
        auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

        std::cout
            << "Numero de RG encontrado.\n\n"
            << "Numero de RG: " << _lista[posicaoAtual]._RG << "\n"
            << "Nome da pessoa: " << _lista[posicaoAtual]._nome << "\n"
            << "Posicao na lista: " << posicaoAtual + 1 << "\n"
            << "Numero de comparacoes: " << comparacoes << "\n"
            << "Numero de modificacoes: " << modificacoes << "\n\n"
            << "Tempo de Execucao:\n"
            << "-> " << duracaoSegundos.count() << " s\n"
            << "-> " << duracaoMilissegundos.count() << " ms\n"
            << "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
            << std::endl;
    }
}

void LSequencial::selectionSort() {
    auto inicio = std::chrono::high_resolution_clock::now();

    int comparacoes = 0,
        modificacoes = 0;

    // Inicia o metodo

    unsigned int indiceCerto = 0;
    unsigned int indiceErrado = 0;
    unsigned int RG = 0;
    char nome[20]{ '\0' };

    mostrar();

    while (indiceCerto < _posicao - 1) {
        comparacoes++;
        // Inicializa o índice de erro no índice correto atual
        indiceErrado = indiceCerto;

        // Procura pelo menor RG
        for (unsigned int i = indiceCerto + 1; i < _posicao; i++) {
            comparacoes += 2;
            if (_lista[indiceErrado]._RG > _lista[i]._RG) {
                indiceErrado = i;
            }
        }

        // Troca os elementos
        strcpy_s(nome, sizeof(nome), _lista[indiceCerto]._nome);
        RG = _lista[indiceCerto]._RG;

        strcpy_s(_lista[indiceCerto]._nome, sizeof(_lista[indiceCerto]._nome), _lista[indiceErrado]._nome);
        _lista[indiceCerto]._RG = _lista[indiceErrado]._RG;

        strcpy_s(_lista[indiceErrado]._nome, sizeof(_lista[indiceErrado]._nome), nome);
        _lista[indiceErrado]._RG = RG;

        modificacoes += 6;

        // Atualiza o indice arrumado
        indiceCerto++;

        // Mostra a lista
        mostrar();
    }
    
    auto fim = std::chrono::high_resolution_clock::now();

    auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
    auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout
        << "Numero de comparacoes: " << comparacoes << "\n"
        << "Numero de modificacoes: " << modificacoes << "\n\n"
        << "Tempo de Execucao:\n"
        << "-> " << duracaoSegundos.count() << " s\n"
        << "-> " << duracaoMilissegundos.count() << " ms\n"
        << "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
        << std::endl;
}

void LSequencial::insertionSort() {
    auto inicio = std::chrono::high_resolution_clock::now();

    int comparacoes = 0,
        modificacoes = 0;

    // Inicia o metodo
    unsigned int j;
    unsigned int RG = 0;
    char nome[20]{ '\0' };

    mostrar();

    for (unsigned int i = 1; i < _posicao; i++) {
        comparacoes++;
        int j = i - 1;

        // Copia os dados em variáveis auxiliares
        unsigned int RG = _lista[i]._RG;
        char nome[20];
        strcpy_s(nome, sizeof(nome), _lista[i]._nome);

        // Desloca elementos para encontrar a posição correta para `RG`
        while (j >= 0 && _lista[j]._RG > RG) {
            _lista[j + 1]._RG = _lista[j]._RG;
            strcpy_s(_lista[j + 1]._nome, sizeof(_lista[j + 1]._nome), _lista[j]._nome);
            modificacoes += 2;

            j--;
            comparacoes++; // Conta cada comparação feita no `while`
        }

        // Insere o elemento na posição correta
        _lista[j + 1]._RG = RG;
        strcpy_s(_lista[j + 1]._nome, sizeof(_lista[j + 1]._nome), nome);
        modificacoes += 2;

        // Exibe a lista atualizada
        mostrar();
    }

    // Fim da logica

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
    auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout
        << "Numero de comparacoes: " << comparacoes << "\n"
        << "Numero de modificacoes: " << modificacoes << "\n\n"
        << "Tempo de Execucao:\n"
        << "-> " << duracaoSegundos.count() << " s\n"
        << "-> " << duracaoMilissegundos.count() << " ms\n"
        << "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
        << std::endl;
}

void LSequencial::bobbleSort() {
    auto inicio = std::chrono::high_resolution_clock::now();

    int comparacoes = 0,
        modificacoes = 0;

    // Inicia o metodo

    while (!verificarOrdem()) {
        comparacoes++;
        for (unsigned int i = 1; i < _posicao; i++) {
            comparacoes += 2;
            if (_lista[i - 1]._RG > _lista[i]._RG) {
                std::swap(_lista[i - 1]._RG, _lista[i]._RG);
                std::swap(_lista[i - 1]._nome, _lista[i]._nome);
                modificacoes += 2;
            }
        }
        mostrar();
    }

    // Fim da logica

    auto fim = std::chrono::high_resolution_clock::now();

    auto duracaoSegundos = std::chrono::duration<double>(fim - inicio);
    auto duracaoMilissegundos = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    auto duracaoMicrosegundos = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout
        << "Numero de comparacoes: " << comparacoes << "\n"
        << "Numero de modificacoes: " << modificacoes << "\n\n"
        << "Tempo de Execucao:\n"
        << "-> " << duracaoSegundos.count() << " s\n"
        << "-> " << duracaoMilissegundos.count() << " ms\n"
        << "-> " << duracaoMicrosegundos.count() << " microsegundos\n"
        << std::endl;
}