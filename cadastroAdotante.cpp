//ULTIMA VERCAO :)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <mutex>
#include <memory>     // PONTERIOS INTELIGENTES -----> (unique_ptr, shared_ptr) para gerenciar memória automaticamente
#include <cctype>     // ANALISE DE CARACTERES INDIVIDUAIS
#include <map>        // Estrutura associativa chave → valor, útil para buscas rápidas por chave (nickname --> Usuario)

//USUARIO
class Usuario { //ENUM ----> converte M,F,A em valor (define os valores possíveis para o sexo) 
public:
    enum class SexoAnimal { MACHO, FEMEA, AMBOS };

    Usuario(std::string nome,
            std::string nickname,
            std::string senha,
            std::string caracteristicas,
            SexoAnimal sexo)
        : nome_(std::move(nome)),
          nickname_(std::move(nickname)),
          senha_(std::move(senha)),
          caracteristicas_(std::move(caracteristicas)),
          sexo_(sexo) {}

    const std::string& nome() const { return nome_; }
    const std::string& nickname() const { return nickname_; }
    const std::string& senha() const { return senha_; }
    const std::string& caracteristicas() const { return caracteristicas_; }
    SexoAnimal sexo() const { return sexo_; }

    static std::string sexoToString(SexoAnimal s) {
        switch (s) {
            case SexoAnimal::MACHO: return "macho";
            case SexoAnimal::FEMEA: return "femea";
            case SexoAnimal::AMBOS: return "ambos";
        }
        return "desconhecido";
    }

private:
    std::string nome_;
    std::string nickname_;
    std::string senha_;
    std::string caracteristicas_;
    SexoAnimal sexo_;
};
//REMOVE ACENTOS SIMPLES  ----> vaogais e suas variacoes
static std::string normalize(const std::string& in) {
    static const std::map<char,char> accents = {
        {(char)0xC0,'A'}, {(char)0xC1,'A'}, {(char)0xC2,'A'}, {(char)0xC3,'A'}, {(char)0xC4,'A'},
        {(char)0xE0,'a'}, {(char)0xE1,'a'}, {(char)0xE2,'a'}, {(char)0xE3,'a'}, {(char)0xE4,'a'}, // à á â ã ä
        {(char)0xC8,'E'}, {(char)0xC9,'E'}, {(char)0xCA,'E'}, {(char)0xCB,'E'},
        {(char)0xE8,'e'}, {(char)0xE9,'e'}, {(char)0xEA,'e'}, {(char)0xEB,'e'},
        {(char)0xCC,'I'}, {(char)0xCD,'I'}, {(char)0xCE,'I'}, {(char)0xCF,'I'},
        {(char)0xEC,'i'}, {(char)0xED,'i'}, {(char)0xEE,'i'}, {(char)0xEF,'i'},
        {(char)0xD2,'O'}, {(char)0xD3,'O'}, {(char)0xD4,'O'}, {(char)0xD5,'O'}, {(char)0xD6,'O'},
        {(char)0xF2,'o'}, {(char)0xF3,'o'}, {(char)0xF4,'o'}, {(char)0xF5,'o'}, {(char)0xF6,'o'},
        {(char)0xD9,'U'}, {(char)0xDA,'U'}, {(char)0xDB,'U'}, {(char)0xDC,'U'},
        {(char)0xF9,'u'}, {(char)0xFA,'u'}, {(char)0xFB,'u'}, {(char)0xFC,'u'},
        {(char)0xC7,'C'}, {(char)0xE7,'c'}
    };
    std::string out;
    out.reserve(in.size());
    for (unsigned char ch : in) {
        auto it = accents.find((char)ch);
        if (it != accents.end()) {
            out.push_back(std::tolower((unsigned char)it->second));
        } else {
            out.push_back(std::tolower(ch));
        }
    }
    return out;
}

//VALIDADORES
class IValidator {
public:
    virtual ~IValidator() = default;
    virtual bool validar(const std::string& valor, std::string& motivo) const = 0;
};

