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
    Adotante buscarAdotantePorId(int id);
};

#endif
