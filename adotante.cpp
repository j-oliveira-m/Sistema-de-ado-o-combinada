#include "Adotante.h"

    Adotante::Adotante(int id, string nome, bool animalComdeficiencia, bool temPatio,
                   string preferenciaPorte, string estiloVida, bool temTempoLivre,
                   bool dispostoAtencao)
                    : id(id), nome(nome),temPatio(temPatio), preferenciaPorte(preferenciaPorte),
                    estiloVida(estiloVida), temTempoLivre(temTempoLivre),
                    dispostoAtencao(dispostoAtencao) {}

    Adotante::Adotante() : id(-1), nome(""), temPatio(false), preferenciaPorte(""),
                       estiloVida(""), temTempoLivre(false),
                       dispostoAtencao(false) {}


    void Adotante::cadastrarAdotante(){
        cout << "Digite o nome do adotante: ";
        getline(cin, nome);

        char resposta;

        cout << "Adotaria um animalzinho com deficiencia ou problemas de saude: (s/n): ";
        cin >> resposta;
        animalComdeficiencia = (resposta == 's' || resposta == 'S');
        cin.ignore();

        cout << "Possui patio: (s/n): ";
        cin >> resposta;
        temPatio = (resposta == 's' || resposta == 'S');
        cin.ignore();

        cout << "Preferencia de porte (pequeno/medio/grande): ";
        getline(cin, preferenciaPorte);

        cout << "Estilo de vida (saideiro/caseiro): ";
        getline(cin, estiloVida);

        cout << "Tem tempo livre? (s/n): ";
        cin >> resposta;
        temTempoLivre = (resposta == 's' || resposta == 'S');

        cout << "Disposto a dar atencao extra? (s/n): ";
        cin >> resposta;
        dispostoAtencao = (resposta == 's' || resposta == 'S');
        cin.ignore();
    }

    void Adotante::exibirAdotante() {
        cout << "\n--- Dados do Adotante ---\n";
        cout << "ID: " << id << "\n";
        cout << "Nome: " << nome << "\n";
        cout << "Adotaria um animalzinho com deficiencia ou problemas de saude: " << (animalComdeficiencia ? "Sim" : "Nao") << "\n";
        cout << "Possui patio: " << (temPatio ? "Sim" : "Nao") << "\n";
        cout << "Preferencia de porte: " << preferenciaPorte << "\n";
        cout << "Estilo de vida: " << estiloVida << "\n";
        cout << "Tempo livre: " << (temTempoLivre ? "Sim" : "Nao") << "\n";
        cout << "Disposto a dar atencao: " << (dispostoAtencao ? "Sim" : "Nao") << "\n";
}