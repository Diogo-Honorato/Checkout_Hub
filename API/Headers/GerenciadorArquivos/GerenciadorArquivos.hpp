#ifndef _GERENCIADORARQUIVOS_
#define _GERENCIADORARQUIVOS_
#include <vector>
#include <tuple>
#include <string>
#include "../Estoque/Estoque.hpp"

class GerenciadorArquivos
{
public:
    void inserirProduto(const std::string &produto, float valorProduto, int quantidadeProduto);

    std::vector<std::tuple<std::string, float, int>> lerArquivo();
};

#endif 