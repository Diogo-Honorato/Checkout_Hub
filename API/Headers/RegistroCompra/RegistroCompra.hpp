#ifndef _REGISTRCOMPRA_
#define _REGISTRCOMPRA_
#include "../Estoque/Estoque.hpp"
#include "../Produto/Produto.hpp"

class RegistroCompra
{
private:
    float lucro;
    Estoque estoque;
    float valorTotalCompra;
public:
    RegistroCompra(Estoque estoqueProdutos);
    float setLucro(float valorLucro);
    float getLucro();
    float getValorTotalCompra();
    float encerrarExpediente();
    float comprarProduto();
};

#endif