//NOME (sem números)
class NomeValidator : public IValidator {
public:
    bool validar(const std::string& valor, std::string& motivo) const override {
        if (valor.empty()) { motivo = "Nome vazio."; return false; }
        for (unsigned char c : valor) {
            if (std::isdigit(c)) { motivo = "Nome nao pode conter numeros."; return false; }
        }
        return true;
    }
};

//SENHA (+6 letras, 1 maiúscula, 1 número, 1 especial)
class SenhaValidator : public IValidator {
public:
    bool validar(const std::string& valor, std::string& motivo) const override {
        if (valor.size() < 6) { motivo = "Senha deve ter ao menos 6 caracteres."; return false; }

        int letras = 0;
        bool temMaiuscula = false;
        bool temNumero = false;
        bool temEspecial = false;
        for (unsigned char c : valor) {
            if (std::isalpha(c)) {
                letras++;
                if (std::isupper(c)) temMaiuscula = true;
            } else if (std::isdigit(c)) {
                temNumero = true;
            } else {
                temEspecial = true;
            }
        }
        if (letras < 6) { motivo = "Senha deve conter ao menos 6 letras."; return false; }
        if (!temMaiuscula) { motivo = "Senha deve conter ao menos 1 letra maiuscula."; return false; }
        if (!temNumero) { motivo = "Senha deve conter ao menos 1 numero."; return false; }
        if (!temEspecial) { motivo = "Senha deve conter ao menos 1 caractere especial."; return false; }
        return true;
    }
};

//CARACTERISTICAS
class CaracteristicasValidator : public IValidator {
public:
    bool validar(const std::string& valor, std::string& motivo) const override {
        if (valor.empty()) { motivo = "Preenchimento obrigatorio."; return false; }
        if (valor.size() > 80) { motivo = "Deve conter no maximo 80 caracteres."; return false; }
        return true;
    }
};

//SEXO (m, f ou a)
class SexoValidator : public IValidator {
public:
    bool validar(const std::string& valor, std::string& motivo) const override {
        std::string s = normalize(valor);
        if (s == "macho" || s == "femea" || s == "ambos") return true;
        motivo = "Sexo deve ser 'macho', 'femea' ou 'ambos'.";
        return false;
    }
};


class UsuarioFactory { //------------> centraliza criacao do usuario
public:
    static std::unique_ptr<Usuario> criarUsuario(const std::string& nome,
                                                 const std::string& nickname,
                                                 const std::string& senha,
                                                 const std::string& caracteristicas,
                                                 const std::string& sexoStr,
                                                 std::string& motivoErro) {
        std::string s = normalize(sexoStr);
        Usuario::SexoAnimal sexo;
        if (s == "macho") sexo = Usuario::SexoAnimal::MACHO;
        else if (s == "femea") sexo = Usuario::SexoAnimal::FEMEA;
        else if (s == "ambos") sexo = Usuario::SexoAnimal::AMBOS;
        else { motivoErro = "Sexo invalido."; return nullptr; }

        return std::make_unique<Usuario>(nome, nickname, senha, caracteristicas, sexo);
    }
};

//LISTAGEM E SALVAMENTO (singleton) 
class CadastroDB {
public:
    static CadastroDB& getInstance() {
        static CadastroDB instance;
        return instance;
    }

    int salvarUsuario(std::unique_ptr<Usuario> usuario) {
        std::lock_guard<std::mutex> lock(mutex_);
        int id = nextId_++;
        usuarios_.push_back(std::move(usuario));
        return id;
    }

    void listarUsuarios() const {
        std::cout << "=== Usuarios cadastrados ===\n";
        int idx = 1;
        for (const auto& u : usuarios_) {
            std::cout << idx++ << ". Nome: " << u->nome()
                      << " | Nick: " << u->nickname()
                      << " | Sexo animal: " << Usuario::sexoToString(u->sexo())
                      << " | Caracteristicas: " << u->caracteristicas() << "\n";
        }
        if (usuarios_.empty()) std::cout << "Ainda nao ha usuarios listados\n";
    }

private:
    CadastroDB() = default;
    CadastroDB(const CadastroDB&) = delete;
    CadastroDB& operator=(const CadastroDB&) = delete;

