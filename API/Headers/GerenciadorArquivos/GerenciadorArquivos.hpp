#ifndef _GERENCIADORARQUIVOS_
#define _GERENCIADORARQUIVOS_
#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include "../Produto/Produto.hpp"

class GerenciadorArquivos
{
public:
    void inserirProduto(const std::string &produto, float valorProduto, int quantidadeProduto);

    std::vector<std::tuple<std::string, float, int>> lerArquivo();

    int atualizarArquivo(std::unordered_map<std::string, Produto> estoque);
};

#endif 