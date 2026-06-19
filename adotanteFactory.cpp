#include "adotanteFactory.h"

    Adotante AdotanteFactory::criarAdotante(int id) {
    // cria adotante com valores padrão
        Adotante novoAdotante(id, "", false, false, "", "", false, false);
        novoAdotante.cadastrarAdotante(); // coleta os dados do usuário
    return novoAdotante;
}