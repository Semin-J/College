// Name: Semin Jeon
// Date: 2018/11/18
// Good class is a concrete class that encapsulated the general information for an aid Good


#include <iomanip>
#include <cstring>
#include "Error.h"
#include "Good.h"

using namespace std;

namespace aid {
  void Good::safeEmpty() {
    m_sku[0] = '\0';
    m_unit[0] = '\0';
    m_name = nullptr;
    m_qty = 0;
    m_qtyNeeded = 0;
    m_price = 0.0;
    m_isTaxed = true;
    m_errorState.clear();
    call_empty++; //Need to check safeEmpty wouldn't be called more than once?
  }
  void Good::name(const char * name_src) {
    int size = strlen(name_src);
    if (name_src == nullptr) {
      delete[] m_name;
      m_name = nullptr;
    }
    else {
      if (size < max_name_length) {
        m_name = new char[size + 1];
        strncpy(m_name, name_src, size);
        m_name[size] = '\0';
      }
      else {
        m_name = new char[max_name_length + 1];
        strncpy(m_name, name_src, max_name_length);
        m_name[max_name_length] = '\0';
      }
    } 
  }

  const char * Good::name() const {
    return m_name;
  }

  const char * Good::sku() const {
    return m_sku;
  }

  const char * Good::unit() const {
    return m_unit;
  }

  bool Good::taxed() const {
    return m_isTaxed;
  }

  double Good::itemPrice() const {
    return m_price;
  }

  double Good::itemCost() const {
    return m_isTaxed == true ? m_price * (1 + TAX) : m_price;
  }

  void Good::message(const char* message_src) {
    m_errorState.message(message_src);
  }

  bool Good::isClear() const {
    return m_errorState.isClear();
  }

  Good::Good(char type_src) { //= 'N' (default)
    m_type = type_src;
    safeEmpty();
  }

  Good::Good(const char* sku_src, const char* name_src, const char* unit_src, int qty_src, bool isTaxed_src, double price_src, int qtyNeeded_src) {
    strcpy(m_sku, sku_src);
    name(name_src);
    strcpy(m_unit, unit_src);
    m_qty = qty_src;
    m_isTaxed = isTaxed_src;
    m_price = price_src;
    m_qtyNeeded = qtyNeeded_src;
  }

  Good::Good(const Good & good_src) {
    strcpy(m_sku, good_src.m_sku);
    name(good_src.m_name);
    strcpy(m_unit, good_src.m_unit);
    m_qty = good_src.m_qty;
    m_isTaxed = good_src.m_isTaxed;
    m_price = good_src.m_price;
    m_qtyNeeded = good_src.m_qtyNeeded;
  }

  Good::~Good() {
    delete[] m_name;
    m_name = nullptr;
  }

  Good& Good::operator=(const Good& good_src) {
    strcpy(m_sku, good_src.m_sku);
    delete[] this->m_name;
    this->m_name = nullptr;
    name(good_src.m_name);
    strcpy(m_unit, good_src.m_unit);
    m_qty = good_src.m_qty;
    m_isTaxed = good_src.m_isTaxed;
    m_price = good_src.m_price;
    m_qtyNeeded = good_src.m_qtyNeeded;

    return *this;
  }

  bool Good::operator==(const char * sku_src) {
    bool same;
    if (strcmp(m_sku, sku_src) == 0) same = true;
    else same = false;
    return same;
  }

  bool Good::operator>(const char * sku_src) {
  return (m_sku > sku_src)? true : false;
  }

  bool Good::operator>(const Good & good_src) {
    return (m_name > good_src.m_name)? true : false;
  }

  int Good::operator+=(int add_qty) {
    return (add_qty > 0)? (m_qty + add_qty) : m_qty;
  }

  std::fstream & Good::store(std::fstream & file, bool newLine) const {
    if (!this->isEmpty()) {
      file.open(filename, ios::out | ios::app);
      file << this->sku() << "," << this->name() << "," << this->unit() << "," <<
        (this->taxed() ? 1 : 0) << "," << fixed << setprecision(2) << this->itemPrice() << "," << this->quantity() << "," <<
        this->qtyNeeded();
      if (newLine)
        file << "\n";
      file.clear();
      file.close();
    }
    return file;
  }

