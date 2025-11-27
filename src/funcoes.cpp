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
    num2 = (senha/100)%10;
    num3 = (senha/10)%10;
    num4 = senha%10;

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

bool compararSenhas(int senhaMaquina, int senhaUsuario) {
    int m1 = senhaMaquina / 1000;
    int m2 = (senhaMaquina / 100) % 10;
    int m3 = (senhaMaquina / 10) % 10;
    int m4 = senhaMaquina % 10;

    int u1 = senhaUsuario / 1000;
    int u2 = (senhaUsuario / 100) % 10;
    int u3 = (senhaUsuario / 10) % 10;
    int u4 = senhaUsuario % 10;

    char res1 = '_', res2 = '_', res3 = '_', res4 = '_';
    int acertos_O = 0;

    if (u1 == m1) { res1 = 'O'; u1 = 0; m1 = 0; acertos_O++; }
    if (u2 == m2) { res2 = 'O'; u2 = 0; m2 = 0; acertos_O++; }
    if (u3 == m3) { res3 = 'O'; u3 = 0; m3 = 0; acertos_O++; }
    if (u4 == m4) { res4 = 'O'; u4 = 0; m4 = 0; acertos_O++; }

    if (acertos_O == 4) {
        cout << "OOOO" << endl;
        return true;
    }

    if (u1 > 0) {
        if (u1 == m1 && m1 > 0) { res1 = 'X'; m1 = 0; }
        else if (u1 == m2 && m2 > 0) { res1 = 'X'; m2 = 0; }
        else if (u1 == m3 && m3 > 0) { res1 = 'X'; m3 = 0; }
        else if (u1 == m4 && m4 > 0) { res1 = 'X'; m4 = 0; }
    }

    if (u2 > 0) {
        if (u2 == m1 && m1 > 0) { res2 = 'X'; m1 = 0; }
        else if (u2 == m2 && m2 > 0) { res2 = 'X'; m2 = 0; }
        else if (u2 == m3 && m3 > 0) { res2 = 'X'; m3 = 0; }
        else if (u2 == m4 && m4 > 0) { res2 = 'X'; m4 = 0; }
    }

    if (u3 > 0) {
        if (u3 == m1 && m1 > 0) { res3 = 'X'; m1 = 0; }
        else if (u3 == m2 && m2 > 0) { res3 = 'X'; m2 = 0; }
        else if (u3 == m3 && m3 > 0) { res3 = 'X'; m3 = 0; }
        else if (u3 == m4 && m4 > 0) { res3 = 'X'; m4 = 0; }
    }

    if (u4 > 0) {
        if (u4 == m1 && m1 > 0) { res4 = 'X'; m1 = 0; }
        else if (u4 == m2 && m2 > 0) { res4 = 'X'; m2 = 0; }
        else if (u4 == m3 && m3 > 0) { res4 = 'X'; m3 = 0; }
        else if (u4 == m4 && m4 > 0) { res4 = 'X'; m4 = 0; }
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
