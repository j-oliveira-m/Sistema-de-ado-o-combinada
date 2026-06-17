#ifndef REPOSITORIOPETS_H
#define REPOSITORIOPETS_H
#include <vector>
#include "Pet.h"

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
    };

#endif