/* Vetor Expansível - Pacote de dados
 *
 * by Joukim, Fevereiro de 2021 - Estrutura de Dados (GCC216)
 * Características da primeira implementação - fevereiro de 2021:
 * -> tamanho do pacote e tipo de dados definidos
 * -> em arquivo de configuração
 */
#include <iostream>
#include "configuracao.hpp"

using namespace std;

// essa classe também poderia se chamar bloco, pagina, packet ou pedaco
class pacote {
    friend class sequenceset;
    // classe não possui métodos públicos
    // objetos da classe são criados e manuseados
    // apenas pela classe sequenceset
    private:
    dado elementos[CAP_PACOTE];
    unsigned numElementos;
    int posProximoPacote;
    pacote() : numElementos( 0 ), posProximoPacote( POS_INVALIDA ) {}
    bool cheio() { return ( numElementos == CAP_PACOTE ); }
    void inserir( dado umDado );
    inline bool chaveEhMaiorQueTodos( tipoChave chave );
    inline bool chaveEhMenorQueTodos( tipoChave chave );
    void imprimir();
};

void pacote::inserir( dado umDado ) {
    int posicao = numElementos - 1;
    // Faz a procura pela posição de inserção do elemento de forma decrescente
    while ( ( posicao >= 0 ) && strcmp(umDado.nome , elementos[posicao].nome) < 0 ) {
        elementos[posicao + 1] = elementos[posicao];
        posicao--;
    }
    elementos[posicao + 1] = umDado;
    numElementos++;
}

void pacote::imprimir() {
    cout << "[";
    for ( unsigned i = 0; i < numElementos; i++ )
        cout << elementos[i];
    cout << "]";
}

bool pacote::chaveEhMaiorQueTodos( tipoChave chave ) {
    
    return ( strcmp( elementos[numElementos - 1].nome , chave.c_str() ) < 0);
}

bool pacote::chaveEhMenorQueTodos( tipoChave chave ) {
    return ( strcmp( elementos[0].nome , chave.c_str()) > 0);
}
