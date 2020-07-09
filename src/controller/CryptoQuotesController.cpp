#include "CryptoQuotesController.hpp"

/**
 *  Author: Danny Huss
 *  Email: danny.huss@protonmail.com
 *  Created: 2020-07-09
 *  Description: Crypto-Quotes main control class
**/

CryptoQuotesController::CryptoQuotesController(CryptoQuotesModel *model, CryptoQuotesView *view) {
    this->model = model;
    this->view  = view;
}

int CryptoQuotesController::run(void) {
    return 0;
}
