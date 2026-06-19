#include "RepositorioAdotantes.h"
#include <iostream>
using namespace std;

    void RepositorioAdotantes::adicionar(const Adotante& adotante) {
        adotantes.push_back(adotante);
}
        Adotante RepositorioAdotantes::buscarPorId(int id) {
            for (auto& a : adotantes) {
                if (a.getId() == id) return a;
    }
            cout << "Adotante nao encontrado!\n";
            return Adotante(); // usa o construtor vazio
}

    void RepositorioAdotantes::listarAdotantes() {
        for (auto& a : adotantes) {
            a.exibirAdotante();
    }
}
