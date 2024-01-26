#include <iostream>
#include <string>
#include "../../Headers/Estoque/Estoque.hpp"
#include "../../Headers/RegistroCompra/RegistroCompra.hpp"

int main(){

    Estoque estoque;

    float totalCompra;

    estoque.adicionarProduto("Banana",65.00f,5);
    estoque.adicionarProduto("Leite",15.00f,16);
    estoque.adicionarProduto("Arroz",25.00f,510);

    RegistroCompra comprar = RegistroCompra(estoque);

    totalCompra = comprar.comprarProduto();

    std::cout <<"Valor da Compra: "<< totalCompra << std::endl;

}