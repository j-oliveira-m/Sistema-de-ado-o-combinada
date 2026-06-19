#include "RepositorioPets.h"
#include <iostream>

    using namespace std;

    void RepositorioPets::adicionar(const Pet& pet){
        pets.push_back(pet);
}

    Pet RepositorioPets::buscarPorId(int id) {
        for (auto& p : pets){
            if(p.getId() == id) return p;
        }
        cout << "Pet nao encontrado!\n";
        return Pet();
}

    void RepositorioPets::listarPets() {
        for (auto& p : pets){
            p.exibirPet();
        }
}