#ifndef ADOTANTE_H
#define ADOTANTE_H
#include <string>
#include<iostream>

    using namespace std;

    class Adotante {
        private:
            int id;
            string nome;
            string endereco;
            bool temPatio;
            string preferenciaPorte; // pequeno, médio, grande
            string estiloVida;   // saideiro ou caseiro
            bool temTempoLivre;         // tempo disponivel
            bool dispostoAtencao;   // pode dar atenção a pets carentes

        public:

            Adotante();
            Adotante(int id, string nome, string endereco, bool temPatio, string preferenciaPorte,
                    string estiloVida, bool temTempoLivre, bool dispostoAtencao);

        void cadastrarAdotante();
        void exibirAdotante();

                int getId() const {return id; }
                string getNome() const {return nome; }
                string getEndereco() const {return endereco; }
                bool getTemPatio() const {return temPatio; }
                string getPreferenciaPorte() const {return preferenciaPorte; }
                string getEstiloVida() const {return estiloVida; }
                bool getTemTempoLivre() const {return temTempoLivre; }
                bool getDispostoAtencao() const {return dispostoAtencao; }

    };





#endif