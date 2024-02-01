#ifndef _REGISTRCOMPRA_
#define _REGISTRCOMPRA_
#include <vector>
#include "../Estoque/Estoque.hpp"
#include "../Produto/Produto.hpp"
#include "../GerenciadorArquivos/GerenciadorArquivos.hpp"

class RegistroCompra
{
private:
    float lucro;
    
    float valorTotalCompra;

    GerenciadorArquivos arquivos;
    
public:
    RegistroCompra();
    float setLucro(float valorLucro);
    float getLucro();
    float getValorTotalCompra();
    float encerrarExpediente();
    std::vector<float> formaPagamentoDinheiro(float valorPagamento);
    std::vector<float> processarPagamento(float valorPagamento);
    float comprarProduto(Estoque &estoque);
};

#endif