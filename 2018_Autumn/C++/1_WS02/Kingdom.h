/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 2018/09/17
// Author Semin Jeon
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name         Date        Reason
// Semin Jeon   2018/09/17
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

// TODO: sict namespace
namespace sict{
// TODO: define the structure Kingdom in the sict namespace
  struct Kingdom {
    char m_name[32];
    int m_population;
  };
// TODO: declare the function display(...),
//         also in the sict namespace
  void display(const Kingdom&);
  //why don't I need to put struct in front of the Kingdom?
  void display(const Kingdom[], int num);
}
#endif