#ifndef __CRYPTOQUOTESCONTROLLER_HPP
#define __CRYPTOQUOTESCONTROLLER_HPP 1

#include "../model/CryptoQuotesModel.hpp"
#include "../view/CryptoQuotesView.hpp"

/**
 *  Author: Danny Huss
 *  Email: danny.huss@protonmail.com
 *  Created: 2020-07-09
 *  Description: Crypto-Quotes main control class
**/

class CryptoQuotesController {
    public:
        CryptoQuotesController(CryptoQuotesModel *model, CryptoQuotesView *view);
        int run(void);
    private:
        CryptoQuotesModel *model;
        CryptoQuotesView  *view;
};

#endif
