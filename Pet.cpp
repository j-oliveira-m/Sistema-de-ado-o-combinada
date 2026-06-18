#include "Pet.h"
#include <iostream>
using namespace std;

Pet::Pet(int id, string nome, string tipo, int idade, string porte,
         bool possuiDeficiencia, bool castrado,
         bool gostaDePatio, bool adaptaAmbienteFechado,
         bool sociavelComAnimais, bool sociavelComCriancas,
         string estiloPet, bool carenteAtencao)
    : id(id), nome(nome), tipo(tipo), idade(idade), porte(porte),
      possuiDeficiencia(possuiDeficiencia), castrado(castrado),
      gostaDePatio(gostaDePatio), adaptaAmbienteFechado(adaptaAmbienteFechado),
      sociavelComAnimais(sociavelComAnimais), sociavelComCriancas(sociavelComCriancas),
      estiloPet(estiloPet), carenteAtencao(carenteAtencao) {}

Pet::Pet() : id(-1), nome(""), tipo(""), idade(0), porte(""),
             possuiDeficiencia(false), castrado(false),
             gostaDePatio(false), adaptaAmbienteFechado(false),
             sociavelComAnimais(false), sociavelComCriancas(false),
             estiloPet(""), carenteAtencao(false) {}

string Pet::getNome() const { return nome; }
string Pet::getTipo() const { return tipo; }
int Pet::getIdade() const { return idade; }
string Pet::getPorte() const { return porte; }
bool Pet::getPossuiDeficiencia() const { return possuiDeficiencia; }
bool Pet::getCastrado() const { return castrado; }

void Pet::editar(string novoNome, string novoPorte, int novaIdade) {
    nome = novoNome;
    porte = novoPorte;
    idade = novaIdade;
}

void Pet::cadastrarPet() {
    cout << "Digite o nome do pet: ";
    getline(cin, nome);

    cout << "Digite o tipo do animal: ";
    getline(cin, tipo);

    cout << "Digite a idade do animal: ";
    cin >> idade;
    cin.ignore();

    cout << "Digite o porte: ";
    getline(cin, porte);

    char resposta;
    cout << "Possui deficiencia (s/n): ";
    cin >> resposta;
    possuiDeficiencia = (resposta == 's' || resposta == 'S');

    cout << "Eh castrado (s/n): ";
    cin >> resposta;
    castrado = (resposta == 's' || resposta == 'S');

    cout << "Gosta de patio (s/n): ";
    cin >> resposta;
    gostaDePatio = (resposta == 's' || resposta == 'S');

    cout << "Se adapta bem em ambientes fechados (s/n): ";
    cin >> resposta;
    adaptaAmbienteFechado = (resposta == 's' || resposta == 'S');

    cout << "Se da bem com outros animais (s/n): ";
    cin >> resposta;
    sociavelComAnimais = (resposta == 's' || resposta == 'S');

    cout << "Se da bem com criancas (s/n): ";
    cin >> resposta;
    sociavelComCriancas = (resposta == 's' || resposta == 'S');

    cin.ignore();
    cout << "Estilo do pet (saideiro/caseiro): ";
    getline(cin, estiloPet);

    cout << "Eh carente de atencao (s/n): ";
    cin >> resposta;
    carenteAtencao = (resposta == 's' || resposta == 'S');
    cin.ignore();
}

void Pet::exibirPet() {
    cout << "\n--- Dados do Pet ---\n";
    cout << "ID: " << id << "\n";
    cout << "Nome: " << nome << "\n";
    cout << "Tipo: " << tipo << "\n";
    cout << "Idade: " << idade << "\n";
    cout << "Porte: " << porte << "\n";
    cout << "Deficiencia: " << (possuiDeficiencia ? "Sim" : "Nao") << "\n";
    cout << "Castrado: " << (castrado ? "Sim" : "Nao") << "\n";
    cout << "Gosta de patio: " << (gostaDePatio ? "Sim" : "Nao") << "\n";
    cout << "Adapta ambiente fechado: " << (adaptaAmbienteFechado ? "Sim" : "Nao") << "\n";
    cout << "Sociavel com animais: " << (sociavelComAnimais ? "Sim" : "Nao") << "\n";
    cout << "Sociavel com criancas: " << (sociavelComCriancas ? "Sim" : "Nao") << "\n";
    cout << "Estilo do pet: " << estiloPet << "\n";
    cout << "Carente de atencao: " << (carenteAtencao ? "Sim" : "Nao") << "\n";
}