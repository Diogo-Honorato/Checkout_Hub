#include <iostream>
#include <string>
#include "../../Headers/Estoque/Estoque.hpp"
#include "../../Headers/GerenciadorArquivos/GerenciadorArquivos.hpp"
#include "../../Headers/RegistroCompra/RegistroCompra.hpp"

int main()
{
    Estoque estoque;

    RegistroCompra comprar;

    comprar.comprarProduto(estoque);

}