    std::vector<std::unique_ptr<Usuario>> usuarios_;
    int nextId_ = 1;
    mutable std::mutex mutex_;
};

// CADASTRO -------> cuida de todo o processo de validação e cadastro 
class CadastroFacade { //--------> simplificador dos cadastro
public:
    CadastroFacade() { //---------> negaçao de validador individual com factory
        validators_.push_back(std::make_unique<NomeValidator>());
        validators_.push_back(std::make_unique<SenhaValidator>());
        validators_.push_back(std::make_unique<CaracteristicasValidator>());
        validators_.push_back(std::make_unique<SexoValidator>());
    }

    bool cadastrar(const std::string& nome,
                   const std::string& nickname,
                   const std::string& senha,
                   const std::string& caracteristicas,
                   const std::string& sexoStr,
                   std::string& motivoErro) {
        
//VALIDAR ------> Execução e Validação de regras
        {
            std::string m;
            if (!validators_[0]->validar(nome, m)) { motivoErro = "Nome invalido: " + m; return false; }
        }
        {
            std::string m;
            if (!validators_[1]->validar(senha, m)) { motivoErro = "Senha invalida: " + m; return false; }
        }
        {
            std::string m;
            if (!validators_[2]->validar(caracteristicas, m)) { motivoErro = "Caracteristicas invalidas: " + m; return false; }
        }
        {
            std::string m;
            if (!validators_[3]->validar(sexoStr, m)) { motivoErro = "Sexo invalido: " + m; return false; }
        }
        
        auto usuario = UsuarioFactory::criarUsuario(nome, nickname, senha, caracteristicas, sexoStr, motivoErro);
        if (!usuario) {
            if (motivoErro.empty()) motivoErro = "Erro ao criar usuario.";
            return false;
        }

        CadastroDB::getInstance().salvarUsuario(std::move(usuario));
        return true;
    }

private:
    std::vector<std::unique_ptr<IValidator>> validators_;
};

//PURAMENTE ESTETICO -----> Remove espaços extras no início e no fim
static std::string readLineTrimmed() {
    std::string s;
    std::getline(std::cin, s);
    auto l = s.find_first_not_of(" \t\r\n");
    if (l == std::string::npos) return "";
    auto r = s.find_last_not_of(" \t\r\n");
    return s.substr(l, r - l + 1);
}

//MENU ---------> Saida
int main() {
    CadastroFacade facade;

    while (true) {
        std::cout << "\n=== Sistema de Cadastro de Usuarios (Adocao) ===\n";
        std::cout << "1 - Cadastrar usuario\n";
        std::cout << "2 - Listar usuarios\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";
        std::string opt;
        std::getline(std::cin, opt);
        if (opt == "0") break;
        if (opt == "1") {
            std::cout << "Nome: ";
            std::string nome = readLineTrimmed();
            std::cout << "Nickname: ";
            std::string nick = readLineTrimmed();
            std::cout << "Senha: ";
            std::string senha = readLineTrimmed();
            std::cout << "Caracteristicas desejadas: ";
            std::string carac = readLineTrimmed();
            std::cout << "Sexo do animal (macho / femea / ambos): ";
            std::string sexo = readLineTrimmed();

            std::string motivo;
            bool ok = facade.cadastrar(nome, nick, senha, carac, sexo, motivo);
            if (ok) std::cout << "Cadastro realizado com sucesso!\n";
            else std::cout << "Falha no cadastro --> " << motivo << "\n";
        } else if (opt == "2") {
            CadastroDB::getInstance().listarUsuarios();
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }

    std::cout << "Encerrando.\n";
    return 0;
}