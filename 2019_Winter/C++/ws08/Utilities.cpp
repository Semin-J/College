// Semin Jeon (146453162)
// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
    for (size_t i = 0; i < desc.size(); ++i) {
      for (size_t k = 0; k < price.size(); ++k) {
        if (desc[i].code == price[k].code) {
          Product* tmp = new Product(desc[i].desc, price[k].price);
          tmp->validate();
          priceList += tmp;
          delete tmp; // deallocate tmp
          tmp = nullptr;
        }
      }
    }
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
    for (size_t i = 0; i < desc.size(); ++i) {
      for (size_t k = 0; k < price.size(); ++k) {
        if (desc[i].code == price[k].code) {
          std::unique_ptr<Product> tmp(new Product(desc[i].desc, price[k].price));
          tmp->validate();
          priceList += tmp;
        }
      }
    }





		return priceList;
	}
}