#include "CryptoQuotesView.hpp"


#define TERMINAL_SCREEN 1

#define ASCII_ENCODING 1
/**
 *  Author: Danny Huss
 *  Email: danny.huss@protonmail.com
 *  Created: 2020-07-09
 *  Description: Crypto-Quotes main view handler
**/

CryptoQuotesView::CryptoQuotesView(CryptoQuotesModel *model) {
    this->model = model;    
}

int CryptoQuotesView::InitializeScreen(int screen_style, int text_encoding) {

    switch (screen_style) {
        case 1:
            this->screen = new NCursesScreen(text_encoding);

            if (this->screen) 
                return true;
                
            break;
            
        default:
            break;
    };
    
    return false;
}
