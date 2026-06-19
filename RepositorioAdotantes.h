#ifndef REPOSITORIOADOTANTES_H
#define REPOSITORIOADOTANTES_H
#include <vector>
#include "Adotante.h"

    class RepositorioAdotantes {
        private:
            std::vector<Adotante> adotantes;
            int ultimoId;

        public:
            RepositorioAdotantes() : ultimoId(0) {}

            int proximoId() { return ++ultimoId; }
    void adicionar(const Adotante& adotante);
        Adotante buscarPorId(int id);
    void listarAdotantes();


};

#endif