#include "Tetris.h"
#include <iostream>

int main(){

    int larg = 17;
    Tetris game1(larg);

    game1.adicionaForma(0 ,0, 'I', 270);
    game1.removeLinhasCompletas();
    game1.removeColuna(16);

    game1.adicionaForma(0 , 1, 'I', 90);
    game1.adicionaForma(4 , 0, 'I', 90);
    game1.adicionaForma(8 , 0, 'I', 90);
    game1.adicionaForma(12 , 0, 'I', 90);

    game1.adicionaForma(4 , 1, 'I', 90);
    game1.adicionaForma(8 , 1, 'I', 90);
    game1.adicionaForma(12 , 1, 'I', 90);

    game1.adicionaForma(0 ,2, 'I', 90);
    game1.adicionaForma(4 ,2, 'I', 90);
    game1.adicionaForma(8 ,2, 'I', 90);
    game1.adicionaForma(12 ,2, 'I', 90);
    game1.adicionaForma(8 ,3, 'I', 90);
    game1.adicionaForma(0 ,4, 'I', 90);
    game1.adicionaForma(4 ,4, 'I', 90);
    game1.adicionaForma(8 ,4, 'I', 90);
    game1.adicionaForma(12 ,4, 'I', 90);

    game1.adicionaForma(10 , 5, 'I', 90);
    game1.adicionaForma(1 , 5, 'I', 90);
    game1.removeLinhasCompletas();
    game1.imprimeTetris();

    
/*
    game1.adicionaForma(5, 5, 'I', 90);
    game1.adicionaForma(10, 5, 'I', 180);
    game1.adicionaForma(15, 5, 'I', 270);
    
    game1.adicionaForma(0, 10,'J', 0);
    game1.adicionaForma(5, 10, 'J', 90);
    game1.adicionaForma(10, 10, 'J', 180);
    game1.adicionaForma(15, 10, 'J', 270);



    //std::cout << "Largura do vetor inicial\n";
    std::cout << game1.getAltura() << "\n";
    std::cout << game1.getAltura(1) << "\n";
    std::cout << game1.get(0,0) << "\n";
    std::cout << game1.getNumColunas() << "\n";

    std::cout << game1.get(1,2) << std::endl; //imprime espaco em branco
    std::cout << game1.get(0,0) << std::endl; //imprime T
    std::cout << game1.get(1,1) << std::endl; //imprime T
    std::cout << game1.get(4,1) << std::endl; //imprime O
    std::cout << game1.get(3,4) << std::endl; //imprime S
    
    game1.adicionaForma(0, 1, 'T', 180);
    game1.adicionaForma(0, 1, 'I', 90);
    game1.adicionaForma(1, 4,'S',0);
    game1.adicionaForma(3, 1,'O',0);
    
    game1.removeLinhasCompletas(); // remove linha
    game1.removeColuna(2);


    std::cout << game1.getAltura(1) << " " << game1.getAltura() << "\n";




*/


    // std::cout << "\nAdicione uma peca de tetris qualquer...\n";
    //char id1, id2, id3, id4;
    //std::cin >> id1 >> id2 >> id3 >> id4;
                     // c, l, id,   ang

    /*
    game1.adicionaForma(1, 5, 'J', 0);
    game1.adicionaForma(2, 3, 'J', 90);
    game1.adicionaForma(1, 1, 'J', 180); 
    game1.adicionaForma(0, 3, 'J', 270);
    
    game1.adicionaForma(5, 1, 'Z', 0);
    game1.adicionaForma(5, 4, 'Z', 90);
    game1.adicionaForma(6, 2, 'Z', 180);
    game1.adicionaForma(7, 5, 'Z', 270);

    game1.adicionaForma(8, 1, 'S', 0);
    game1.adicionaForma(9, 4, 'S', 90);
    game1.adicionaForma(10, 5, 'S', 180);
    game1.adicionaForma(11, 3, 'S', 270);

    game1.adicionaForma(13, 5, 'L', 0);
    game1.adicionaForma(12, 3, 'L', 90);
    game1.adicionaForma(14, 1, 'L', 180);
    game1.adicionaForma(14, 4, 'L', 270);

    game1.adicionaForma(18, 1, 'O', 0);
    game1.adicionaForma(20, 1, 'O', 90);
    game1.adicionaForma(18, 3, 'O', 180);
    game1.adicionaForma(20, 3, 'O', 270);

    game1.adicionaForma(22, 3, 'I', 0);
    game1.adicionaForma(18, 4, 'I', 90);
    game1.adicionaForma(23, 3, 'I', 180);
    game1.adicionaForma(18, 5, 'I', 270);

    game1.adicionaForma(1, 4, 'T', 0);
    game1.adicionaForma(15, 4, 'T', 90);
    game1.adicionaForma(10, 1, 'T', 180);
    game1.adicionaForma(24, 4, 'T', 270);
    
    game1.adicionaForma(5, 1, 'Z', 0);
    game1.adicionaForma(4, 4, 'Z', 90);
    game1.adicionaForma(4, 3, 'Z', 180);
    game1.adicionaForma(4, 3, 'Z', 270);

    */
    //game1.removeColuna(2);
    //std::cout << "peca: " << game1.get(0, 0) << std::endl;
    //game1.removeLinhasCompletas();

    return 0;
}