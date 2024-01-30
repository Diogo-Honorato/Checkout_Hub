#ifndef _ESTOQUE_
#define _ESTOQUE_
#include <string>
#include <unordered_map>
#include "../Produto/Produto.hpp"
#include "../GerenciadorArquivos/GerenciadorArquivos.hpp"

class Estoque
{
private:
    uint quantidadeTotalProdutos;
    std::unordered_map<std::string, Produto> estoque;
    GerenciadorArquivos arquivos;

public:
    void adicionarProduto(const std::string &nome, float valor, int quantidade);
    bool inciarEstoque();
    bool removerProduto(const std::string &nome);
    void listarProdutos();
    int incrementarQuantidadeProduto(const std::string &nomeProduto, int valorQuantidade);
    int decrementarQuantidadeProduto(const std::string &nomeProduto, int valorQuantidade);
    Produto consultarEstoque(const std::string &nome);
    Estoque();
    ~Estoque();
    
};

#endif