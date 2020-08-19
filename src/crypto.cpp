/**
 *  Author: Danny Huss
 *  Email: danny.huss@protonmail.com
 *  Created: 2020-07-09
 *  Description: Crypto-Quotes main application file
**/

#include "model/CryptoQuotesModel.hpp"
#include "view/CryptoQuotesView.hpp"
#include "controller/CryptoQuotesController.hpp"
#include <iostream>

int main(void) {

    try {
        try {
            CryptoQuotesModel       *model      = new CryptoQuotesModel();
            CryptoQuotesView        *view       = new CryptoQuotesView(model);
            CryptoQuotesController  *controller = new CryptoQuotesController(model, view);

    return controller->run();
            } catch(const std::exception &e) {
            std::cerr << "Unhandled exception: " << e.what();  // todo: localize string
            return 1;
        }
    } catch(...) { 
        return 1;   // catch any exception that isn't derived from std::exception
    } 
    
    return 0;
}
