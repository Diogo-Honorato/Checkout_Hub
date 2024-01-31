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
    std::vector<std::tuple<std::string, float, int>> lerArquivo();

    int atualizarArquivo(std::unordered_map<std::string, Produto> estoque);

    int gerarRecibo(std::vector<Produto> produtoLista, float totalValorCompra);

    int gerarListaProdutos(std::vector<std::string> chavesEstoque ,std::unordered_map<std::string, Produto> estoque, int totalProdutos);
};

#endif 