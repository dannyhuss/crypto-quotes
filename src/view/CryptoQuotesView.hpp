#ifndef __CRYPTOQUOTESVIEW_HPP
#define __CRYPTOQUOTESVIEW_HPP 1

#include "../model/CryptoQuotesModel.hpp"

/**
 *  Author: Danny Huss
 *  Email: danny.huss@protonmail.com
 *  Created: 2020-07-09
 *  Description: Crypto-Quotes main view handler
**/

class CryptoQuotesView {
    public:
        CryptoQuotesView(CryptoQuotesModel *model);
    private:
        CryptoQuotesModel *model;
};

#endif
