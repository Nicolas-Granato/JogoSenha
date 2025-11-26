#include <iostream>
#include "src/autenticador.h"
using namespace std;

int main(){
    int variavelDeInicializacao, nivelDeDificuldade;

    cout << "Inicio Jogo Senha\n1 - iniciar             0 - fechar o jogo" << endl;
    cin >> variavelDeInicializacao;

    while (variavelDeInicializacao != 1 && variavelDeInicializacao != 0){
        cout << "ERRO: Opcao inexistente..." << endl;
        cout << "1 - iniciar             0 - fechar o jogo" << endl;
        cin >> variavelDeInicializacao;
    }
    
    while (variavelDeInicializacao == 1){
    
        cout << "Escolha uma dificuldade:" << endl;  
        cout << "1 - Facil(10 tentativas)\n2 - Medio(7 tentativas)\n3 - Dificil(4 tentativas)" << endl;
        cin >> nivelDeDificuldade;

        while (nivelDeDificuldade != 1 && nivelDeDificuldade != 2 && nivelDeDificuldade != 3){
        cout << "ERRO: Opcao inexistente..." << endl;
        cout << "1 - Facil(10 tentativas)\n2 - Medio(7 tentativas)\n3 - Dificil(4 tentativas)" << endl;
        cin >> nivelDeDificuldade;
        }

        cout << "Gerando senha aleatoria..." << endl;
        int senhaMaquina = geradorDeSenha();
        cout << senhaMaquina << endl;
        
        cout << "Escreva uma senha de 4 digitos, e que seus numeros estejam entre 1 e 6." << endl;
        for (int i = 0; i < nivelDeDificuldade; i++){
            int senhaUsuario = gerarSenhaUsuario();
            
            bool resposta = compararSenhas(senhaMaquina, senhaUsuario);
            
            if (resposta == true){
                cout << "Parabens!!!\nVocê venceu o jogo!" << endl;
                break;
            }
        }

        cout << "Deseja Jogar mais uma vez?(1 - jogar novamente             0 - fechar o jogo)" << endl;
        cin >> variavelDeInicializacao;

        while (variavelDeInicializacao != 1 && variavelDeInicializacao != 0){
            cout << "ERRO: Opcao inexistente..." << endl;
            cout << "1 - jogar novamente             0 - fechar o jogo" << endl;
            cin >> variavelDeInicializacao;
        }
    }

    return 0;
}
