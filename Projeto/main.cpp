#include <cstring>
#include <iostream>
#include "sequenceset.hpp"
#include "learquivo.hpp"

using namespace std;

int main() {
    sequenceset meuSeqSet( "teste.dat" );
    dado umDado;
    tipoChave umaChave;
    char operacao;

    do {
        try {
            cin >> operacao;
            switch ( operacao ) {
            case 'i': // inserir
                cin.ignore();
                getline( cin, umaChave );
                strcpy( umDado.nome, umaChave.c_str() );

                cin >> umaChave;
                strcpy( umDado.modalidade, umaChave.c_str() );

                cin >> umaChave;
                strcpy( umDado.nivel, umaChave.c_str() );

                cin >> umaChave;
                strcpy( umDado.inicio, umaChave.c_str() );

                cin >> umaChave;
                strcpy( umDado.termino, umaChave.c_str() );

                cin.ignore();
                getline( cin, umaChave );
                strcpy( umDado.area, umaChave.c_str() );

                meuSeqSet.inserirDado( umDado );
                break;
            case 'b': // buscar
                cin.ignore();
                getline( cin, umaChave );
                cin >> operacao;
                umDado = meuSeqSet.buscar( umaChave );
                cout << "Busca: " << umDado.nome << "/" << umDado.area << endl;
                break;
            case 'p': // mostrar estrutura
                meuSeqSet.imprimir();
                break;
            case 'd': // mostrar estrutura
                meuSeqSet.depurar();
                break;
            case 'a': // ler arquivo de entrada
                leArquivo( meuSeqSet );
                break;
            case 'j': //inicializar Arvore
                meuSeqSet.inicializarArvore();
                meuSeqSet.imprimirArvore();
                break;
            case 's': // sair
                // será tratado no while
                break;
            default:
                cout << "Opcao invalida!" << endl;
            }
        }
        catch ( runtime_error& e ) {
            cerr << e.what() << endl;
        }
    } while ( operacao != 's' );
    remove( "teste.dat" );
    return 0;
}
