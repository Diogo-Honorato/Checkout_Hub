#ifndef _GERENCIADORARQUIVOS_
#define _GERENCIADORARQUIVOS_
#include "../Estoque/Estoque.hpp"

class GerenciadorArquivos
{
private:
    Estoque estoque;

public:
    Estoque getEstoque();
    void inserirProduto(const std::string &produto, float valorProduto, int quantidadeProduto);

};

#endif 