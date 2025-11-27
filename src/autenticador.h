#ifndef AUTENTICADOR_H
#define AUTENTICADOR_H
using namespace std;

int geradorDeSenha();
int gerarSenhaUsuario();
bool compararSenhas(int senhaMaquina,int senhaDoUsuario);
int selecaoNivel(int nivelDeDificuldade);

#endif