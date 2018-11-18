// Name: Semin Jeon
// Date: 2018/11/08
// Error class manages the error state of client code and encapsulates the last error message

#ifndef ERROR_H
#define ERROR_H

namespace aid {
  class Error {
    char* m_error;
    void setter(const char* error_src);
    void safeEmpty();
  public:
    explicit Error(const char* error_src = nullptr);
    Error(const Error& em) = delete;
    Error& operator=(const Error& em) = delete;
    virtual ~Error();
    void clear();
    bool isClear() const;
    void message(const char* str);
    const char* message() const; 
  };
  std::ostream& operator<<(std::ostream& os, const Error& rhs);
}

#endif // !ERROR_H
