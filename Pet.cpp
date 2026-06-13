#include "Pet.h"
#include <iostream>

using namespace std;

        Pet::Pet(int id, string nome, string tipo, int idade, string porte, bool possuiDeficiencia, bool castrado)
        : id(id), nome(nome), tipo(tipo), idade(idade), porte(porte), possuiDeficiencia(possuiDeficiencia), castrado(castrado) {}

            string Pet::getNome() const{ return nome; }
            string Pet::getTipo() const{ return tipo; }
            int Pet::getIdade() const { return idade; }
            string Pet::getPorte() const { return porte; }
            bool Pet::getPossuiDeficiencia() const { return possuiDeficiencia; }
            bool Pet::getCastrado() const { return castrado; }

void Pet::editar(string novoNome, string novoPorte, int novaIdade) {    
        nome = novoNome;
        porte = novoPorte;
        idade = novaIdade;
    }

    void Pet::cadastrarPet(){
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
        cout << "Possui deficiencia: (s/n): ";
        cin >> resposta;
        possuiDeficiencia = (resposta == 's' || resposta == 'S');

        cout << "E castrado: (s/n) : ";
        cin >> resposta;
        castrado = (resposta == 's' || resposta == 'S');
    }

    void Pet::exibirPet() {
        cout << "\n--- Dados do Pet ---\n";
        cout << "ID: " << id << "\n";
        cout << "Nome: " << nome << "\n";
        cout << "Tipo: " << tipo << "\n";
        cout << "Idade: " << idade << "\n";
        cout << "Porte: " << porte << "\n";
        cout << "Deficiência: " << (possuiDeficiencia ? "Sim" : "Não") << "\n";
        cout << "Castrado: " << (castrado ? "Sim" : "Não") << "\n";

    }