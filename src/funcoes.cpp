#include <iostream>
#include <random>

using namespace std;

int geradorDeSenha(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1,6);

    int num1, num2, num3, num4, senha;
    num1 = distrib(gen);
    num2 = distrib(gen);
    num3 = distrib(gen);
    num4 = distrib(gen);

    senha = num1*1000 + num2*100 + num3*10 + num4;
    return senha;
    }

int gerarSenhaUsuario(){
    int senha, num1, num2, num3 ,num4;
    
    cin >> senha;

    num1 = senha/1000;
    num2 = (senha - num1*1000)/100;
    num3 = (senha - num1*1000 - num2*100)/10;
    num4 = (senha - num1*1000 - num2*100 - num3*10);

    while ((num1 > 6 || num2 > 6 || num3 > 6 || num4 > 6) || (senha < 1000 || senha > 9999)) {
        cout << "ERRO: senha invalida..." << endl;
        cout << "Escreva uma senha de 4 digitos, e que seus numeros estejam entre 1 e 6." << endl;
        cin >> senha;

        num1 = senha/1000;
        num2 = (senha - num1*1000)/100;
        num3 = (senha - num1*1000 - num2*100)/10;
        num4 = (senha - num1*1000 - num2*100 - num3*10);
    }

    return senha;
}

bool compararSenhas(int senhaMaquina,int senhaUsuario){
    int n1Usuario, n2Usuario, n3Usuario, n4Usuario, n1Maquina, n2Maquina, n3Maquina, n4Maquina;
    char res1 = 'O', res2 = 'O', res3 = 'O' , res4 = 'O';

    n1Usuario = senhaUsuario/1000;
    n2Usuario = (senhaUsuario - n1Usuario*1000)/100;
    n3Usuario = (senhaUsuario - n1Usuario*1000 - n2Usuario *100)/10;
    n4Usuario = (senhaUsuario - n1Usuario*1000 - n2Usuario *100 - n3Usuario*10);

    n1Maquina = senhaMaquina/1000;
    n2Maquina = (senhaMaquina - n1Maquina*1000)/100;
    n3Maquina = (senhaMaquina - n1Maquina*1000 - n2Maquina*100)/10;
    n4Maquina = (senhaMaquina - n1Maquina*1000 - n2Maquina*100 - n3Maquina*10);

    if (n1Maquina!=n1Usuario){
        if (n1Usuario == n2Maquina || n1Usuario == n3Maquina || n1Usuario == n4Maquina){
            res1 = '_';
        } else {
            res1 = 'X';
        }
    }
    
    if (n2Maquina!=n2Usuario){
        if (n2Usuario == n1Maquina || n2Usuario == n3Maquina || n2Usuario == n4Maquina){
            res2 = '_';
        } else {
            res2 = 'X';
        }
    }

    if (n3Maquina!=n3Usuario){
        if (n3Usuario == n1Maquina || n3Usuario == n2Maquina || n3Usuario == n4Maquina){
            res3 = '_';
        } else {
            res3 = 'X';
        }
    }

    if (n4Maquina!=n4Usuario){
        if (n4Usuario == n1Maquina || n4Usuario == n2Maquina || n4Usuario == n3Maquina){
            res4 = '_';
        } else {
            res4 = 'X';
        }
    }

    if (res1 == 'O' && res2 == 'O' && res3 == 'O' && res4 == 'O'){
        return true;
    }

    cout << res1 << res2 << res3 << res4 << endl;

    return false;
}

int selecaoNivel(int nivelDeDificuldade){
    int tentativas;
    
    if (nivelDeDificuldade == 1){
        tentativas = 10;
    }
    if (nivelDeDificuldade == 2){
        tentativas = 7;
    }
    if (nivelDeDificuldade == 3){
        tentativas = 4;
    }

    return tentativas;
}
