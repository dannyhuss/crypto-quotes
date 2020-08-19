#ifndef __CRYPTOQUOTESVIEW_HPP
#define __CRYPTOQUOTESVIEW_HPP 1

#include "../model/CryptoQuotesModel.hpp"
#include "screen/NCursesScreen.hpp"
/**
 *  Author: Danny Huss
 *  Email: danny.huss@protonmail.com
 *  Created: 2020-07-09
 *  Description: Crypto-Quotes main view handler
**/

using namespace std;

class CryptoQuotesView {
    public:
        CryptoQuotesView(CryptoQuotesModel *model);
        int InitializeScreen(int screen_style, int text_encoding);
    private:
        CryptoQuotesModel *model;
        NCursesScreen *screen;
};

#endif
