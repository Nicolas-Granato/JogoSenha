#include <iostream>
#include "src/autenticador.h"
using namespace std;

int main(){
    int variavelDeInicializacao, nivelDeDificuldade;

    cout << "------------- Inicio Jogo da Senha -------------\n1 - Iniciar            0 - Fechar o jogo" << endl;
    cin >> variavelDeInicializacao;

    while (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "ERRO: Digite apenas numeros!" << endl;
            cin >> variavelDeInicializacao;
    }        

    while (variavelDeInicializacao != 1 && variavelDeInicializacao != 0){
        cout << "ERRO: Opcao inexistente..." << endl;
        cout << "1 - Iniciar             0 - Fechar o jogo" << endl;
        cin >> variavelDeInicializacao;
    }
    
    while (variavelDeInicializacao == 1){

        cout << "\nBem vindo ao Jogo da Senha\n\nO computador gerou uma senha de 4 digitos.\nCada digito e um numero entre 1 e 6." << endl;
        cout << "\nSeu objetivo e descobrir a senha!\n" << endl;
    
        cout << "Escolha uma dificuldade:" << endl;  
        cout << "1 - Facil(10 tentativas)\n2 - Medio(7 tentativas)\n3 - Dificil(4 tentativas)" << endl;
        cin >> nivelDeDificuldade;

        while (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "ERRO: Digite apenas numeros!" << endl;
            cin >> nivelDeDificuldade;
        }  

        while (nivelDeDificuldade != 1 && nivelDeDificuldade != 2 && nivelDeDificuldade != 3){
            cout << "ERRO: Opcao inexistente..." << endl;
            cout << "1 - Facil(10 tentativas)\n2 - Medio(7 tentativas)\n3 - Dificil(4 tentativas)" << endl;
            cin >> nivelDeDificuldade;
        }

        cout << "\nGerando senha aleatoria...\n" << endl;
        int senhaMaquina = geradorDeSenha();
       
        for (int i = 0; i < selecaoNivel(nivelDeDificuldade); i++){
            int senhaUsuario = gerarSenhaUsuario();
            bool resposta = compararSenhas(senhaMaquina, senhaUsuario);

            if (resposta){
                cout << "Parabens!!!\nVoce venceu o jogo!!!" << endl; 
                break;
            }
            if (i == selecaoNivel(nivelDeDificuldade) - 1){
                cout << "A senha era: " << senhaMaquina << endl;
                cout << "Infelizmente nao foi dessa vez..." << endl;
            }
        }

        cout << "Deseja Jogar mais uma vez?\n(1 - Jogar novamente             0 - Fechar o jogo)" << endl;
        cin >> variavelDeInicializacao;

        while (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "ERRO: Digite apenas numeros!" << endl;
            cin >> variavelDeInicializacao;
        }    

        while (variavelDeInicializacao != 1 && variavelDeInicializacao != 0){
            cout << "ERRO: Opcao inexistente..." << endl;
            cout << "1 - Jogar novamente             0 - Fechar o jogo" << endl;
            cin >> variavelDeInicializacao;
        }
    }

    cout << "Saindo do jogo..." << endl;

    return 0;
}