  std::fstream & Good::load(std::fstream & file) {
    char sku[max_sku_length + 1];
    char name[max_name_length + 1];
    char unit[max_unit_length + 1];
    int qty;
    bool tax;
    char price;
    int qtyN;
    file.open(filename, ios::in);
    file >> sku >> name >> unit >> qty >> tax >> price >> qtyN;
    file.clear();
    file.close();
    *this = Good(sku, name, unit, qty, tax, price, qtyN);
    return file;
  }

  std::ostream & Good::write(std::ostream & os, bool linear) const {
    if(!isEmpty()) {
      if (linear == true) {
        os.width(max_sku_length);
        os << left << m_sku << "|";
        os.width(20);
        os << left << m_name << "|";
        os.width(7);
        os << fixed << setprecision(2);
        os << right << itemCost() << "|";
        os.width(4);
        os << right << m_qty << "|";
        os.width(10);
        os << left << m_unit << "|";
        os.width(4);
        os << right <<m_qtyNeeded << "|";
      }
      else {
        os << "Sku: " << m_sku << endl
          << "Name (no spaces): " << m_name << endl
          << "Price: " << m_price << endl;
        if (m_isTaxed == true) os << "Price after tax: " << itemCost() << endl;
        else os << "N/A" << endl;
        os << "Quantity on hand: " << m_qty << endl
          << "Quantity needed: " << m_qtyNeeded << endl;
      }
    }
    return os;
  }

  std::istream & Good::read(std::istream & is) {
    char sku[max_sku_length + 1];
    char name[max_name_length + 1];
    char unit[max_unit_length + 1];
    
    std::cout << " Sku: "; 
    is >> sku;
    cin.get();
    std::cout << " Name (no spaces): ";
    is >> name;
    cin.get();
    std::cout << " Unit: ";
    is >> unit;
    cin.get();
    Good tmp(sku, name, unit);

    char tax;
    std::cout << " Taxed? (y/n): ";
    is >> tax;
    cin.get();
    if (tax == 'y' || tax == 'Y' || tax == 'n' || tax == 'N') {
      if (tax == 'y' || tax == 'Y') tmp.m_isTaxed = true;
      else if (tax == 'n' || tax == 'N') tmp.m_isTaxed = false;
      double price = -1.23;
      std::cout << " Price: ";
      is >> price;
      cin.get();
      if (price > 0) {
        tmp.m_price = price;
        int qty = -1;
        std::cout << " Quantity on hand: ";
        is >> qty;
        cin.get();
        if (qty > 0) {
          tmp.m_qty = qty;
          int qtyN = -1;
          std::cout << " Quantity needed: ";
          is >> qtyN;
          cin.get();
          if (qtyN > 0) {
            tmp.m_qtyNeeded = qtyN;
            *this = tmp;
          }
          else {
            this->m_errorState.message("Invalid Quantity Needed Entry");
          }
        }
        else {
          this->m_errorState.message("Invalid Quantity Entry");
        }
      }
      else {
        is.fail();
        this->m_errorState.message("Invalid Price Entry");
      }
    }
    else {
      is.setstate(ios::failbit);
      this->m_errorState.message("Only (Y)es or (N)o are acceptable");
    }

    return is;
  }

  double Good::total_cost() const { 
    return itemCost() * m_qty;
  }

  void Good::quantity(int qty_src) {
    if (qty_src > 0) m_qty = qty_src;
  }

  bool Good::isEmpty() const { //check after call empty;
    return call_empty > 0? true : false;
  }

  int Good::qtyNeeded() const {
    return m_qtyNeeded;
  }

  int Good::quantity() const {
    return m_qty;
  }

  std::ostream & operator<<(std::ostream& os, const Good & good_src) {
    good_src.write(os, true); //should it be true?
    return os;
  }

  std::istream & operator>>(std::istream& is, Good & good_src) {
    good_src.read(is);
    return is;
  }

  double operator+=(double & add_price, const Good & good_src) {
    add_price += good_src.total_cost();
    return add_price;
  }
}