/**
 *  Author: Danny Huss
 *  Email: danny.huss@protonmail.com
 *  Created: 2020-07-09
 *  Description: Crypto-Quotes main application file
**/

#include "model/CryptoQuotesModel.hpp"
#include "view/CryptoQuotesView.hpp"
#include "controller/CryptoQuotesController.hpp"

int main(void) {

    CryptoQuotesModel       *model      = new CryptoQuotesModel();
    CryptoQuotesView        *view       = new CryptoQuotesView(model);
    CryptoQuotesController  *controller = new CryptoQuotesController(model, view);
    
    return controller->run();
}
