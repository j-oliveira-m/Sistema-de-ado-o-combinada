#ifndef SISTEMAADOTACOFACADE_H
#define SISTEMAADOTACOFACADE_H

#include "RepositorioPets.h"
#include "RepositorioAdotantes.h"

    class SistemaAdocaoFacade {
        private:
            RepositorioPets repoPets;
            RepositorioAdotantes repoAdotantes;

        public:
            SistemaAdocaoFacade();

            // Métodos para Pets
    void cadastrarPet();
    void listarPets();
        Pet buscarPetPorId(int id);

    // Métodos para Adotantes
    void cadastrarAdotante();
    void listarAdotantes();
    void editarAdotante(int id);
    Adotante buscarAdotantePorId(int id);

    // Match e relatório
        int realizarMatch(int idAdotante, int idPet);
        
    void realizarMatchAutomatico(int idAdotante);
    void relatorioPetsDisponiveis();
    void removerPet(int idPet);

};

#endif
