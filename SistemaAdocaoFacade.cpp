#include "SistemaAdocaoFacade.h"
#include "PetFactory.h"
#include "AdotanteFactory.h"
#include "MatchStrategy.h"
#include <iostream>
using namespace std;

SistemaAdocaoFacade::SistemaAdocaoFacade() {}

    void SistemaAdocaoFacade::cadastrarPet() {
        Pet novoPet = PetFactory::criarPet(repoPets.proximoId());
        repoPets.adicionar(novoPet);
        cout << "Pet cadastrado com sucesso!\n";
}

    void SistemaAdocaoFacade::listarPets() {
        repoPets.listarPets();
}

    Pet SistemaAdocaoFacade::buscarPetPorId(int id) {
            return repoPets.buscarPorId(id);
}

    void SistemaAdocaoFacade::cadastrarAdotante() {
        Adotante novoAdotante = AdotanteFactory::criarAdotante(repoAdotantes.proximoId());
        repoAdotantes.adicionar(novoAdotante);
        cout << "Adotante cadastrado com sucesso!\n";
}

    void SistemaAdocaoFacade::listarAdotantes() {
        repoAdotantes.listarAdotantes();
}

    Adotante SistemaAdocaoFacade::buscarAdotantePorId(int id) {
    return repoAdotantes.buscarPorId(id);
}

// Novo: realizar match
    int SistemaAdocaoFacade::realizarMatch(int idAdotante, int idPet) {
        Adotante a = repoAdotantes.buscarPorId(idAdotante);
        Pet p = repoPets.buscarPorId(idPet);

    int compat = MatchStrategy::calcularCompatibilidade(a, p);
        cout << "Compatibilidade entre " << a.getNome() << " e " << p.getNome()
         << ": " << compat << "%\n";
    return compat;
}

// Novo: relatório de pets disponíveis
    void SistemaAdocaoFacade::relatorioPetsDisponiveis() {
        cout << "\n--- Relatório de Pets Disponíveis ---\n";
        repoPets.listarPets();
}

// Novo: remover pet após adoção
    void SistemaAdocaoFacade::removerPet(int idPet) {
        auto& pets = repoPets.getPets();
        bool encontrado = false;

        for (size_t i = 0; i < pets.size(); i++) {
            if (pets[i].getId() == idPet) {
                pets.erase(pets.begin() + i); // remove pelo índice
                cout << "Pet com ID " << idPet << " foi adotado e removido do relatório.\n";
                encontrado = true;
                break;
        }
}

            if (!encontrado) {
                cout << "Pet com ID " << idPet << " não encontrado.\n";
    }
}

    void SistemaAdocaoFacade::realizarMatchAutomatico(int idAdotante) {
        Adotante a = repoAdotantes.buscarPorId(idAdotante);
        auto& pets = repoPets.getPets();

        if (pets.empty()) {
            cout << "Nenhum pet disponível para adoção.\n";
        return;
    }

        cout << "\n--- Resultados de Match para " << a.getNome() << " ---\n";

        for (auto& p : pets) {
            int compat = MatchStrategy::calcularCompatibilidade(a, p);
            cout << "Pet " << p.getNome() << " (ID " << p.getId() << ") -> Compatibilidade: " 
                 << compat << "%\n";
    }
}




