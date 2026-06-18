#include "MatchStrategy.h"
#include <iostream>
using namespace std;

    int MatchStrategy::calcularCompatibilidade(const Adotante& adotante, const Pet& pet) {
        int score = 0;
        int total = 0;

            // Preferência de porte
        total++;
        if (adotante.getPreferenciaPorte() == pet.getPorte()) score++;

        // Estilo de vida
            total++;
        if (adotante.getEstiloVida() == pet.getEstiloPet()) score++;

            // Patio
            total++;
        if (adotante.getTemPatio() == pet.getGostaDePatio()) score++;

            // Ambiente fechado
            total++;
        if (!adotante.getTemPatio() && pet.getAdaptaAmbienteFechado()) score++;

            // Sociabilidade com animais
            total++;
        if (pet.getSociavelComAnimais()) score++;

            // Sociabilidade com crianças
            total++;
        if (pet.getSociavelComCriancas()) score++;

            // Tempo livre
            total++;
        if (adotante.getTemTempoLivre() || !pet.getCarenteAtencao()) score++;

            // Atenção extra
            total++;
        if (adotante.getDispostoAtencao() || !pet.getCarenteAtencao()) score++;

            // Calcula porcentagem
            int compatibilidade = (score * 100) / total;
    return compatibilidade;
}
