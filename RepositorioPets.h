#ifndef REPOSITORIOPETS_H
#define REPOSITORIOPETS_H
#include <vector>
#include "Pet.h"

        // Classe que funciona como repositório de Pets
// Cria o escopo para armazenar, organizar e acessar os dados dos pets
    class RepositorioPets {
        private:
            std::vector<Pet> pets;
            int ultimoId;

        public:
            RepositorioPets() : ultimoId(0) {}

            int proximoId() { return ++ultimoId; }
    void adicionar(const Pet& pet);
        Pet buscarPorId(int id);
    void listarPets();

    // Novo: acesso ao vetor interno
        std::vector<Pet>& getPets() { return pets; }
};

#endif
