#include <iostream>
#include <random>

using namespace std;

int geradorDeSenha(){
    random_device rd;
    uniform_int_distribution<> distrib(1,6);
    mt19937 gen(rd());

    int num1, num2, num3, num4, senha;
    num1 = distrib(gen);
    num2 = distrib(gen);
    num3 = distrib(gen);
    num4 = distrib(gen);

    senha = num1*1000 + num2*100 + num3*10 + num1;
    return senha;
    }

int senhaUsuario(){
    int senha, num1, num2, num3 ,num4;
    
    cin >> senha;
    num1 = senha%1000;
    num2 = (senha - num1*1000)%100;
    num3 = (senha - num1*1000 - num2*100)%10;
    num4 = (senha - num1*1000 - num2*100 - num3*10);

    while (num1 > 6 || num2 > 6 || num3 > 6 || num4 > 6) {
        cout << "Nenhum dos digitos da senha deve ser maior que 6" << endl;
        cin >> senha;
        num1 = senha%1000;
        num2 = (senha - num1*1000)%100;
        num3 = (senha - num1*1000 - num2*100)%10;
        num4 = (senha - num1*1000 - num2*100 - num3*10);
    }

    return senha;
}

bool comparadorDeSenha(int senhaMaquina,int senhaDoUsuario){
    int n1Usuario, n2Usuario, n3Usuario, n4Usuario, n1Maquina, n2Maquina, n3Maquina, n4Maquina;
    char res1 = 'O', res2 = 'O', res3 = 'O' , res4 = 'O';

    n1Usuario = senhaDoUsuario%1000;
    n2Usuario = (senhaDoUsuario - n1Usuario*1000)%100;
    n3Usuario = (senhaDoUsuario - n1Usuario*1000 - n2Usuario *100)%10;
    n4Usuario = (senhaDoUsuario - n1Usuario*1000 - n2Usuario *100 - n3Usuario*10);

    n1Maquina = senhaMaquina%1000;
    n2Maquina = (senhaMaquina - n1Maquina*1000)/100;
    n3Maquina = (senhaMaquina - n1Maquina*1000 - n2Maquina*100)%10;
    n4Maquina = (senhaMaquina - n1Maquina*1000 - n2Maquina*100 - n3Maquina*10);

    if (n1Maquina!=n1Usuario){
        if (n1Usuario == n2Maquina || n1Usuario == n3Maquina || n1Usuario == n4Maquina){
            res1 = '_';
        } 
        res1 = 'X';
    }
    
    if (n2Maquina!=n3Usuario){
        if (n2Usuario == n1Maquina || n2Usuario == n3Maquina || n2Usuario == n4Maquina){
            res3 = '_';
        } 
        res2 = 'X';
    }

    if (n3Maquina!=n3Usuario){
        if (n3Usuario == n1Maquina || n3Usuario == n2Maquina || n3Usuario == n4Maquina){
            res3 = '_';
        } 
        res3 = 'X';
    }

    if (n4Maquina!=n4Usuario){
        if (n4Usuario == n1Maquina || n4Usuario == n2Maquina || n4Usuario == n3Maquina){
            res4 = '_';
        } 
        res4 = 'X';
    }

    if (res1 != 'O' && res2 != 'O' && res3 != 'O' && res4 != 'O'){
        cout << res1 << res2 << res3 << res4 << endl;

        return false;
    }

    return true;
}


